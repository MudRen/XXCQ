// /d/playertown/road1.c ��ʯС��
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","��ʯС��");
	set("long",@LONG
����һ����ʯС��������������������������������С·������
���棬һ��С���������ǣ����洫�������ǵĵ�������
LONG );

	set("recordable_room",1);
	set("outdoors","playertown");
	set("no_clean_up",0);
	
	set("exits",([
		"north"	:	__DIR__"road8",
		"south"	:	__DIR__"road6",
		"east"	:	__DIR__"miao",
	]));
	
	setup();
	
	replace_program(ROOM);
	
}
