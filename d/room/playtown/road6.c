// /d/playertown/road1.c ��ʯС��
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","��ʯС��");
	set("long",@LONG
����һ������ʯ�ӵ�С·�����߳��ż��Ÿߴ����������
�����·�ƺ����Ǳ����������ţ���������ͨ�������·����
С·�������Ȼ����һ��Сͤ��������ϡ�ɼ�������Ӱ��
LONG );

	set("recordable_room",1);
	set("outdoors","playertown");
	
	set("exits",([
		"north" : __DIR__"road7",
		"south" : __DIR__"road5",
		"west" : __DIR__"road4",
	]));
	
	setup();
	
	replace_program(ROOM);
	
}
