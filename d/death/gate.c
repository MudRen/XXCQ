// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "���Ź�" NOR);
	set("long", 
		"�������������������ڡ����Źء���������ǰ������һ���ߴ��\n"
		"��ɫ��¥������������޿�������ж�ǰ������Ϊһ�����Źؾ��޷���\n"
		"�������ˡ�\n");

	set("exits", ([
		"north" : "/d/death/gateway",
	]) );

	set("valid_startroom", 1);

	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );
	setup();
}

void init()
{
	object ob;

	ob = this_player();
	ob->set("startroom","/d/death/gate");
}
