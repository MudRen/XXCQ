// /d/playertown/road2.c ��ʯС��
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","��ʯС��");
	set("long",@LONG
����һ������ʯ�ӵ�С·�����߳��ż��Ÿߴ������������Χ��
һСƬ�յأ���ɫ�����ǳ��ʺϽ�����
LONG );

	set("recordable_room",1);
	set("outdoors","playertown");
	set("exits",([
		"north"	:	__DIR__"road1",
		"south"	:	__DIR__"road3",
		"west"	:	__DIR__"road15",
	]));
	
	setup();
	
	replace_program(ROOM);
	
}
