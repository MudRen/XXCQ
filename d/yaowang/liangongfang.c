// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���߽�һ��ͦ���ķ��䡣������ʯ�̵أ�ǽ�߷��ż��������ޣ����滭������
�ϵľ���������Ѩ��������ҩ���ȵ���������ϰ(lianxi)��ĵġ�
LONG );
	set("area", "ҩ����");
	set("areb", "������");
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"xiting",
	]));
	set("objects", ([
		__DIR__"npc/buwawa" : 1,
	]));
	setup();
	replace_program(ROOM);
}
