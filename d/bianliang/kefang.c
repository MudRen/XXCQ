// Room: /city/kefang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����ջ�ͷ�");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ��������
���������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ�������
��ŵ����˹�ȥ��
LONG
	);

	
	set("valid_startroom", 1);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);

	set("exits", ([
		"out" : __DIR__"guangming",
	]));

	set("area", "����");

	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}


