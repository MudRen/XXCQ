//exiaolu1.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
�����Ǻ�ɽС·��ֻ��һ��ͨ���������Ӳݴ�������ʱ����ϤϤ
�����Ĳ�������ż������һ��ֻС��������ǰ�ӹ���С·����������
��ǰ��ȥ��ͨ����������ĺ�ɽ��
LONG);
	set("exits", ([
			"south" : __DIR__"chaifang",
			"east" : __DIR__"exiaolu2",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}