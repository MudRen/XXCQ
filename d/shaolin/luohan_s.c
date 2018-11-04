// Room: /d/shaolin/banruo1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�޺���ƫ��");
	set("long", @LONG
�����޺�����ƫ���һ�伫Ϊ��ª���������������ܣ����˼�����
���⣬���ڿյ����ر���������������ֹ���֮һ�����䷿�����ϰ�
����һ�������ҷ��ڵĻƲ����ţ�һλ�뷢���׵���ɮ�������������Ŀ
�붨�������Ǹ��𿴹����䷿����衣
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"luohan",
		"east" : __DIR__"kfroom_6",
	]));

	set("objects",([
		"/kungfu/class/shaolin/tianhong" : 1,
	]));

	setup();

}

int valid_leave(object me, string dir)
{
	if( !me->query_temp("kfroom_6"))
	{
		if (dir == "east")
		{
			return notify_fail("���䷿�������أ�û����������˭Ҳ����ȥ��\n");
		}
	}
	return ::valid_leave(me, dir);
}