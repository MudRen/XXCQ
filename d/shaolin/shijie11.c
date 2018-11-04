// Room: /d/shaolin/shijie11.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���ֽ�����������ǰ������һ������ʯ�������ֱͨ��ǰ�����ص�
ϡϡ��������ż��ð�����ȴ�Եøߴ�ͦ�Σ��������֦������ո߸���
չ�š�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"southdown" : __DIR__"shijie10",
		"north" : __DIR__"guangchang1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if ( me->query("id") == "seng bing" &&  dir == "southdown" ) return 0;
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
