// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "ҩ���ȴ���");
	set("long", @LONG
���߽�һ��ǳ����ķ��䣬��������һ�����ĵ�̺����ǰ������һ��̫ʦ��
һ����֪�����ǹ�������λ�����߸�����һ�����ӡ��Ա�ǽ�Ϲ���һ�����԰�
��board����ר�Ź�ҩ���ȵ��ӽ���ʹ�õġ�
LONG );
	set("area", "ҩ����");
	set("areb", "����");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"houyuan",
		"south" : __DIR__"yaowanggu",
		"west" : __DIR__"xiting",
		"east" : __DIR__"dongting",
	]));
         set("objects", ([
                 __DIR__"npc/zongguan" : 1,
         ]));

	setup();
         call_other("/clone/board/yaowang_b", "???");
	replace_program(ROOM);
}
