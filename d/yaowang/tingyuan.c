// Room: ����ҩ��
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "ͥԺ");
	set("long", @LONG
����һ�������ͥԺ��ͥԺ��������һ����ʯ�̳ɵ�С·��
�������ż���С����������һ����������������ǳ���
ҩ�ļ���ҩ��������������ҩ���ʷ��ı�����
LONG );
	set("area", "������");
	set("areb", "�ش���");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"beiting",
		"south" : __DIR__"nanting",
		"west" : __DIR__"zhengting",
		"east" : __DIR__"huichun",
	]));
	set("objects", ([
		__DIR__"npc/zhanggui" : 1,
	]));
        set("outdoors", "yaowang");
	setup();
	replace_program(ROOM);
}
