#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʯС·");
        set("long", @LONG
�����Ǻ�ɽС·��ֻ��һ��ͨ���������Ӳݴ�������ʱ����ϤϤ����
�Ĳ�������ż������һ��ֻС��������ǰ�ӹ���С·������������ǰ��ȥ
��ͨ����������ĺ�ɽ��
LONG);
        set("exits", ([
		"north" : __DIR__"hsxiaolu2",
		"south" : __FILE__,
//		"east" : __FILE__,
//		"west" : __FILE__,
//		"northwest" : __FILE__,
//		"northeast" : __FILE__,
		"southeast" : __FILE__,
		"southwest" : __DIR__"hsxiaolu1",
        ]));
        set("outdoors", "����");
        setup();
        replace_program(ROOM);
}

