//houroad3.c		�Ĵ����š���ʯС·

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
			"east" : __DIR__"houroad2",
			"west" : __DIR__"houroad4",
			"northwest" : __DIR__"biaofang",
			"southwest" : __DIR__"bcailiao",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}