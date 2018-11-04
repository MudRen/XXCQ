// boat1.c
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"Сľ��"NOR);
	set("long",
"һֻ���ݵ��������˵�Сľ�ۣ����������ʱ���ûˤ��ȥ�������и�\n"
HIG"���"NOR"(bole)����Ҫ��Ҫ��һ��(use)��\n"
);
	set("exits", ([
	"out": __DIR__"muqiao",
]));
        set("no_clean_up", 0);
	set("item_desc", ([
	"bole":  HIG"һ������������ݣ������ֵ��˵࣬��ʵ�����ء�\n"NOR,         
	"hetian" : HIG"һƬ�����͵ĺ�Ҷ(heye)�����泤��������(lianpeng)��\n"NOR,
	"heye" : HIG"�������ĺ�Ҷ�����ž�Ө͸����ˮ���ں�Ҷ�Ϲ�����ȥ��\n"NOR,
	"lianpeng" : HIY"�Ĺĵ�������ʼ��ˡ�\n"NOR,
]));
        setup();
}


void init()
{
	add_action("do_use","use");                  
	add_action("do_save","save");
	add_action("do_quit","quit");	                        
	add_action("do_zhai", "zhai");
	add_action("do_zhai", "cai");
	add_action("do_bo", "bo");
}                                    

int do_save()
{
	write("���ﲻ׼���̣�\n");
	return 1;
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}


int do_use(string arg)
{
	object me, ob;
	me = this_player();
	ob = this_object();
	if(!arg||arg!="bole")
		return notify_fail("��Ҫ��ʲô?\n");
	message_vision(HIG"$N������ݾ���һ���ҳš�\n......\n......\n"NOR,me);
	message("vision", HIG"$Nһ�þ���һ�°�С�������ú�Զ��\n"NOR, environment(me), ({me}));
	write(HIR"�۵�����ͷ�󺹡�\n"NOR);
	me->receive_damage("jingli", 10);
	delete("exits/out");
	if(!ob->query("busy"))
	ob->set("busy", 1);
	switch(random(20))
	{
		case 0:
		case 1:
		case 2:
		case 3:                                                     
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		message_vision(HIR"~ ~ ~ �����ں����뵴ѽ��~ ~ ~\n"NOR, me);
		me->add_temp("hua", 1);
		break;
		case 11:
		case 12:
		case 13:
		message_vision("��Զ������һ��Ƭ�����͵�"HIG"����"NOR"(hetian)��\n", me);
		break;
		case 14:
		message_vision("�㻮�Ż��ţ������ֻص���ԭ�ء�\n", me);
		me->delete_temp("hua");
		set("exits/out", __DIR__"muqiao");
		break;		
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		message_vision(HIG"�㻮�˺þþ���֪���Լ������ˡ�\n"NOR,me);
		break;
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	 object qiao;
	 qiao = find_object(__DIR__"muqiao");
 	 if( dir == "out" )
	 {
        	this_object()->delete("busy");            
        	me->delete_temp("hua");
	 	if(!(qiao = find_object(__DIR__"muqiao")))
                     qiao = load_object(__DIR__"muqiao");
                {
         	qiao->set("long",
"����ͨ������Сͤ��ľ�ţ�������ȥ����̲���������ɫ���ˡ�ľ�ŵ�\n"
"�����ϵ����һ����Сľͷʨ�ӣ����˰������֡�ľ���������ܹ�����һ��\n"
"����Сͤ����ľ����˨��һ��Сľ������Ȼ�������˲��ڡ�\n");       
		}              
		return 1; 
	}
        return ::valid_leave(me,dir);
}

int do_zhai(string arg)
{
	object me, ob;
	me = this_player();

	if( !living(me)) return 0;
	if( me->is_busy()) return notify_fail("����æ���ء�\n");
	if( me->is_fighting()) return notify_fail("����æ���ء�\n");
	if( !arg || arg != "lianpeng" || arg == "") return notify_fail("��Ҫժʲô��\n");
	if( arg == "lianpeng")
	{       
		switch(random(5))
		{       
			case 0:
			case 1:
			tell_object(me, "��Ҷ��ס������������������ͷת��ġ�\n");
			break;
			case 2:
			tell_object(me, "�����ֹ���������Ǿ���̫���ˣ��㹻���š�\n");
			message("vision", "$N���ֹ���������Ǿ���̫���ˣ�$N�����š�\n", environment(me), ({me}));
			break;
			case 3:
			tell_object(me, "�����ֹ������һ��ץס��һ�������\n");
			message("vision", "$N���ֹ������һ��ץס��һ�������\n", environment(me), ({me}));
			break;
			case 4:
			tell_object(me, "ͻȻ����һ�Σ�Ϲ����һ������æ���ַ�ס���ߡ�\n");
			message("vision", "ͻȻ����һ�Σ�Ϲ��$Nһ������æ���ַ�ס���ߡ�\n", environment(me), ({me}));
			break;
		}
		return 1;
	}
}

int do_bo(string arg)
{
	object me, ob;
	me = this_player();
	ob = this_object();
	if( !living(me)) return 0;
	if( me->is_busy()) return notify_fail("����æ���ء�\n");
	if( me->is_fighting()) return notify_fail("����æ���ء�\n");
	if( !arg || arg != "heye" || arg == "") return notify_fail("��Ҫ��ʲô��\n");
	if( (int)me->query_temp("hua", 1) < 10 ) return 0;
	if( arg == "heye")
	{       
        	message_vision("$N���ֲ����˵�����ǰ�ĺ�Ҷ��\n", me);
        	tell_object(me, "ͻȻ��һ��С�������������ǰ���㲻�����ϵ�̽��������\n");
        	me->move(__DIR__"ab");
        	ob->delete("busy");
        	return 1;
        }
}