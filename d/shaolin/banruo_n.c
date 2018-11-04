// Room: /d/shaolin/banruo1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "������ƫ��");
	set("long", @LONG
���ǰ����ñ�ƫ���һ�伫Ϊ��ª���������������ܣ����˼�����
���⣬���ڿյ����ر���������������ֹ���֮һ��ʼ�䷿�����ϰ�
����һ�������ҷ��ڵĻƲ����ţ�һλ�뷢���׵���ɮ�������������Ŀ
�붨�������Ǹ��𿴹�ʼ�䷿��������
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"banruo",
		"west" : __DIR__"kfroom_1",
	]));

	set("objects",([
		"/kungfu/class/shaolin/tianpeng" : 1,
	]));

	setup();

}

void init()
{
	object me = this_player();

	if (me->query_temp("kfroom_1"))
	{
		me->delete_temp("kfroom_1");
		environment(me)->delete_temp("kfroom_1");
	}
}

int valid_leave(object me, string dir)
{
	if( !me->query_temp("kfroom_1"))
	{
		if (dir == "west")
		{
			return notify_fail("ʼ�䷿�������أ�û������������˭Ҳ����ȥ��\n");
		}
	}
	return ::valid_leave(me, dir);
}