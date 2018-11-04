// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǽ�®�ķ����ݣ�ǽ�Ϲ��ż��������õ�����ڵ��ϻ�����һ
Щ���ߣ���ָ�ס�ţƤ����ȡ�����Ը�����Ҫ���ϼ�������Щ������Ȼ
���ã���������ôֵǮ��������ò��Ż��ǲ�Ҫ���õĺá�
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"wuchang3",
	]));
        set("objects", ([
		__DIR__"npc/obj/liangongfu" : 3,
		__DIR__"npc/obj/huwan" : 2,
		__DIR__"npc/obj/shoutao" : 2,
	]));

	setup();
	replace_program(ROOM);
}