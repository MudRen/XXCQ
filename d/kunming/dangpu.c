// Room:/d/kunming/dangpu.c
// JackyBoy@CuteRabbits Studio for CCTX 1999/4/17
inherit SR_DANGPU;
void create()
{
	set("short", "����");//���Ӧ�ÿ�������Ҹı�
	set("long", @LONG
����һ��Ϊ������ʿ����ĵ��̣�����Ը��ٸ�Ͷ����������Ӫ�����߽�
��Ҳ�ÿ��ǿ���׬Ǯ�����Ⱑ��
LONG
	);
	set("exits", ([
		"west" : __DIR__"nanjie1",
	]));
	setup();
	replace_program(SR_DANGPU);
}
