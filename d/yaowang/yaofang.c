// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
��һ�߽�������ŵ�һ��Ũ�ص�ҩζ��������ҩ���ȴ��ҩ�ĵĵط���
����ȫ������һ����С�����ҩ��ҩ�ĵ�Ʒ���湻��ġ�������ҩ��
��ҩ���Ķ����Ӹ���δ����ɲ����Ҷ���
LONG );
	set("area", "ҩ����");
	set("areb", "ҩ��");
	set("no_fight", 1);
	set("exits", ([
		"southwest" : __DIR__"dongting",
	]));

	set("objects", ([
        __DIR__"npc/huoji4" : 1,
	]));
	setup();
	replace_program(ROOM);
}
