// Room: /d/sroom/storage.c
// JackyBoy@CuteRabbit Studio 1999/5/21
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
	����һ�����������Ĵ����ҡ�
LONG
);
	set("valid_startroom",1);
	set("no_fight",1);
	setup();
	replace_program(ROOM);
}