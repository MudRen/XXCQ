// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
��û�߽������̣����������Ѿ����˹��������������Ĵ����̣���
�����ڹ��ŵ�Ҳ����ũ���õ����������������������ͣ�����еĻ�վ��
��ӭ��������
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"hyroad3",
	]));

	set("objects", ([
		__DIR__"npc/tiejiang": 1,
	]));

	setup();
	replace_program(ROOM);
}