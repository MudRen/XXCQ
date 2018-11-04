// Room: /d/shaolin/shijie5.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
һ�Ҿ޴���ٲ������������Խɽ�䣬ˮ����Ũ�÷·���Ե���ˮ��
������ɽ�ͼ����𱡱����������۲�ɢ��������ˮ�����������ʯ����
����ˮ�գ�����ȥ���ÿ������˴����
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"southdown" : __DIR__"shijie4",
		"northup" : __DIR__"shijie6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if (( present("shui tong", this_player())) && dir == "northup")
	{
		if (me->query("jingli")<15)
			return notify_fail("���Ŵ�ˮͰ�����Ѿ��۵��߲������ˡ�\n");
		me->add("jingli",-10);
		me->improve_skill("dodge",10+random(5));
		me->start_busy(1);
	}

	return ::valid_leave(me, dir);
}
