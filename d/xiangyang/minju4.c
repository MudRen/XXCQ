// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "é����");
	set("long", @LONG
����һ����ͨ��é�ݷ������Ӽ�ͽ�ıڣ������ǳ������ң���������
��ֻ��һ�����ˣ�һ����ʮ����ĺ��������ﶣ���������ô��ţ�������
���Ҿߡ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"tulu8",
	]));

	set("objects", ([
		__DIR__"npc/awang": 1,
	]));

	setup();
	replace_program(ROOM);
}