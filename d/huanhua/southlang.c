// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����Ľ�®�����಻�ϵĻ������ӵģ��������ڵ�������ȵ�����
�ֱ��ǻ�̳������Ժ�������Ż���������ͨ���仨̶�������ȵط�����
ʱ��Ѿ�ߡ��Ҷ��߹����
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"qianroad2",
		"west" : __DIR__"southlang_2",
		"south" : __DIR__"southyuan",
	]));

        set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}