// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ҩ���ȵ�����������Χǽ�ڶ�����ʯ�����ɵģ���ש�̵أ�
�����������һ����ͭ���ɵĴ�¯��
LONG );
	set("area", "ҩ����");
	set("areb", "��������");
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"xiaolu1",
	]));
	set("objects", ([
		__DIR__"npc/obj/danlu1" : 1,
	]));
	setup();
	replace_program(ROOM);
}
