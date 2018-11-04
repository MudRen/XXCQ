//by andylau

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG
����Сѩ���������ֵ���������������������ʯ����read bei����ʯ����
���ŵĶ���һЩ�����ڽ�����߳汷��Ƶ���ʦ�������е�ȥ���ˣ��е���
�����ӣ��еĻ�������Ұ�ף������˼����ĵ�����������ǵ����ֻ���
Զ���������Զ������һ����һ���˵����С���Ӣ�ͷף������裬��
¶Ϧ�⣬������Ƣ�����Ǻ�ʱ�⡣ż�м���С��Ů���̤�࣬ݺ����Ӱ��
���ֶ��ˡ�
LONG );

    set("exits", ([
        "south" : __DIR__"jiaowai2",
        "west"  : __DIR__"course",
        "north" : "/d/bianliang/guangming",
        "east"  : __DIR__"bite",
    ]));

    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
    setup();
    create_door("east", "����С��", "west", DOOR_CLOSED);
    create_door("west", "����С��", "east", DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
    me = this_player();
    if ((me->query("id")!="course" && me->query("id")!="qixia") && dir == "west")
    {
       return notify_fail(RED"�����˼ҵ�˽լ����ȥ�����ˣ�\n"NOR);
    }
    if ((me->query("id")!="bite" && me->query("id")!="princess") && dir == "east")
    {
       return notify_fail(RED"�����˼ҵ�˽լ����ȥ�����ˣ�\n"NOR);
    }
    return ::valid_leave(me, dir);
}
void init()
{
	add_action("do_bian", "bian");
	add_action("do_look","read");
	add_action("do_upadm", "upadm");
	add_action("do_uplock", "uplock");
	add_action("do_upboot", "upboot");
}
int do_look(string arg)
{
	object me = this_player();
if (arg == "bei" || arg == "ʯ��" )
{
	me->start_more( read_file("/doc/help/famous.txt"));
//	me->cat("/doc/help/famous.txt");
	return 1;
}
	else
	write("��Ҫ��ʲô��\n");
	return 1;
}
