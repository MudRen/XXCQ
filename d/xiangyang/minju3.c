// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "é����");
	set("long", @LONG
����һ����ͨ��é�ݷ������Ӽ�ͽ�ıڣ��������õķǳ��ĸɾ�����
����ҵ�Ů�˺ܰ��ɾ���һ��Լ��ʮ����Ĵ帾��ɨ�ŵأ����ʱ������
Ӧ�ö���ȥ�ˡ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"maitian2",
	]));

	set("objects", ([
		__DIR__"npc/cuihua": 1,
	]));

	setup();
	replace_program(ROOM);
}