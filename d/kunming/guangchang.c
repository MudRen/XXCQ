// Room:/d/kunming/guangchang.c
// JackyBoy@CuteRabbits Studio for CCTX 1999/4/17

inherit ROOM;

void create()
{
	set("short", "���й㳡");
	set("long", @LONG
�����������ǵ����Ĺ㳡�������Ϸ��ż���ʯ������������һЩ�ٸ���ͨ
�档�����������������˶������ﾭ�������Կ�����������������С����Ϣ��
Ҳ�����������ٵĽ�����ʿ��
LONG
	);
	set("exits", ([
		"south" : __DIR__"nanjie1",
		"west"  : __DIR__"xijie1",
	]));
	set("outdoors","kunming");
	setup();
	replace_program(ROOM);
}
