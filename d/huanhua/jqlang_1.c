// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ������ϰ��ľ����ȣ����������ϱ�Զ�������������ĺ�������
������һ��ʯ��·�������죬��Լ����һ�����Ĺ㳡������Ӧ���ǽ�®
�����䳡�������������������غ����С�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"jqlang_2",
		"northeast" : __DIR__"hupan_s",
		"south" : __DIR__"wuroad2",
	]));

        set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}