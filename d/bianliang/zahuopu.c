// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
���Ǿ�������һ���ӻ��̣�����С�������һ�أ�����һЩ�ճ���
Ʒ��Τ�ƹ������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ
��һЩ���صĶ�����
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"nandajie2",
	]));

	set("objects", ([
		__DIR__"npc/wei": 1,
	]));

	set("area", "����");

	setup();
	replace_program(ROOM);
}