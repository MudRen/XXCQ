// Room: /city/milin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬï�ܵ������֣����������Ѿ�û��·�ˣ�ֻ����Χ��������
�����֮����������������ͷ��һ�߽�������·���ʧ�˷�����˵��Ƭ
������ͨ�����ʯ�ıؾ�֮·��
LONG );
	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"chuzuan",
		"north" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}
