// Room: /d/shaolin/banruo1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�޺���ƫ��");
	set("long", @LONG
�����޺��ñ�ƫ���һ�伫Ϊ��ª���������������ܣ����˼�����
���⣬���ڿյ����ر���������������ֹ���֮һ�Ľ��䷿�����ϰ�
����һ�������ҷ��ڵĻƲ����ţ�һλ�뷢���׵���ɮ�������������Ŀ
�붨�������Ǹ��𿴹ܽ��䷿����ա�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"luohan",
		"east" : __DIR__"kfroom_2",
	]));

	set("objects",([
		"/kungfu/class/shaolin/tiankong" : 1,
	]));

	setup();

}

void init()
{
	object me = this_player();

	if (me->query_temp("kfroom_2"))
	{
		me->delete_temp("kfroom_2");
		environment(me)->delete_temp("kfroom_2");
	}
}

int valid_leave(object me, string dir)
{
	if( !me->query_temp("kfroom_2"))
	{
		if (dir == "east")
		{
			return notify_fail("���䷿�������أ�û����յ�����˭Ҳ����ȥ��\n");
		}
	}
	return ::valid_leave(me, dir);
}