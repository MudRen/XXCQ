// Room: ����ҩ��
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����ķ��䣬��������ҩ��һ��ŨŨ��ҩζ����
������Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С������ɢ�������ġ�
LONG );
	set("area", "������");
	set("areb", "�ش���");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"tingyuan",
		"west" : __DIR__"neiwu",
	]));
	set("objects", ([
		__DIR__"npc/huoji1" : 1,
	]));
	setup();
	replace_program(ROOM);
}
