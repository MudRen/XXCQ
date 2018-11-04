// Room: /d/shaolin/banruo1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�޺���");
	set("long", @LONG
�����á��޺��ü縺Ϊ����������ɮ�����Σ����������ڵ��޺�����
�����ֹ����еĽ��䡢���䡢�����������޺�������ľ����ʦ�Ĺ���Ҳ
�ǳ����뻯���������ߴ��ɮ֮һ�������õ�������Ǿ��䷿������ľ��
��ʦ���ֵľ��Ǹ��𿴹ܾ��䷿�����ޡ�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"luohan_n",
		"east" : __DIR__"kfroom_4",
		"south" : __DIR__"luohan_s",
		"west" :__DIR__"wuchang7",
	]));

	set("objects",([
		"/kungfu/class/shaolin/tianluo" : 1,
		"/kungfu/class/shaolin/muchan" : 1,
	]));

	setup();

}

int valid_leave(object me, string dir)
{
	if( !me->query_temp("kfroom_4"))
	{
		if (dir == "east")
		{
			return notify_fail("���䷿�������أ�û�����޵�����˭Ҳ����ȥ��\n");
		}
	}
	return ::valid_leave(me, dir);
}