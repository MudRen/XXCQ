// /d/playertown/road1.c ��ʯС��
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","��ʯС��");
	set("long",@LONG
������һ��������С���ϣ�ʱ���дӶ�������������������
�Ĵ�����ȥ��������һ�����ֵļ��У��Ǵ�Ůÿ���ȥ�ĵط�������
�Ǵ峤�ľ���������һЩ�˻���Űݷá�
LONG );

	set("recordable_room",1);
	set("outdoors","playertown");
	set("no_clean_up",0);
	
	set("exits",([
		"north" : __DIR__"road11",
		"east" : __DIR__"road17",
		"west" : __DIR__"chunzhangjia",
		"south":	__DIR__"road2",
	]));
		
	setup();
	
	replace_program(ROOM);
	
}
