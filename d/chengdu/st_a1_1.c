// Room:/d/chengdu/st_a1_1.c
// JackyBoy@CuteRabbits Studio for CCTX 1999/9/13

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
����һ������·�ڵĿ�ջ���������ǳɶ�������С�Խ��ˣ�ԶԶ��ȥ��������
�������֡��Ϸ���һ������
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);

	set("exits", ([

	]));

	setup();
	replace_program(ROOM);
}
