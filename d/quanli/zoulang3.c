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
                        "southwest" : __DIR__"dati",
                        "east" : __DIR__"quanlili",
	]));
        replace_program(ROOM);
	setup();
}
