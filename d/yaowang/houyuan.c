// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
������ҩ����ɽׯ�ĺ�Ժ��Ժ�����ż���С��������һ��ˮ����
һ������ʯ�̳ɵ�С·ͨ��һ�����š�
LONG );
	set("area", "ҩ����");
	set("areb", "��Ժ");
	set("no_fight", 1);
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"xiaolu1",
		"south" : __DIR__"dating",
	]));

	setup();
	replace_program(ROOM);
}
