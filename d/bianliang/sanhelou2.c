// Room: /city/sanhelou2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳�
�ȱ������ס����ҪԱ���Ӹ�����������ĥʱ�⣬��վ��¥������������
һ���޾���ͬ�������������Ӱ��Զ���������������ܳ缹ֻ�����Ŀ���
������¥���ƹ���ϰ������������д����ˡ�
LONG
	);

	set("valid_startroom", 1);

	set("objects", ([
		__DIR__"npc/hu" : 1,
	]));

	set("exits", ([
		"down" : __DIR__"sanhelou",
	]));

	set("area", "����");

	setup();
	replace_program(ROOM);
}