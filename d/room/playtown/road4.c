// /d/playertown/road4.c ��ʯС��
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","��ʯС��");
	set("long",@LONG
�����С������Ĵ�֣�����������ϲ���ۼ���������ĵط���
���ҿ��˿���������Լ���Կ���һ������С¥��������Ĳ�Զ
����һ��Сͤ��
LONG );

	set("recordable_room",1);
	set("outdoors","playertown");
	set("exits",([
		"west"	:	__DIR__"road3",
		"east"	:	__DIR__"road6",
	]));
	
	setup();
	
	replace_program(ROOM);
	
}
