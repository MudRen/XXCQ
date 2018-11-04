// Room: /d/shaolin/banruo1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "������ƫ��");
	set("long", @LONG
���ǰ�������ƫ���һ�伫Ϊ��ª���������������ܣ����˼�����
���⣬���ڿյ����ر���������������ֹ���֮һ�����䷿�����ϰ�
����һ�������ҷ��ڵĻƲ����ţ�һλ�뷢���׵���ɮ�������������Ŀ
�붨�������Ǹ��𿴹����䷿��������
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"banruo",
		"west" : __DIR__"kfroom_5",
	]));

	set("objects",([
		"/kungfu/class/shaolin/tianyin" : 1,
	]));

	setup();

}

int valid_leave(object me, string dir)
{
	if( !me->query_temp("kfroom_5"))
	{
		if (dir == "west")
		{
			return notify_fail("���䷿�������أ�û������������˭Ҳ����ȥ��\n");
		}
	}
	return ::valid_leave(me, dir);
}