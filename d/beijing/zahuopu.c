// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
���Ǿ�������һ���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ������
�������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ���صĶ�����
̯������һ������(zhaopai)��
LONG
	);

	set("valid_startroom", 1);

	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));

	set("exits", ([
		"north" : __DIR__"shalan-e1",
	]));

	set("objects", ([
		__DIR__"npc/wei": 1,
	]));

	setup();
	replace_program(ROOM);
}