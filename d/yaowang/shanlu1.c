// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����С��ɽ·�ϣ�������һƬ��ľ�ԣ�ɽ·����ͨ��һ���������Ƶ�
ɽ�ȣ�����ͨ�������ǡ�ɽ�紵�����㲻�����������⣬���Ǿ����뿪Ϊ�á�
LONG );
	set("area", "ҩ����");
	set("areb", "ɽ·1");
	set("exits", ([
        "south" : "/d/bianliang/jiebei4",
		"north" : __DIR__"shanlu2",
	]));

        set("outdoors", "yaowang");
	setup();
	replace_program(ROOM);
}
