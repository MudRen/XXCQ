// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����ӻ���");
	set("long", @LONG
����һ��СС���ӻ��̣�����С������������ĵ���λ�ã�ʹ����
������ǳ��Ĳ����������ϰڷŵ���Щ�����䲻�߹�ȴҲʵ�ã����ϰ�
�ڴ˿�����ʮ�꣬�����ǲ���˵�ġ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"hyroad3",
	]));

	set("objects", ([
		__DIR__"npc/hu": 1,
	]));

	setup();
	replace_program(ROOM);
}