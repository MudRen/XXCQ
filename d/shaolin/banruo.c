// Room: /d/shaolin/banruo1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����á��޺��ü縺Ϊ����������ɮ�����Σ����������ڵİ�������
�����ֹ����е�ʼ�䡢���䡢���������������������ؼ���ʦ��������
�������������ߴ��ɮ֮һ�������õ�����������䷿�����ڵؼ���ʦ��
�ֵľ��Ǹ��𿴹����䷿�����̡�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"banruo_n",
		"west" : __DIR__"kfroom_3",
		"south" : __DIR__"banruo_s",
		"east" :__DIR__"wuchang6",
	]));

	set("objects",([
		"/kungfu/class/shaolin/tianxing" : 1,
		"/kungfu/class/shaolin/diji" : 1,
	]));

	setup();

}

void init()
{
	object me = this_player();

	if (me->query_temp("kfroom_3"))
	{
		me->delete_temp("kfroom_3");
		environment(me)->delete_temp("kfroom_3");
	}
}

int valid_leave(object me, string dir)
{
	if( !me->query_temp("kfroom_3"))
	{
		if (dir == "west")
		{
			return notify_fail("���䷿�������أ�û�����̵�����˭Ҳ����ȥ��\n");
		}
	}
	return ::valid_leave(me, dir);
}