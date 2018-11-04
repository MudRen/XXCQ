// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�Ÿ�����");
	set("long", @LONG
����˵�ǲ��ã�ʵ����һ��ʱ���Ѿõ�ľ�巿����ǰ�жŸ��ν���ʱ
����д�ġ��Ÿ����á����Ҷ����������һ��˽�ӣ��������˶�������
������ѽ���ʮ�������µ���ͯ��
LONG
	);

	set("valid_startroom", 1);
	set("no_fight", 1);
        set("no_sleep_room",1);

	set("exits", ([
		"west" : __DIR__"fhroad3",
	]));

	set("objects", ([
		__DIR__"npc/du": 1,
	]));

	setup();
	replace_program(ROOM);
}