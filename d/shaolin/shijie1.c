// Room: /d/shaolin/shijie1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��������ɽ��´������ɽɽ�š�һ��������ʯ������������Ѷ��ϣ�
ֱû�ƶˡ���ɽȺ���������ɫ��ɽ�����˸����������С֮�⡣·����
����һ�����ݣ��������һ�����ӣ�����д����ɽ��վ�ĸ����֡�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"northup" : __DIR__"shijie2",
		"west" : __DIR__"ssyizhan",
         "southdown" : "/d/bianliang/guandao10",
		"east" : __DIR__"kys",
	]));
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

//    if (myfam && (myfam["family_name"] == "������" ) && !me->query("passmuren") && dir != "northup")
//       return notify_fail("���ֵ���û��ͨ��ľ�������ʮ���޺����ǲ����뿪��ɽ�ģ���ô�����봥���Ź棿\n");

	return ::valid_leave(me, dir);
}
