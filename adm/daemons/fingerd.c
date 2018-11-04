// fingerd.c
// change for netplay@CCTX
#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>

int query_only_ip(object *);

//add by jackyboy for finger display!
int online_time(object);
int online_time_total(object);

void create() { seteuid( getuid() ); }

int online_time(object body)
{
	return time() - (int)body->query_temp("temp_time");
}
int online_time_total(object body)
{
	return body->query("mud_age");
	//body->query("time_aged")+time()-(int)body->query_temp("temp_time");
}
int sort_by_ip(object ob1, object ob2)
{
        string ip1, ip2;

        if (! wizardp(ob1) && wizardp(ob2))
                return -1;

        if (wizardp(ob1) && ! wizardp(ob2))
                return 1;

        if (interactive(ob1) && ! interactive(ob2))
                return -1;

        if (! interactive(ob1) && interactive(ob2))
                return 1;

        if (interactive(ob1) && interactive(ob2))
        {
                ip1 = query_ip_number(ob1);
                ip2 = query_ip_number(ob2);
                if (ip1 != ip2)
                        return strcmp(ip1, ip2);
        }

        return strcmp(getuid(ob1), getuid(ob2));
}
string age_string(int time)
{
	int month, day, hour, min, sec;

	sec = time % 60;
	time /= 60;
	min = time % 60;
	time /= 60;
	hour = time % 24;
	time /= 24;
	day = time % 30;
	month = time / 30;
	return (month?month + "m":"") + (day?day + "d":"") + 
	(hour?hour + "h":"") + min + "m";
}

string finger_all()
{
	object *ob;
	string msg;
	int i;

	ob = users();
	msg = "";
	if ( !wizardp(this_player()) )  // player finger
	{
		for(i=0; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i]) ) continue;
			msg = sprintf("%s%-14s%-14s%-14s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				(interactive(ob[i]) ? (query_idle(ob[i]) + "s") : HIR "������" NOR));
		}
        return "�� " + MUD_NAME + "\n" +
		"������������������������������������\n"
		+ "����          �ʺ�          ����\n" +
		"������������������������������������\n"
		+ msg +
		"������������������������������������\n";
	} else  	// wizard finger
	{
		string *counter;
		string ipname;
		int pcnt;
		int lcnt;

		pcnt = 0;
		lcnt = 0;
		counter = ({ });
                ob = sort_array(ob, (: sort_by_ip :));
		for(i=0; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i]) ) continue;
			ipname = query_ip_name(ob[i]);
			msg = sprintf("%s%-14s%-14s%-14s%s%-7s" NOR "%s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				age_string( (int)ob[i]->query("mud_age")), 
                                (interactive(ob[i]) ? ((query_idle(ob[i]) >= 120) ? HIG : NOR) : HIR),
				(interactive(ob[i]) ? (query_idle(ob[i]) + "s") : "����"), ipname);
			if( environment(ob[i]) )
			{
				pcnt++;
				if( interactive(ob[i]) &&
                                    member_array(ipname, counter) == -1 )
					counter += ({ ipname });
			} else
				lcnt++;
		}

		msg = "�� " + MUD_NAME + "\n" +
		      "������������������������������������������������"
		      "��������������������������\n" +
		      "����          �ʺ�          ����          ����   ����\n" +
		      "������������������������������������������������"
		      "��������������������������\n" +
		      msg +
		      sprintf("\n%d�������������%d����ͬ�ĵص㣬"
			      "%s��ҽ�����Ϸ�С�\n",
			      pcnt, sizeof(counter),
			      lcnt ? (string) lcnt + "��" : "Ŀǰû��") +
		      "������������������������������������������������"
		      "��������������������������\n";
		return msg;
	}
}
	
