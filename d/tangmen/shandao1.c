//shandao1.c		�Ĵ����š���ɽɽ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������ͨ��ɽ����С�����涸�ޱȣ�һ��С�ľͻ�ˤ��ȥ������
�Ǹ������ƵĲ�����������д���Ұ�޵�˺ҧ��������ë���Ȼ����
����������ȫ���ע������Ұ��������
LONG);
	set("exits", ([
			"westdown" : __DIR__"houshan",
			"northeast" : __DIR__"shandao2",
	]));
	set("area", "����");
	set("objects", ([__DIR__"npc/xiezi" : 1,__DIR__"npc/snake" : 1,]));
	setup();
	replace_program(ROOM);
}