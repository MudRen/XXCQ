// write by JackyBoy@CuteRabbit Studio for CCTX II 1999/5/17
// ��Ҫ������һЩ���Ե��޸��Լ���ϵ����ʼ�ע���������޸ġ�

#define MAX_DUMMY 10
//�����һͬʱ��¼��ID��

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <runtime_config.h>
#include <mudlib.h>

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
int mad_lock = 0;
string *banned_name = ({
	"��", "��", "��", "��", "��",
	"ʱ��",
});
void logon_main(string ,object );
void get_id(string , object );
void confirm_id(string , object );
object make_body(object );
void init_new_player(object );
varargs void enter_world(object , object , int );
varargs void reconnect(object , object , int );
object find_body(string );
int check_legal_id(string );
int check_legal_name(string );

void random_gift(mapping my)
{
	int i;
	int tmpstr, tmpint, tmpcon, tmpdex, tmpbac;
	tmpstr = tmpint = tmpcon = tmpdex = tmpbac = 10;

	for (i = 0; i < 50; i++) {
		switch (random(5)) {
		case 0: tmpstr++; break;
		case 1: tmpint++; break;
		case 2: tmpcon++; break;
		case 3: tmpdex++; break;
		case 4: tmpbac++; break;
		}
	}
	if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
	if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
	if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
	if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;
	if (tmpbac <= 30) my["bac"] = tmpbac; else my["bac"] = 30;

	my["kar"] = 10 + random(21);
	my["per"] = 10 + random(21);
	my["apt"] = 20 + random(30);
}

void create() 
{
	seteuid(getuid());
	set("channel_id","���߾���");
}

void logon(object ob)
{
	write("\n\nWelcome to SnowMud! Select GB or BIG5 (gb/big5):");
	input_to( (: logon_main :),ob);
}

void logon_main(string arg,object ob)
{
	object *usr;
	int i, wiz_cnt, ppl_cnt, login_cnt,i_user,log_num=0;
	string user_num;   
	int encode;
	if(!arg || arg=="")
	{
		write("\nSelect ������ GB or �j���X BIG5 (gb/big5):");
		input_to( (: logon_main :), ob );
		return;
	}
	else
	if(arg[0..0]=="g" || arg[0..0]=="G")
		encode=0;
	else
	if(arg[0..0]=="b" || arg[0..0]=="B")
		encode=1;
	else 
	{
		write("\nSelect ������ GB or �j���X BIG5 (gb/big5):");
		input_to( (: logon_main :), ob );
		return;
	}
	if(encode==0)
		write("\nUse GB encoded Chinese.\n");
	else
		write("\nUse BIG5 encoded Chinese.\n");
	ob->set_encoding(encode);
	if( mad_lock == 1 ) 
	{
		write("����ʱ���Ѿ�����ˣ����ܽ��룡�� \n");
		destruct(ob);
		return;
	}
	if (BAN_D->is_banned(query_ip_name(ob)) == 1) 
	{
		write("��ĵ�ַ�ڱ� MUD ���ܻ�ӭ��\n");
		destruct(ob);
		return;
	}
	write(read_file(WELCOME)+BBLK+HIW);
	UPTIME_CMD->main();
	usr = users();
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	for(i=0; i<sizeof(usr); i++)
	{
		if( !environment(usr[i]) ) login_cnt++;
   		else 
		if( wizardp(usr[i]) )
		{
			if(usr[i]->query("env/invisibility")==0)
				wiz_cnt++;
		}
		else ppl_cnt++;
	}
	user_num=read_file(USERS,1);
	i_user=atoi(user_num);
	write(sprintf(BBLK+HIW"��һ�žž���ʮһ��ʮ������"+CHINESE_MUD_NAME+"����%s�˴����á�\n",chinese_number(i_user)));
	i_user=i_user+1; 
	user_num=sprintf("%d", i_user); 
	write_file(USERS,user_num,1);
	user_num=read_file(IDUSER,1);
	i_user=atoi(user_num);
	write(sprintf(CHINESE_MUD_NAME+"Ŀǰ����%s��ע����ҡ�\n",chinese_number(i_user))); 
	//����Ӧ��ͳ�Ʒ�վ����
	//����DNS_MASTERû���ܼ�ʱ��Ӧ������Ϸ���������������ʱ�����д���
	write(sprintf("Ŀǰ���� %d λ��ʦ��%d λ��������ϣ��Լ� %d λʹ���߳��������С�\n\n",
		wiz_cnt, ppl_cnt, login_cnt ));
	for(i=0;i<sizeof(usr);i++) 
	if (ob!=usr[i]) 
		if 
		(
			(
				//��������һЩ�ر�����Ŀ��Բ����Ƶ�վ��(�������й̶�IP��վ��)
				query_ip_number(ob)!="10.163.180.3"&&
				query_ip_number(ob)!="10.163.179.201"&&
				query_ip_number(ob)!="10.163.180.4"&&
				query_ip_number(ob)!="10.163.180.2"
			)
			&&
				query_ip_name(ob)==query_ip_name(usr[i])
		) 
			log_num++;
	if (log_num >= MAX_DUMMY )
	{  
		write(HIR+"��ֻ����ͬʱ��½"+MAX_DUMMY+"��IP�����˳������ʺ����ԡ�\n"+NOR); 
		destruct(ob); 
		return;                 
	}
	else
	{
		write(HIW+"�����ڵĵ�ַ("+HIR+query_ip_number(ob)+HIW")����"HIY+chinese_number(log_num)+HIW"λ��������ϡ�\n");
	}
	write("����Ӣ�����֣�");
	input_to( (: get_id :), ob );
}

