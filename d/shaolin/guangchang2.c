// Room: /d/shaolin/guangchang2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
�����������������ƽ�е���ʯ̨������ǰ����һ����㳡��̨��
�Ͽ̵��������ڷ�����޺��Լ���ǧ٤������������ƽ̨�����з�Ҳ
�и�����ߵĴ���¯����¯ǰ����̨�ϣ�������գ�����Ʈ�ƣ���λ���
���Դ����ߵ�ݡ����Ҹ�ͨ��һ��СԺ����������������ʡ���ǰ����
�Ǵ��۱��
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"twdian",
		"north" : __DIR__"guangchang3",
		"northup" : __DIR__"dxbdian",
		"east" : __DIR__"zhonglou",
		"west" : __DIR__"gulou",
	]));
	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"npc/tieshi" : 1,
		__DIR__"npc/tiexin" : 1,
	]));
	setup();
	replace_program(ROOM);
}

