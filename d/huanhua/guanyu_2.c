// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���Ϲ������㣬���Ͼͱ�չ������ǰ�ĺ����������������Ƿ����
����������ҡҷ�ĺɻ�����������̿գ����������ˡ�һ��Ů����վ��¥
��ǰ����Զ������֪������ʲô��
LONG);

	set("valid_startroom", 1);
	set("exits", ([
		"down" : __DIR__"guanyu",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/xueyu" : 1,
	]));

	setup();
	replace_program(ROOM);
}