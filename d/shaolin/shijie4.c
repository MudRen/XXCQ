// Room: /d/shaolin/shijie4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ɽ��СϪ");
	set("long", @LONG
ˮ��Խ��Խ��ɽ�������ŨŨ��ˮ����ʯ���ϣ����ѵ�ɽ϶�У���
����һ����ϸϸ��Ȫˮ�����һ�ɳα̵�СϪ����ɽ��������ȥ����Χ��
�⵴���������������������ɾ���������ɽ��������ɮ������ˮͰ������
��ˮ��
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"northup" : __DIR__"shijie5",
		"eastdown" : __DIR__"shijie3",
	]));
	set("sljob",1);
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
