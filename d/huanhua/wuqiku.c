// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǽ�®�ı��������������ϼ����϶�ɢ�ҵİڷ���һЩ��ͨ�ı�
�������糤�����ֵ����������������һ�����������û���������΢
��һ�£�Ҳ����б������黹�ġ�
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"wuchang2",
	]));
        set("objects", ([
		__DIR__"npc/obj/zhujian" : 2,
		__DIR__"npc/obj/ruanjian" : 2,
	]));

	setup();
	replace_program(ROOM);
}
