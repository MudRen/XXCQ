// Room:/d/kunming/nanjie1.c
// JackyBoy@CuteRabbits Studio for CCTX 1999/4/17

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�����������ĳ��й㳡�����ߵ�������ջռ���˵���֮�㣬��������ĺ�
���ÿ����˶�ϲ�������������СЪһ�ᣬ������һ����ҵ�֣�����������
�Լ�����������Ŀ��̶����������￪���̣���������ٸ���˰���꣬�����
�Ǻ�𡣶�����һ��Ϊ������ʿ����ĵ��̣�����Ը��ٸ�Ͷ������������Ӫ
�ġ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"kedian",
		"north": __DIR__"guangchang",
		"east" : __DIR__"dangpu",
	]));
	set("outdoors","kunming");
	setup();
	replace_program(ROOM);
}
