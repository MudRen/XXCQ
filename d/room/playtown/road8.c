// /d/playertown/road1.c ��ʯС��
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","�����");
	set("long",@LONG
������һ��������С���ϣ�����һ������ڣ�������һ����ʯС
��������Ͷ�������������ש�̳ɵ�·��
LONG );

	set("outdoors","playertown");
	set("no_clean_up",0);
	
	set("exits",([
		"northwest" : __DIR__"road9",
		"northeast" : __DIR__"road10",
		"south"	: __DIR__"road7",
		"west"	: __DIR__"road17",
	]));
	
	setup();
	
	replace_program(ROOM);
	
}
