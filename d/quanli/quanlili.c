//zoulang1��c              

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ȩ�����ϲ�����ȡ����������Ŵ�Ƭ�����֣�������죬��Ӱ
��涣���ʵ������⣬���в��ٱ���ϡ�е������м����У��������ϣ���
������������ 
LONG);
	set("valid_startroom",1);
	set("outdoors","����");
	set("exits", ([
                        "west" : __DIR__"zoulang3",
                        "east" : __DIR__"quanlili1",
	]));
        replace_program(ROOM);
	setup();
}
