// Room: girlroom.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
//

inherit ROOM;

void create()
{
	set("short", "Ů��������");
	set("long", @LONG
����һ����ķ��䣬���ڽ��еļ��ȴ���ȴ�����Ŵ��������ڷǳ�
���࣬����͸��һ�����㡣��ǽ��������̨�ӣ�̨���ϵ����㣬ǽ�ϻ���
��һ��ͭ����������Ů�����ǻ�ױ�õġ�������ʣ�µľ��Ǽ��Ŵ󴲺�һ
�����¹��ˡ�
LONG
	);

	set("no_fight", 1);

	set("sleep_room", 1);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"xiaojing",
	]));

	setup();
	replace_program(ROOM);
}