//houroad4.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
�����Ǻ�լ�������ʯС·�������Ŀ�������Զ������������
ˮ����չĿ��ȥ�Ѿ����Կ����ڷ���ҡ�ڵ�ƬƬ��Ҷ��һ����紵��
����һ�ɺɻ����㡣
LONG);
	set("exits", ([
			"west" : __DIR__"houyuan",
			"east" : __DIR__"houroad3",
			"northwest" : __DIR__"dufang",
			"southwest" : __DIR__"dcailiao",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}