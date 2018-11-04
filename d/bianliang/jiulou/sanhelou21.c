// Room: /city/sanhelou2.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
����������¥����������������Ŵ��ɫ�ĵ�̺��һ�������ϻ���
һ���̽�ɫ�Ĵ��ϲ�֡���������������ٰ���ϯ�������Ҳ�������
�Ͳ�������һ�º��ϰ塣
LONG);
	set("no_fight",1);
	set("objects", ([
		__DIR__"hu" : 1,
	]));
	set("exits", ([
		"out" : __DIR__"sanhelou2",
	]));

	setup();
}

void init()
{
	add_action("do_work", "quit");
	add_action("do_work", "du");
	add_action("do_work", "dazuo");
	add_action("do_work", "tuna");
	add_action("do_work", "zhoutian");
        add_action("do_stand", "stand");
}

int do_work()
{
	if( present("table", environment(this_player())) )
	{
                write(WHT"�������������������ò�㣡\n"NOR);
		return 1;
	}
}

int do_stand(string arg)
{       object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="up"&&(me->query_temp("marks/��"))){
		me->delete_temp("marks/��");
		me->delete_temp("marks/����");
	message_vision("$N�����Ķ�Ƥ�����˸����ã�վ����׼�������ˡ�\n", this_player());
        return 1;
	}
	else return notify_fail("�㱾����վ�ŵġ�\n");
}

int valid_leave(object me, string dir)
{
	if( dir=="out"
	&& this_player()->query_temp("marks/��") )
	return notify_fail(WHT"��Ҫ���뿪���ӡ�(ָ���ʽ��stand up)\n"NOR);

	if( dir=="out"
     && this_player()->query_temp("marks/��ʼ") )
	return notify_fail(WHT"��Ҫ�Ƚ����������뿪��(ָ���ʽ��jieshu)\n"NOR);

        return ::valid_leave(me, dir);
}
