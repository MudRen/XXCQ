// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�е���˯��");
	set("long", @LONG
����һ��谵�ķ��䣬������е�һ�ȴ�����������������������һ
�Ŵ�ͨ�̣���Լ����˯ʮ�����ˣ����������Ĺ������Կ��������Ѿ�˯��
�������ˡ���û��˼ϸ�۲죬æ���˸��ط��ϴ���������
LONG
	);

	set("no_fight", 1);

	set("sleep_room", 1);

	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"qqlang_3",
	]));

	setup();
	replace_program(ROOM);
}