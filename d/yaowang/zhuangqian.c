// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "ׯǰ");
	set("long", @LONG
������ҩ��ɽׯ�Ĵ��ţ�����ҩ���ȵش�ƫƧ��������������Ҳ�����䱸��
�����ߴ��ׯ����д�š�ҩ���ȡ���
LONG );
	set("area", "ҩ����");
	set("areb", "ׯǰ");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"yaowanggu",
		"south" : __DIR__"gukou",
	]));

	setup();
	replace_program(ROOM);
}
