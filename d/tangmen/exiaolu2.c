//exiaolu2.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
�����Ǻ�ɽС·����·Խ��Խխ���Ӳ�ȴ����ï���Ѿ������߰�
��ʱ��Զ������������Х������ͷƤ���飬С·������������ǰ��ȥ
ͨ����������ĺ�ɽ��
LONG);
	set("exits", ([
			"west" : __DIR__"exiaolu1",
			"eastup" : __DIR__"houshan",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}