void get_id(string arg, object ob)
{
	object ppl;
	object *usr;
	int i, wiz_cnt;
	arg = lower_case(arg);
	if( !check_legal_id(arg)) 
	{
		write("����Ӣ�����֣�");
		input_to("get_id", ob);
		return;
	}

	usr = users();
	wiz_cnt = 0;
	for(i=0; i<sizeof(usr); i++) 
	{
		if( wizardp(usr[i]) ) 
			wiz_cnt++;
	}
	if( (string)SECURITY_D->get_status(arg)=="(player)"
		&& (sizeof(users()) - wiz_cnt) >= 150) 
	{
		ppl = find_body(arg);

		if( !ppl || !interactive(ppl) ) 
		{
			write("�Բ���"+CHINESE_MUD_NAME+"��ʹ�����Ѿ�̫���ˣ������������\n");
			destruct(ob);
			return;
		}
	}

	if( wiz_level(arg) < wiz_lock_level ) 
	{
		write("�Բ���"+CHINESE_MUD_NAME+"Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL
			+ " ���ϵ��˲������ߡ�\n");
		destruct(ob);
		return;
	}
        
	if( (string)ob->set("id", arg) != arg ) 
	{
		write("�޷����������û�����\n");
		destruct(ob);
		return;
	}

	if( arg=="guest" ) 
	{
		// If guest, let them create the character.
		confirm_id("Yes", ob);
		return;
	} 
	else 
	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) 
	{
		if( ob->restore() ) 
		{
			write("��������Ѿ�����ע���ˣ����������룺");
			input_to("get_passwd", 1, ob);
			return;
		}
		write("�������ﴢ�浵����һЩ���⣬������guest(����:guest)����֪ͨ��ʦ����\n");
		destruct(ob);
		return;
	}
	write("ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
	ob->set("newbie",1);
	input_to("confirm_id", ob);
}

void get_passwd(string pass, object ob)
{
	string my_pass,temp_pass;
	object user;
	int time_rl;
	string temps;
	write("\n");
	my_pass = ob->query("password");
	temp_pass= ob->query("temp_password");
	//temp_password��������ҳ���ע��ʱʹ�õ���ʱ����
	if(my_pass&&my_pass==crypt(pass,my_pass))
	{
		//��ʱ˵��ע��ɹ�������ע������
		ob->set("registered",1);
	}
	else
	if(	crypt(pass, temp_pass) != temp_pass ) 
	{
		write("�������\n");
		destruct(ob);
		return;
	}
	else
	{
		//��Ϊ�������봦��
		//�������õ�¼��ע���ң�
		ob->set_temp("go_reg_room",1);
	}
	
	time_rl = time() - ob->query("last_on");
	// Check if logout recently
	if (time_rl >= 0 && time_rl <= 10)
	{
		temps = sprintf("����ϴ��˳��� %d tick.\n", time_rl);
		write(temps);
		if ((string)SECURITY_D->get_status(ob->query("id")) == "(player)")
		{
			write("�Բ���Ϊ�˽���ϵͳ���ɣ����Ժ���login����л���ĺ�����\n");
	                destruct(ob);
	                return;
		} 
		else
		{
			write("��Ȼ������ʦ��Ҳ��ҪƵ����loginŶ��\n");
		}
	}

	// Check if we are already playing.
	user = find_body(ob->query("id"));

	// by Find.
	if(user && !environment(user)) /* ����״̬�ǲ�Ӧ���ֵ� */
		destruct(user);

	if (user) 
	{
		if( user->query_temp("netdead") ) 
		{
			reconnect(ob, user);
			return;
		}
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

	if( objectp(user = make_body(ob)) ) 
	{
		if( user->restore() ) 
		{
			log_file( "USAGE", sprintf("%s loggined from %s (%s)\n", user->query("name"),
				query_ip_name(ob), ctime(time()) ) );
			enter_world(ob, user);
			return;
		} 
		else 
		{
			destruct(user);
		}
	}
	write("�������´���������\n");
	confirm_id("y", ob);
}

void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) 
	{
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}       
	if( yn[0]!='y' && yn[0]!='Y' ) 
	{
		write("�ðɣ���ӭ�´�������\n");
		destruct(ob);
		return;
	} 
	else
	{
		tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
			+ " )����ȡ���������Ƶ����\n");
		log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", user->query("name"),
			query_ip_name(ob), ctime(time()) ) );
	}
	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( objectp(old_link) )
	{
		exec(old_link, user);
		destruct(old_link);
	}
	reconnect(ob, user);    
}

