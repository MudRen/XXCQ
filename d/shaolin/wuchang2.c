// Room: /d/shaolin/wuchang2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ���
��̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м������Ų��ٲݰС�
ʮ����ɮ��������ϰ���ա�������һ����ɮ����
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"zoulang3",
		"west" : __DIR__"wuchang",
		"east" : __DIR__"wuchang7",
		"north" : __DIR__"zoulang7",
	]));
	set("objects",([
		"/kungfu/class/shaolin/tieshu" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

