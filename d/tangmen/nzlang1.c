//nzlang1.c		�Ĵ����š�����

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
			"east" : __DIR__"ezlang1",
			"west" : __DIR__"wzlang1",
			"south" : __DIR__"lianyunge",
			"north" : __DIR__"neiyuan",
	]));
	set("area", "����");
	set("objects", ([__DIR__"npc/tangfang" : 1,]));
	setup();
	replace_program(ROOM);
}