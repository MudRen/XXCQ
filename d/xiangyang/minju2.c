// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "é����");
	set("long", @LONG
����һ����ͨ��é�ݷ������Ӽ�ͽ�ıڣ�ֻ�д��������ĺ촰������
��һ��������������һ��é�ݣ������Ϸ���һ��С��һ����̫̫̾����
�������ӱ��ϲ����·���
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"maitian1",
	]));

	set("objects", ([
		__DIR__"npc/laotai": 1,
	]));

	setup();
	replace_program(ROOM);
}