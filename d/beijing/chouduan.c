// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�Һͳ����");
	set("long", @LONG
	����һ�Һ�����˿���У��������ڱ���С��ӭ���������������ܣ���ׯ��
�����˸��ֲ��Ϻͳ��£�����е��ϰ��˿���������ڹ�̨��ææµµ���ƺ���
����ʲô��������·����������ǳ��ã�����������һ�ߣ�����ʲô��
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"shalan-w1",
	]));
        set("objects", ([
                 __DIR__"npc/xiaoer2": 1,
                 __DIR__"npc/cai": 1,]));

	setup();
	replace_program(ROOM);
}

