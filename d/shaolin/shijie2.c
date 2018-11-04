// Room: /d/shaolin/shijie2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������ʯ��������Ȼ��������ͷ����ߵ�ɽ�����ų������Ľ���
�����˱�������̦��������ϡ��Щ����ĺۼ�����һ�����Ե��ر�������
����շ�аħ��������Ⱥ����!
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"southdown" : __DIR__"shijie1",
		"northup" : __DIR__"shijie3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
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
	}

	return ::valid_leave(me, dir);
}
