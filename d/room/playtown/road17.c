// /d/playertown/road3.c ��ʯС��
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","��ʯС��");
	set("long",@LONG
����һ������ʯ�ӵ�С·�����߳��ż��Ÿߴ������������С·�ı�
������������С����ߺ��������ż��о�������ɣ���������ͨ�������
·�������С·�������ׯ�����ġ�
LONG );

	set("recordable_room",1);
	set("outdoors","playertown");
	set("exits",([
"enter"  :  "data/room/feixue/xiaoyuan.c",
		"east"	: __DIR__"road8",
		"west"	: __DIR__"road1",
	]));
	
	setup();
	
	replace_program(ROOM);
	
}
