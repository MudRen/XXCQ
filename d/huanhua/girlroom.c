// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "Ů����˯��");
	set("long", @LONG
����һ��谵�ķ��䣬������е�һ�ȴ��������������������ں���
���࣬����͸��һ�����㡣ͨ�̵����м���Ů���Ӻ��¶�˯����û��˼ϸ
�۲죬æ���˸��ط��ϴ���������
LONG
	);

	set("no_fight", 1);

	set("sleep_room", 1);

	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"jqlang_3",
	]));

	setup();
	replace_program(ROOM);
}