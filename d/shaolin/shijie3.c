// Room: /d/shaolin/shijie3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ���������ƺ���ÿ�����Щ�����µ�ɽ��������������˾����Ϊ
һˬ��Զ����������ˮ�������н�Զ��ɽ���Ϲ����˺��ܵ����ܣ������
��ҡ߮��
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"southdown" : __DIR__"shijie2",
		"westup" : __DIR__"shijie4",
	]));
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

