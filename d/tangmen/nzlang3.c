//nzlang3.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ƹ󱱲�����ȡ������Ǳ��̵ĺ�ˮ�������ɻ�������
�ţ���������������������ֹ����ǰ������ͨ�����Ƹ��լ��
LONG);
	set("exits", ([
			"south" : __DIR__"nzlang2",
			"north" : __DIR__"tangltt",
			"west" : __DIR__"tangshe",
			"east" : __DIR__"tangting",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}