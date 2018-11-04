// Room: /welcome/datiepu.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"������"NOR);
	set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬͨ�죬
��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ˵�����������
����ذ�ס����׵��һλ������ͷ�󺹻�����������ר����־���ڴ�����
LONG );
	set("exits", ([
		"west" : __DIR__"nanlang2",
	]));
        set("objects", ([
		__DIR__"npc/smith": 1,
	]));
	set("no_fight", 1);
//	set("no_clean_up", 0);
	setup();
}

void init()
{
           add_action("do_job","da");
}
int do_job(string arg)
{
        object *inv;
        object me;
         int i, jingli;

	me = this_player();
	jingli = ( random(me->query("str"))/3 );
	inv = all_inventory(me);
	if (jingli <= 0)
		jingli = 5;

	if (me->query("jingli")<=10) {
	message_vision ("��û�������ˣ���ȥ��Ϣ��˯һ�°ɣ�"+HIC"(sleep)\n"NOR, me );
        return 1;
	}
	   //�ж��Ƿ�wield�˹���
	if( (string)(inv[i]->query("id"))=="hammer" && 
		(int) inv[i]->query("equipped") ) 
	{
		if( !arg || arg!="��" )
			{return notify_fail ("��Ҫ��ʲô��\n");
		}
		else {
			me->add_temp("wancheng", jingli);
			me->add("jingli", -jingli);
			me->add("combat_exp", jingli);
			me->add("potential", (jingli/2));
			message_vision ("$N�������������������պ������\n", me );
			if (me->query_temp("wancheng") >= 100)
			{
				me->set_temp("renwu",100);   //��100��ʾ�������
				return notify_fail (WHT"����Ի�ȥ�����ˣ�(ask moto about ok)\n"NOR);
				}
			}
	}
	else {
		return notify_fail ("�������ô��������ȭͷ����\n");
		}
        return 1;
}

int valid_leave(object me, string dir)
{
         if ( (dir == "west") &&
		(me->query("wancheng") >= 100) )
	{
		if ( !present("hammer", me) ) {return 1;}
			message_vision ("$N�������е�������\n", me);
		destruct(present("hammer", me));
	}
	return ::valid_leave(me, dir);
}
