// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
�߽�С�ƹݣ�������ߡ��˸�����һ��Ⱦ����죬��ϸ������ԭ����
�����Ľ�®����������������һ�����꺺�Ӷ������ڽ���������Ϸ�
��һ��������һ����֪���Ǹ��ر�����
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"hyroad4",
	]));

	set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}