// Room:/d/kunming/xijie1.c
// JackyBoy@CuteRabbits Studio for CCTX 1999/4/17

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������ĳ��й㳡���ϱߵĿ�ջ�Ϲ���һ��С��(qi)�����ɷ����д
�ż������֣������������������������ֹ���Ʒ�֡�����ȴ�ǹٸ��ļ���
���Σ���˵��������һЩ���̷���
LONG
	);
	set("exits", ([
		"south" : __DIR__"kedian",
		"east": __DIR__"guangchang",
		"north": "/d/sroom/jianyu_men",
	]));
	set("outdoors","kunming");
	setup();
	replace_program(ROOM);
}
