// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "ҩ����");
	set("long", @LONG
�������ҩ�����ˣ���Χ�Ǹ߸ߵ�ɽ�壬ɽ����һ��Ƭ�Ŀյأ���������һ��
ׯ԰��������һƬũ����������ݲ�֪������ô������
LONG );
	set("area", "ҩ����");
	set("areb", "ҩ����");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"zhuangqian",
		"west" : __DIR__"tiandi1",
		"east" : __DIR__"tiandi2",
	]));
         set("objects", ([
                 __DIR__"npc/lufeng" : 1,
         ]));

	setup();
	replace_program(ROOM);
}
