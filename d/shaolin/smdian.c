// Room: /d/shaolin/smdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ɽ�ŵ�");
	set("long", @LONG
�����������µ�ǰ��ɽ�ŵ������ש�̵أ�������кߡ���������
������ΰ�������ŭ��ͷ�����ڣ��ϰ�����¶����ִ����ƣ�һ�ıǣ�һ
�ſڣ�¶����Ŀ�����Ϳ�η�����߸���һ��ľ���������������Թ�ɮ��
ߵ�ݡ��Դ����Ҹ���һ��ƫ��������Ǵ����о�֮�á�������һ������
���ߵ����ɼľ��ͭ���š�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"east" : __DIR__"smdian1",
		"west" : __DIR__"smdian2",
		"north" : __DIR__"taijie",
		"south" : __DIR__"guangchang1",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
		__DIR__"npc/xiang-ke" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;

	return ::valid_leave(me, dir);
}

