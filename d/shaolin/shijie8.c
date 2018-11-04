// Room: /d/shaolin/shijie8.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���￴���ǰ�ɽ���ˡ���Զ��ǰ����һ��Сʯͤ����λ�ο�������Ъ
Ϣ��ɽ·��������ʮ��ƽ̹�����ߵ�ɽ�������������˼������µ�ʫ��
��Զ��ɽ�ּ���͵��֣���Ŀ�δ䡣
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"westdown" : __DIR__"shanmen",
		"northup" : __DIR__"shijie9",
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
