// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "é����");
	set("long", @LONG
����һ����ͨ��é�ݷ������Ӽ�ͽ�ıڣ�ֻ��һ�����Ӻ������Ƶ���
��������һ��é�ݣ������Ϸ���һС���̲ˡ�һ���Ϻ�̾�����������ӱ�
�Ϸ�����
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"tulu1",
	]));

	set("objects", ([
		__DIR__"npc/laohan": 1,
	]));

	setup();
	replace_program(ROOM);
}