void confirm_id(string yn, object ob)
{
	if( yn=="" )
	{
		write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
		input_to("confirm_id", ob);
		return;
	}       
	if( yn[0]!='y' && yn[0]!='Y' )
	{
		write("�ðɣ���ô��������������Ӣ�����֣�");
		input_to("get_id", ob);
		return;
	}
	write( @TEXT
���������ĸ��մ���������������ִ��������������Ժ��ܸ��ģ�
����������������Ź۵���������ɾ������
(��������֮�⣬�� mud �����ȡ�ºš���Ƶ���ƣ�����֣�ؽ�����
 ȡһ���Ƚ������ֵ��������֡�)
 ���벻Ҫѡ������С˵����������������
TEXT
	);
	write("�����������֣�");
	input_to("get_name", ob);
}

void get_name(string arg, object ob)
{
	if( !check_legal_name(arg) )
	{
		write("�����������֣�");
		input_to("get_name", ob);
		return;
	}
	printf("%O\n", ob);
	ob->set("name", arg);
	write("���趨������ʱ���룺");
	input_to("new_password", 1, ob);
}

void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 )
	{
		write("����ĳ�������Ҫ����ַ���������������ʱ���룺");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("temp_password",crypt(pass,0) );//���û�ע�ᣬ������ʱ����
	write("��������һ��������ʱ���룬��ȷ����û�Ǵ�");
	input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob)
{
	mapping my;
	string old_temp_pass;
	write("\n");
	old_temp_pass=ob->query("temp_password");
	if( crypt(pass, old_temp_pass)!=old_temp_pass)
	{
		write("��������������벢��һ�����������趨һ�����룺");
		input_to("new_password", 1, ob);
		return;
	}
	write(@TEXT
һ��������츳��������������ϰ������ϢϢ��ء�Сѩ�����е��������
�����������츳�����и�Ե����ò������Ϊ�����츳�������������
      +-----------------------------------------------------+
      | ������Ӱ�칥���������������Ĵ�С��                  |
      | ���ԣ�Ӱ��ѧϰ�书�ؼ����ٶȼ����ʦ����������      |
      | ���ǣ�Ӱ�������ָ����ٶȼ������������ӵ���Ϣ��������|
      | ����Ӱ�������ʡ���������ܵ�������                |
      | ������Ӱ��Ӱ��ɿص�ɱ�����Ͷ�־����ʧ�ͻָ��ٶȡ�  |
      +-----------------------------------------------------+
TEXT);
	my = ([]);
	random_gift(my);
	printf("\n����[%d]������[%d]������[%d]����[%d]������[%d]\n",
		my["str"], my["int"], my["con"], my["dex"], my["bac"]);
	write("��ͬ����һ���츳��");
	input_to("get_gift", ob, my);
}

void get_gift(string yn, object ob, mapping my)
{
	if (yn[0] != 'y' && yn[0] != 'Y') 
	{
		random_gift(my);
		printf("\n����[%d]������[%d]������[%d]����[%d]������[%d]\n",
			my["str"], my["int"], my["con"], my["dex"], my["bac"]);
		write("��ͬ����һ���츳��");
		input_to("get_gift", ob, my);
	}
	write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
	input_to("get_gender", ob, my);
}