string finger_user(string name)
{
	object ob, body, me;
	string msg, mud;
	int public_flag;
//��������JackyBoy���±�д���Ż���
	if( sscanf(name, "%s@%s", name, mud)==2 ) {
		GFINGER_Q->send_finger_q(mud, name, this_player(1));
		return "��·ָ��͹��̿�����ҪһЩʱ�䣬���Ժ�\n";
	}
	me = this_player(1);
	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() ) 
		return "û�������ҡ�\n";
	if( objectp(body = find_player(name)) && geteuid(body)==name )
	{
		if(wizardp(me))
			public_flag=1;
		else
			public_flag =body->query("env/public")?1:0;
	}
	else 
	{
		body = LOGIN_D->make_body(ob);
		if( !body->restore() ) 
			return "û�������ҡ�\n";
		if(wizardp(me))
			public_flag=1;
		else
			public_flag =body->query("env/public")?1:0;
		destruct(body);
	}
	msg =  sprintf("\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"
		"�����ʼ���ַ��\t%s\n�ϴ����ߣ�\t%s\n\n",
		ob->query("id"),
		ob->query("name"),
		(wiz_level(me)>wiz_level("(immortal)"))?SECURITY_D->get_status(name):"(player)",
		public_flag?ob->query("email"):"��������",
		"("+(wizardp(me)?ob->query("last_from"):"δ֪")+") "+
		ctime(ob->query("last_on")));
	if(!ob->query("profile")||ob->query("profile")=="")
		msg+="û�����ҽ��ܡ�\n\n";
	else
		msg+=ob->query("profile")+"\n\n";
	if( objectp(body = find_player(name)) && geteuid(body)==name && 
		me->visible(body))
	{
		msg += sprintf("\n%sĿǰ����%s�����С�\n", body->name(1),
			wizardp(me)?query_ip_number(body):"δ֪");
		msg+="����ʱ���ܺͣ�"+CHINESE_D->chinese_period(online_time_total(body))+"\n";
		msg+="�˴�����ʱ�䣺"+CHINESE_D->chinese_period(online_time(body))+"\n";
	}
	destruct(ob);
	return msg;
}

varargs string remote_finger_user(string name, int chinese_flag)
{
	object ob, body;
	string msg;
	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() )
		return chinese_flag ? "û�������ҡ�\n" : "No such user.\n";
	if( chinese_flag ) msg =  sprintf(
		"\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"
		"�����ʼ���ַ��\t%s\n�ϴ����ߵ�ַ��\t%s( %s )\n\n",
		ob->query("id"),
		ob->query("name"),
		"(player)",
		ob->query("email"),
		"δ֪",
		ctime(ob->query("last_on")));
	else msg =  sprintf(
		"\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
		capitalize(ob->query("id")),
		"(player)",
		ob->query("email"),
		"Unknow",
		ctime(ob->query("last_on")));
	if(!ob->query("profile")||ob->query("profile")=="")
		msg+="û�����ҽ��ܡ�\n\n";
	else
		msg+=ob->query("profile")+"\n";
	if( body = find_player(name) ) {
		if( !this_player() || this_player()->visible(body) )
		{
			if(chinese_flag)
			{
				msg+="\n" + ob->query("name") + "Ŀǰ�������ߡ�\n";
				msg+="\n����ʱ���ܺͣ�"+
					CHINESE_D->chinese_period(online_time_total(body))+"\n";
				msg+="�˴�����ʱ�䣺"+CHINESE_D->chinese_period(online_time(body))+"\n";
			}
			else
				msg+="\n" + capitalize(name) + " is currently connected.\n";
		}
	}
	destruct(ob);
	return msg;
}

object acquire_login_ob(string id)
{
	object ob;

	if( ob = find_player(id) ) {
		// Check if the player is linkdead
		if( ob->query_temp("link_ob") )
			return ob->query_temp("link_ob");
	}
	ob = new(LOGIN_OB);
	ob->set("id", id);
	return ob->restore() ? ob : 0;
}

string get_killer()
{
	int i;
	string msg;
	object *ob = users();

	msg = "";
	for (i = 0; i < sizeof(ob); i++)
		if ((int)ob[i]->query_condition("killer"))
			msg += (ob[i]->short() + "\n");
	if (msg == "")
		return "�����ΰ����á�\n";
	else
		return "���ڱ������ڼ��������˷���\n\n" + msg;
}
//���º����ų�ͬһ��IP���ߵ�
//write by JackyBoy@CuteRabbits Studio for CCTX 1999/4/9
int query_only_ip(object *ob)
{	
	int i,j,k,count,total;

	total=sizeof(ob);
	for ( i=0; i<sizeof(ob); i++)
	{
		count=1;k=sizeof(ob);
		for (j=0; j<k;j++)
			if (j!=i&&query_ip_name(ob[i])==query_ip_name(ob[j]) )
			{
				ob=ob-({ob[j]});
				count++;
				k=sizeof(ob);
			}
		total=total-count+1;
	}
	return total;
}

int ip_name(object ob1, object ob2)
{
        string name1, name2;
        
        name1 = query_ip_name(ob1);
        name2 = query_ip_name(ob2);

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}


