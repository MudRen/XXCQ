// Room: /d/shaolin/wuchang1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ���
��̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м������Ų���ľ�ˡ�
ʮ����ɮ��������ϰ���ա�������һ����ɮ����
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"zoulang2",
		"west" : __DIR__"wuchang6",
		"east" : __DIR__"wuchang",
		"north" : __DIR__"zoulang6",
	]));
	set("objects",([
		"/kungfu/class/shaolin/tiehua" : 1,
        ]));
	set("outdoors", "shaolin");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

