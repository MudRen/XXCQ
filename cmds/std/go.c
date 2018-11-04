// go.c
#include <ansi.h>
inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":		"��",
	"south":		"��",
	"east":			"��",
	"west":			"��",
	"northup":		"����",
	"southup":		"�ϱ�",
	"eastup":		"����",
	"westup":		"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":		"����",
	"westdown":		"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
	"up":			"��",
	"down":			"��",
	"enter":		"��",
	"out":			"��",
]);


mapping reverse_dir=([
	"north":		"����",
	"south":		"����",
	"east":		"����",
	"west":		"����",
	"northup":		"�ϱ�",
	"southup":		"����",
	"eastup":		"����",
	"westup":		"����",
	"northdown":	"�ϱ�",
	"southdown":	"����",
	"eastdown":		"����",
	"westdown":		"����",
	"northeast":	"���Ϸ���",
	"northwest":	"���Ϸ���",
	"southeast":	"��������",
	"southwest":	"��������",
	"up":			"����",
	"down":		"����",
	"enter":		"����",
	"out":		"����",
]);


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, mout, min, dir,dir1,str,str1,face,thing_msg;
	object env, obj,che,thing;
	mapping exit;
	object *f_obs, *ob;
	int count = 0, my_dex, i,n,i_env,i_obj;

	if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

	if( me->over_encumbranced() )
		return notify_fail("��ĸ��ɹ��أ��������á�\n");
	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
	if (me->is_fighting()) {
		f_obs = me->query_enemy();
		if (objectp(f_obs[0]))
		if (5 + random((int)me->query("dex")) <= random((int)f_obs[0]->query("dex")))
		{
			me->start_busy(1);
//added by King
			message_vision("$N���Ʋ��ã�ת��Ҫ�ߣ���$nһ��������ǰ�����ߣ�û��ô���ף�\n", me, f_obs[0]);
//end of appendence
			return notify_fail("������ʧ�ܡ�\n");
		}
	}

	env = environment(me);
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("�������û�г�·��\n");
		else
			return 0;
	}

	dest = exit[arg];
	if( !objectp(obj = find_object(dest)) )
		obj=load_object(dest);
	if( !objectp(obj) )
		return notify_fail("�޷��ƶ���\n");

// Added by Hop
	ob = all_inventory(obj);
	for(i=0; i<sizeof(ob); i++)
		if( living(ob[i]) && ob[i] != me )
			count++;
	my_dex = (int)me->query_dex();
	if(((my_dex < 15) && (count > 8))
	|| ((my_dex < 20) && (count > 10))
	|| ((my_dex < 30) && (count > 12))
	|| ((my_dex < 40) && (count > 14)))
		return notify_fail("ǰ����̫���ˣ�����ô��Ҳ������ȥ��\n");
// End of appendence	
 
	if( !env->valid_leave(me, arg) ) return 0;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;
	if( !undefinedp(reverse_dir[arg]) )
		dir1="��"+reverse_dir[arg];
	else dir1="��֪��������";

