// /d/playertown/road1.c ��ʯС��
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","��ש·");
	set("long",@LONG
����һ���ǳ�ƽ������ש�̳ɵ�·��������һ���ǳ����µ�С��
԰�������Ǵ�Ů�Ǿ�����˵ĵط� -���ĳأ���������һ������
�ڣ��ǳ���ıؾ�֮·��
LONG );

	set("recordable_room",1);
	set("outdoors","playertown");
	set("no_clean_up",0);
	
	set("exits",([
		"north"	:	__DIR__"huayuan4",
		"east"	:	__DIR__"nvyutang",
		"southwest"	:	__DIR__"road8",
	]));
	
	setup();
	
	replace_program(ROOM);
	
}