void get_gender(string gender, object ob, mapping my)
{	
	object user;
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) )
		return;
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	user->set("bac", my["bac"]);
	write("\n");
	if( gender=="" )
	{
		write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
		input_to("get_gender", ob,my);
		return;
	}
	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "����");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Ů��" );
	else
	{
		write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
		input_to("get_gender", ob,my);
		return;
	}
	//ɾ�����ڵ�¼��־���ñ�־��/clone/user/login.c�����ã�
	//�漰��/feature/save.c
	log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
		query_ip_name(ob), ctime(time()) ) );
	init_new_player(user);
	enter_world(ob, user);
	write("\n");
}

object make_body(object ob)
{
	string err;
	object user;
	
	user = new(ob->query("body"));
	if(!user)
	{
		write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

void init_new_player(object user)
{
	user->set("title", "��ͨ����");
	user->set("birthday", time() );
	user->set("newbie",1);
//    user->set("potential", 99)
	user->set("potential", 99);
	user->set("channels", ({ "chat", "rumor", "es", "new" ,"snow","party"}) );

}

                
varargs void enter_world(object ob, object user, int silent)
{
	object cloth, mailbox;
	string startroom;
	object login_ob;
	//��login_ob�̳�GB&BIG5���뷽ʽ
	user->set_encoding(ob->query_encoding());
	ob->delete_temp("loging");
	//��������䣬����ob->query_temp("link_ob")����time_out�����㵼���޷�������ң�
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	user->set("registered",ob->query("registered"));
	exec(user, ob);
	write("\nĿǰȨ�ޣ�" + wizhood(user) + "\n");
	//����ϵͳ����Ī������ؽ�link_ob��0����������ﱸ��link_ob!
	if(objectp(ob))
		user->set_temp("link_ob1",ob);
	else
		write("link_ob����ȷ�����������߽�����Ϸ��\n");
	
	user->setup();
	if (!user->query("food") && !user->query("water") && ob->query("age") == 14)
	{
		user->set("food", user->max_food_capacity());
		user->set("water", user->max_water_capacity());
	}
	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();
	cloth = new("/clone/misc/cloth");
	cloth->move(user);
	cloth->wear();

// Give user a mailbox.
// Modified by Hop at 1997.04.10
	mailbox = new("/clone/misc/mailbox");
	mailbox->move(user);

// End of modification
	if( !silent )
	{
		write(read_file(MOTD));
		write("  \n"NOR);
		if( user->query("new_mail") )
		{
			tell_object(user, BLINK+HIY + "\n�������ţ��쿴�������ɣ�\n\n" + NOR);
			user->set("new_mail", 0);
		}
		if( !user->is_ghost()&&user->query("newbie")&&!ob->query("registered"))
		{
			//���������û��ע��������ȵ�ע�ᴦע�ᡣ
			write("Ӵ���������Ӵ������ע�����ĵ�������ɣ�\n");
			startroom = NEW_PLAYER_START;
		}
		else
		if( user->is_ghost() )
		{
			startroom = DEATH_ROOM;
		}
		else
		if( !stringp(startroom = user->query("startroom")))
		{
			write("ѽ����֪����Ӧ�ô�ʲô�ط���¼���ȵ�ע�ᴦ�ɣ�\n");
			startroom = NEW_PLAYER_START;
		}
		/*if(ob->query_temp("go_reg_room"))
		{
			//�����������ʱ��������ע���ң�
			write("�������˱��ÿ����ֱ�ӽ���ע���ң�\n");
			startroom = NEW_PLAYER_START;
			ob->delete_temp("go_reg_room");
		}*/
		//��ʦ�����ȵ���Ϣ�ұ���
		if ( wiz_level( user->query("id") ) > 1 )
		{
			user->move(WIZ_START_ROOM);
			CHANNEL_D->do_channel( user, "wiz*",
			sprintf("���߽���"+CHINESE_MUD_NAME+"��") );
		}
		else
		{
			//��Ϊ��Ҫȡ��ע�ᴦ��¼��������ʱ���Ӿ�
			if(stringp(user->query("startroom")))
				startroom=user->query("startroom");
			if( !catch(load_object(startroom)) )
				user->move(startroom);
			else
			{
				user->move(START_ROOM);
				startroom = START_ROOM;
				user->set("startroom", START_ROOM);
			}
			tell_room(startroom, user->query("name") + "���߽���������硣\n",({user}));
		}
	}
	login_ob=new(LOGIN_OB);
	login_ob->set("id",user->query("id"));
	login_ob->restore();
	write("���ϴ������Ǵ�" + HIR +login_ob->query("last_from") + NOR + " on " + 
		HIR +ctime(login_ob->query("last_on"))+ NOR + "\n");
	destruct(login_ob);
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s��%s���߽��롣["+CHINESE_D->chinese_time(6,ctime(time()))+"]", 
			user->name()+"("+user->query("id")+")", query_ip_name(user)) );
	if(!(wizardp(user)&&!user->query("env/logchat")))
		CHANNEL_D->do_channel( this_object(), "chat",
			sprintf("��ӭ%s���߽��뽭����["+CHINESE_D->chinese_time(6,ctime(time()))+"]", 
			user->name()+"("+user->query("id")+")"));
	UPDATE_D->check_user(user);
	if( user->query("lastChangeSize") != file_size("/doc/help/change") ) 
	{
		user->set("lastChangeSize", file_size("/doc/help/change"));
		write(BLINK HIW"\nСѩ�������¸��£������� help change �˽���ϸ�����\n\n"NOR);
	}
//����Ƿ�������а�add by jackyboy@cctx 1999/3/8
	TOPTEN_D->topten_checkplayer(user);
//��¼����ʱ��exp��time add by jackyboy@cctx 1999/3/8
	user->set_temp("temp_exp",user->query("combat_exp"));
	user->set_temp("temp_time",time());
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	//����һ�ݱ��ݣ�
	user->set_temp("link_ob1",ob);
	//�������link_ob����"loging"���temp����Ӧ��ɾ���Ŷԣ�
	//����ob�ͻ���time_out����0��
	ob->delete_temp("loging");
	ob->set_temp("body_ob", user);
	exec(user, ob);
	user->reconnect();
	if( !silent )
	{
		tell_room(environment(user), user->query("name") + "�������߻ص�������硣\n",
			({user}));
	}
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s��%s�������߽��롣", user->query("name")+"("+user->query("id")+
			")", query_ip_name(user)) );
	UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
	int i,j;
	string *bad_word=({"fuck","shit","sex","father","mother"});
	i = strlen(id);
	if( (strlen(id) < 3) || (strlen(id) > 10 ) )
	{
		write("�Բ������Ӣ�����ֱ����� 3 �� 10 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
	{
		if( id[i]<'a' || id[i]>'z' )
		{
			write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
			return 0;
		}
		//��ֹ����4����ĸ��ͬ
		if((i+3)<(sizeof(id)))
		{
			if(id[i]==id[i+1]&&id[i]==id[i+2]&&id[i]==id[i+3])
			{
				printf("�Բ�����Ϸ������ID������4����ĸ(%c)��ͬ��\n",id[i]);
				return 0;
			}
		}
	}
	for(j=0;j<sizeof(bad_word);j++)
		if(strsrch(id,bad_word[j])!=-1)
		{
			write("�Բ����벻Ҫ�ú���"HIY+BLINK+bad_word[j]+NOR"������ID��\n"+
				"�����ȷʵҪʹ�ø�ID��������ʦ��ϵ��\n");
			return 0;
		}
	return 1;
}

int check_legal_name(string name)
{
	int i,j;
	string *bad_word=({"��","��","��","��","ү","��","����","��","��",
        "��","��", "ɽè"});
	i = strlen(name);
	if( (strlen(name) < 2) || (strlen(name) > 8 ) )
	{
		write("�Բ�������������ֱ����� 1 �� 4 �������֡�\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) )
		{
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}
	for(j=0;j<sizeof(bad_word);j++)
		if(strsrch(name,bad_word[j])!=-1)
		{
			write("�Բ����벻Ҫ�ú���"HIY+BLINK+bad_word[j]+NOR"���������֣�\n"+
				"�����ȷʵҪʹ�ø����֣�����һ�����ֽ��������ʦ���޸ģ�\n");
			return 0;
		}
	if( member_array(name, banned_name)!=-1 )
	{
		write("�Բ����������ֻ���������˵����š�\n");
		return 0;
	}
	return 1;
}

object find_body(string name)
{
	object ob, *body;
	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
	if( clonep(body[i])&&getuid(body[i]) == name )
		return body[i];
	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}

int set_madlock(int setmark)
{
	if( wiz_level(this_player(1)) < wiz_level("(hufa)") )
		return 0;
	if( setmark == 1 )
		mad_lock = 1;
	else
		mad_lock = 0;
	return 1;
}

int get_madlock()
{
	return mad_lock;
}




