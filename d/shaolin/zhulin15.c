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
		"east" : __DIR__"zhulin16",
		"west" : __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}
