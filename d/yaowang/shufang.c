// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
���߽�һ���鷿��������ҩ���ȹ�����ҩ�����ڵ��Ӽ��յĵط���������Χ��ǽ
��ȫ�ǰ���װ�������ܣ�������ҩ�����������Ӻ����̫ʦ���ϡ�
LONG );
	set("area", "ҩ����");
	set("areb", "�鷿");
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"xiting",
	]));

	set("objects", ([
		__DIR__"npc/naiyaoer" : 1,
	]));
	setup();
	replace_program(ROOM);
}
