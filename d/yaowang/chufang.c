// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ҩ���ȵĳ�����һ���ŵ�¯�����������һ����֪����
��Ҫ�ṩȫ�ȵ��ӵ���ʳ����������ˣ����������ҪЩ�Եġ�
LONG );
	set("area", "ҩ����");
	set("areb", "����");
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"dongting",
	]));

	set("objects", ([
		__DIR__"npc/huoji3" : 1,
	]));
	setup();
	replace_program(ROOM);
}
