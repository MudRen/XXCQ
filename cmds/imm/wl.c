// look.c
// 1998.9.4  by netkill

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string do_query(object obj);

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
	{
	str = sprintf(  HIC + "%s" + NOR + " - %s\n    %s%s",
		env->query("short"),
		wizardp(me)? file_name(env): "",
		env->query("long"),
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
	}
		
	if( mapp(exits = env->query("exits")) ) 
	{
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });

		if( sizeof(dirs)==0 )
			if ( n ) str += "    ����һƬ��ڣ��������·��\n";
			else
			str += "    ����û���κ����Եĳ�·��\n";
		else if( sizeof(dirs)==1 )
			if ( n )
				 if ( ! random(5) ) str += "    ����һƬ��ڣ��������·��\n";
				else str += "   ����ĳ��ں�����"  HIY + dirs[0] + NOR "��\n";
			else
			str += "    ����Ψһ�ĳ����� " HIY  + dirs[0]  + NOR  "��\n";
		else   if ( n ) 
				if ( ! random(5) ) str += "    ����һƬ��ڣ��������·��\n";
			      else str += sprintf ("   ����ĳ��ں�����" HIY +  "%s"   + NOR " �� "   HIY  + "%s"  + NOR "��\n",
				implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
			else
			str += sprintf("    �������Եĳ����� " HIY + "%s"   + NOR  " �� " HIY + "%s"  + NOR "��\n",
				implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
	}


//	str += env->door_description();

	inv = all_inventory(env);

	{
	
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
		if( !me->visible(inv[i]) ) continue;
		str += "  " + inv[i]->short() + "\n";}
	}
	
	

	write(str);
	return 1;
}

int look_item(object me, object obj)
{
	mixed *inv;

	me->start_more(obj->long());
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object() );
		message("vision", sprintf("�����У�\n  %s\n",
			implode(inv, "\n  ") ), me);
	}
	return 1;
}

int look_living(object me, object obj)
{
	string str, limb_status, pro,pp;
	mixed *inv;
	mapping my_fam, fam;
	int me_shen, obj_shen,phlye;
	phlye= (int)obj->query("phlye");	
	me_shen = (int)me->query("shen");
	obj_shen = (int)obj->query("shen");

	if( me!=obj )
		message("vision", me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);

	str = obj->long();

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

	message("vision", str, me);

// Modified by Hop
/*
	if( obj!=me 
	&&	living(obj)
	&&	random((int)obj->query("shen")) < 0 - (int)me->query("int") * 10 ) {
		write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
	}
*/
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
		return 0;

	return str;
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
		str ="�ֳ�һ" + units + str;
	return str;	
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");
	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write(item[arg]);
		else if( functionp(item[arg]) )
			write((string)(*item[arg])(me));
			
		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = find_object(exits[arg])) )
			look_room(me, env);
		else {
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]));
		}
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int help (object me)
{
	write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
	return 1;
}
