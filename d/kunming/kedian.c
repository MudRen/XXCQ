// Room:/d/kunming/kedian.c
// JackyBoy@CuteRabbits Studio for CCTX 1999/4/17

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
����һ�ҿ�ʮ��·�ڵĿ�ջ�����̺��е��ģ�ˣ�����Ҳ����������
���˶�ϲ��ѡ��������ţ���Ϊ����ĵ���Ҳ��һ���������ˣ����Ժ�������
���������£�С��æǰæ����к����ˣ�����Ҳ����Ц�ݵ�����˵�û�������
��һ�ֹ�ҵĸо���
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);

	set("exits", ([
		"east"  : __DIR__"nanjie1",
		"north" : __DIR__"xijie1",
	]));

	setup();
	call_other("/clone/board/kedian_km_b","???");
	replace_program(ROOM);
}