//�����ǹ��ڰ���ͺ�ҹ��ʾ������

	n=NATURE_D->night();
	i_env=(int)env->query("outdoors");
	i_obj=(int)obj->query("outdoors");
	
	if (!n) i=1;
	if (!i_env && !i_obj) i=1;
	if (n && i_env && !i_obj) i=2;
	if (n && ! i_env && i_obj) i=3;
	if (n && i_env && i_obj ) i =4;
	if( me->is_fighting() ) 
	{
		str="����ײײ�����˹�����ģ����Щ�Ǳ���\n";
	 	str1="��" + dir + "��Ķ����ˡ�\n";
	}
	else
	{
		str=dir1+"���˹�����\n";str1="��" + dir + "�뿪��\n";
	}

	switch( i)
	{	case 1 : 
		mout = me->name() ;
		min = me->name() ;
		break;
		case 2 :
		if(me->query("gender") == "Ů��")
		{
		mout = "һ��ٻӰ" ;
		min =  me->name() ;
		}
		else
		{
		mout = "һ����Ӱ" ;
		min  = me->name() ;
		}
		break;	
		case 3 :
		if(me->query("gender") == "Ů��")
		{
		mout = me->name() ;
		min =  "һ��ٻӰ" ;
		}
		else
		{
		mout = me->name() ;
		min  = "һ����Ӱ" ;
		}
		break;
		case 4 :
			if(me->query("gender") == "Ů��")
		{
		mout = "һ��ٻӰ" ;
		min =  "һ��ٻӰ" ;
		}
		else
		{
		mout = "һ����Ӱ" ;
		min  = "һ����Ӱ" ;
		}
	}
	if(!mout)
		mout=me->name();
	if(!min)
		min=me->name();
	face="";
	if (me->query("gender")=="Ů��")
	{
		if (me->query("per") >= 30) face ="���޾���" ;
		if ((me->query("per") >= 28) && (me->query("per") < 30)) face= "��������" ;
		if ((me->query("per") >= 26) && (me->query("per") < 28)) face= "��������" ;
		if ((me->query("per") >= 24) && (me->query("per") < 26)) face= "��ɫ����" ;
		if ((me->query("per") >= 21) && (me->query("per") < 24)) face= "��Ŀ毺�" ;
		if (me->query("str") <= 16) face = "ͤͤ����" ;
		if ((me->query("str") <= 20) && (me->query("str") > 16)) face= "��̬��ӯ";
		if ((me->query("per")<21) && (me->query("str")>20) || !userp(me)) face = "";
	}
	else
	{
		if (me->query("per") >= 30) face= "�����ٷ��" ;
		if ((me->query("per") >= 26) && (me->query("per") < 30)) face="Ӣ������" ;
		if ((me->query("per") >= 22) && (me->query("per") < 26)) face="�Ǳ�����" ;
		if (me->query("str") >=23) face = "���׳˶" ;
		if ((me->query("str") >= 20) && (me->query("str") < 23)) face= "�����Բ";
		if ((me->query("per")<22) && (me->query("str")<20) || !userp(me)) face = "";
	}
	if(face&&face!="")
		face+="��";
	if (objectp(thing = me->query_temp("armor/cloth")))
		thing_msg = "����" + thing->query("name");
	else
		thing_msg = "ȫ�������";
	if (objectp(thing = me->query_temp("weapon")))
		thing_msg += "��ִ" + thing->query("name");
	if ( me->query("race") == "Ұ��")
	{
		mout = me->name() + "������" + dir + "һ�ܾ���ʧ�ˡ�\n";
		min = me->name() + "���ش��˳�������������������š�\n";
	}
	else
	{
		if ( me->query_temp("xueheche") && (che=present("xuehe che",environment(me))))
		{
			mout = mout+"����Ѫ�ӳ���" + dir + "���۶�ȥ��\n";
			min = face + min + thing_msg + "����Ѫ�ӳ���¡¡�Ŀ��˹�����\n";
			che->move(obj);
		}
		else
		{
			mout = mout + "��" + dir + "�뿪��\n";
			min = face + min + thing_msg + "���˹�����\n";
		}
	}

	message( "vision", mout, environment(me), ({me}) );
	//view_message(mout,environment(me),me);
	if( me->move(obj) )
	{
		me->remove_all_enemy();
		message( "vision", min, environment(me), ({me}) );
		if (me->query_temp("xueheche") && (present("xuehe che",obj))) 
		{
			message_vision(HIR"ɲ�Ǽ䣬���������һ�ֺ���Ѫ�⡣�������ʱ������һ��ŨŨ��ɱ����\n"NOR,me);
		}
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		if (!me->is_ghost())
			me->add("jingli", -1);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "�������һ���������...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help()
{
	write(@HELP
ָ���ʽ : go <����>
 
������ָ���ķ����ƶ���
 
HELP
    );
    return 1;
}
