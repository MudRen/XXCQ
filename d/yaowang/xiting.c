// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ҩ���ȵ�������������ҩ���ȹ������鷿���ǹ�����Ϣ�ĵط�������Ҳһ
�������ﴫ�ڵ��Ӽ��ա�������һ������������ҩ���ȵ�����ϰ���ܵĵط���
LONG );
	set("area", "ҩ����");
	set("areb", "����");
	set("no_fight", 1);
	set("exits", ([
		"west" : __DIR__"liangongfang",
		"east" : __DIR__"dating",
		"north" : __DIR__"shufang",
	]));

	setup();
	replace_program(ROOM);
}
