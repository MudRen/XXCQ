// look.c
// Modify By JackyBoy 1999/6/8

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object,object);
int look_item(object,object);
int look_living(object,object);
int look_room_item(object,string);
string do_query(object);
string inventory_look(object,int);
string room_desc(object);
	
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me));
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	} else result = look_room_item(me, arg);

	return result;
}

int look_room(object me, object env)
{
	int i,n;
	object *inv;
	mapping exits;
	string str, *dirs;

	if( !env ) {
		write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
		return 1;
	}
	if ( n=NATURE_D->night() && (int) env->query("outdoors")
		&&!(wizardp(me)&&me->query("env/debug")) )
		//���������������debug����ʦ�Ļ��Ͷ��ܿ���
	{	
		str = sprintf(  HIR"��"NOR + "%s" + HIR"��"NOR +"- %s\n"+"%s%s",
		env->query("short"),
		wizardp(me)? file_name(env): "",
		"�������ڹ��߲��㣬ʲô�������塣\n",
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
		
		}
	else{
	str = sprintf(  HIR"��"NOR + "%s" + HIR"��"NOR + " - %s\n%s%s",
		env->query("short"),
		wizardp(me)? file_name(env): "",
		room_desc(env),//���η�������
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
	}
	str+=BBLK;
	if( mapp(exits = env->query("exits")) ) 
	{
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });

       if(sizeof(dirs)==0)
			if ( n&&!(wizardp(me)&&me->query("env/debug")) ) 
				str += "    ����һƬ��ڣ��������·��\n";
			else
				str += "    ����û���κ����Եĳ�·��\n";
		else 
			if( sizeof(dirs)==1 )
				if ( n&&!(wizardp(me)&&me->query("env/debug")) )
					if ( ! random(5) ) 
						str += "    ����һƬ��ڣ��������·��\n";
					else 
						str += "   ����ĳ��ں�����"  HIY + dirs[0] + NOR "��\n";
				else
					str += "    ����Ψһ�ĳ����� " HIY  + dirs[0]  + NOR  "��\n";
			else   
				if ( n&&!(wizardp(me)&&me->query("env/debug")) ) 
					if ( ! random(5) ) 
						str += "    ����һƬ��ڣ��������·��\n";
			      	else 
			      		str += sprintf ("   ����ĳ��ں�����" HIY +  "%s"   + NOR " �� "   HIY  + "%s"  + NOR "��\n",
							implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
				else
					str += sprintf("    �������Եĳ����� " HIY + "%s"   + NOR  " �� " HIY + "%s"  + NOR "��\n",
						implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
	}

	inv = all_inventory(env);
     if ( n && (int)env->query("outdoors") &&!wizardp(me)&&!me->query("env/debug"))
	{
		for(i=0; i<sizeof(inv); i++) 
		{
			if( inv[i]==me ) continue;
			if( !me->visible(inv[i]) ) continue;
			if (inv[i]->is_character() )
				str += "һ�����ʵ���Ӱ�����������˭��\n";
			else 
				str += "һ��ģģ�����Ķ�����\n";
		}
	}
	else
	{
		for(i=0; i<sizeof(inv); i++) 
		{
			if( inv[i]==me ) continue;
			if( !me->visible(inv[i]) ) continue;
			str += "  " + inv[i]->short() + "\n";
		}
	}
	write(BBLK+str+BBLK);
	return 1;
}

int look_item(object me, object obj)
{
	mixed *inv;
	int i;
	string str;
	str="\n";
	me->start_more(obj->long());
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		//inv = map_array(inv, "inventory_look", this_object() );
		//����ƺ��д���ע�ͣ�������ĳ���ȡ��Jackyboy
		for(i=0;i<sizeof(inv);i++)
			str+=(string)inv[i]->name(1)+"\n";
		message("vision", sprintf(BBLK+"�����У�\n  %s\n"+BBLK,str), me);
	}
	return 1;
}

int look_living(object me, object obj)
{
    string str, pro,pp,banghui;
	mixed *inv;
	mapping my_fam, fam;
    int me_shen, obj_shen,phlye,bhrank;
	phlye= (int)obj->query("phlye");	
	me_shen = (int)me->query("shen");
	obj_shen = (int)obj->query("shen");
        banghui = obj->query("banghui");
        bhrank = obj->query("bhrank");

	if( me!=obj )
		message("vision", me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);

	str = BBLK+obj->long();

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

	if( (string)obj->query("race")=="����"
	&&	intp(obj->query("age"))  )
	{	if (phlye)
		{
			switch (phlye){
			case 1 :  pp=sprintf("��������"); break;
			case 2 :  pp=sprintf("��ԭ����"); break;
			case 3 :  pp=sprintf("��������"); break;
			case 4 :  pp=sprintf("��������"); break;
			case 5 :  pp=sprintf("��������"); break;
			case 6 :  pp=sprintf("�ɶ�����"); break;
			}
		str += sprintf("%s������������%s��\n",pro, pp);
		} 
		str += sprintf("%s������Լ%s���ꡣ\n", pro, chinese_number(obj->query("age") / 10 * 10));
	}
// ���Ӱ��ĺ������ã����Կ�����Ҽ����ĸ���� adx
                        if (banghui)
                        str += pro + BANGHUI_D->query_banghui( banghui , bhrank );
	// If we both has family, check if we have any relations.
	if( obj!=me
	&&	mapp(fam = obj->query("family"))
	&&	mapp(my_fam = me->query("family")) 
	&&	fam["family_name"] == my_fam["family_name"] ) {
	
		if( fam["generation"]==my_fam["generation"] ) {
			if( (string)obj->query("gender") == "����" ||
				(string)obj->query("gender") == "����")
				str += sprintf( pro + "�����%s%s��\n",
					my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
					my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
			else
				str += sprintf( pro + "�����%s%s��\n",
					my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
					my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( my_fam["master_id"] == obj->query("id") )
				str += pro + "�����ʦ����\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "�����ͬ�ų�����\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "�����ʦ����\n";
			else
				str += pro + "�����ʦ�塣\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "�����ͬ������\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "����ĵ��ӡ�\n";
			else
				str += pro + "�����ʦֶ��\n";
		}
	}

	if( obj->query("max_qi") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";

	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
			str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "ֻ��%s��\n%s\n",
				pro, implode(inv, "\n") );
	}

	message("vision", BBLK+str+BBLK, me);

	if( obj!=me && living(obj)
	&& (((me_shen < 0) && (obj_shen > 0)) || ((me_shen > 0) && (obj_shen < 0)))
	&& (((me_shen - obj_shen) > ((int)obj->query("neili") * 20))
	|| ((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
	{
		write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
		if(obj->query("age") > 15 && me->query("age") > 15)
			COMBAT_D->auto_fight(obj, me, "berserk");
	}

	return 1;
}

string inventory_look(object obj, int flag)
{
	string str;
	if( obj->query("equipped") )
		str = "  "+ do_query(obj);
	else if( !flag )
		str = "    " + str;
	else
		return obj->query("short");

	return BBLK+str+BBLK;
}

string do_query(object obj)
{
	string str,units;

	units =obj->query("unit");
	str = obj->short();
	if (obj->query("armor_type"))
	switch( obj->query("armor_type") ) {
		case "cloth":
		case "armor":
			str = "��һ"+ units + str;
			break;
		case "boots":
			str = "���ϴ���һ" + units + str;
			break;
		case "head":
		case "neck":
		case "wrists":
		case "finger":
		case "hands":
			str ="����һ"+ units + str;
			break;
		case "waist":
			str = "��������һ"+units+str;
			break;
		default:
			str = "װ����"+str; 
			}
	else
	if( obj->wield() )
		if (obj->query("skill_type")=="throwing")
		str ="���ϴ���"+str;
		else
		str ="�ֳ�һ" + units + str;
	return BBLK+str+BBLK;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");
	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) 
	{
		if( stringp(item[arg]) )
			write(item[arg]);
		else if( functionp(item[arg]) )
			write((string)(*item[arg])(me));
		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) 
	{
		if( objectp(env = find_object(exits[arg])) )
			look_room(me, env);
		else 
		{
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]));
		}
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}
string nocolor(string str2)
{
	//Ϊ��ͳһ��ʽ�����԰�����ansi��ɫ�����ַ�ɾ�������������㳤�ȣ�
	str2 = replace_string(str2, BLK,"");
	str2 = replace_string(str2, RED,"");
	str2 = replace_string(str2, GRN,"");
	str2 = replace_string(str2, YEL,"");
	str2 = replace_string(str2, BLU,"");
	str2 = replace_string(str2, MAG,"");
	str2 = replace_string(str2, CYN,"");
	str2 = replace_string(str2, WHT,"");
	str2 = replace_string(str2, HIR,"");
	str2 = replace_string(str2, HIG,"");
	str2 = replace_string(str2, HIY,"");
	str2 = replace_string(str2, HIB,"");
	str2 = replace_string(str2, HIM,"");
	str2 = replace_string(str2, HIC,"");
	str2 = replace_string(str2, HIW,"");
	str2 = replace_string(str2, NOR,"");
	str2 = replace_string(str2, BLINK,"");
	return str2;
}
string room_desc(object ob)
{
	//���ڸ�ʽ���Ʋ���Ϥ��������һ�γ�����ʽ����
	string *line,result,tmp;
	int tag,i,j,tab;
	if(ob->query("no_desc")||ob->query("outdoors")||!this_player()->query("env/room_desc"))
		return "    "+ob->query("long");
	line=explode(ob->query("long"),"\n");
	if(!line)
		return "���������뱨����ʦ��\n";
	result="������������������������������������������������������������������������\n";
	tag=0;
	foreach(tmp in line)
	{
		if(!tag)
		{
			tmp="    "+tmp;
			tag=1;
		}
		//�������ַ�ֵΪ97���ַ����ڣ���ʾ��ʱ������ų�97����ַ�����Ȼ��ʾ������
		//ʹ�����ѭ���жϵ�һ��97���ֵ�λ��
		//�����ɫ��ռ�ݵ�λ��
		tmp=nocolor(tmp);
		tab=0;
		for(i=0;i<sizeof(tmp);i++)
		{
			if((int)tmp[i]==97)
				break;//i��¼�Ĳ�����ʾ�ĳ���
			if(tmp[i]=='\t')
				tab++;
		}
		//write ("����"+tab+"��Tab!"+i+"���ַ�!����"+(68-i-tab*7+2)+"���ո�\n");
		tab=tab*7-2;
		if(tab<0) tab=0;
		if(sizeof(tmp)>68-tab)//��������ַ���������ֱ�ӽ�ȡ�ķ�����
			tmp=tmp[0..64]+"....";
		for(j=68-i-tab;j>0;j--)
			tmp=tmp+" ";
		result=result+"��"+tmp+"��\n";
	}
	result=result+"������������������������������������������������������������������������\n";
	return result;
}
	
int help()
{
	write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
	return 1;
}
