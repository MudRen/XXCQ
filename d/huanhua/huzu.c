// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��Х��");
	set("long", @LONG
����һ��ƫ�᷿����������һ����ң����������߷�ġ���Х�á���
�����֣�������һ��Ӳľ�참��һ�����������ں��淭���ż����˲�����
��佻����Ӳ�ͣ�Ľ����������Ǹ����������������ɵķ����Ÿ������
LONG
	);

	set("exits", ([
		"west" : __DIR__"southyuan",
	]));

        set("objects", ([
        __DIR__"npc/li" : 1,
		__DIR__"npc/zuyuan_h" : 1,
	]));

      set("no_fight",1);
	setup();
	replace_program(ROOM);
}
