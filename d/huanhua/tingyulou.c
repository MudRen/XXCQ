// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
�߽�����¥���������ܵ���佻����ҵ�һ������֮����������������
һ�桰佻�ϴ�������Ҷ�ʹ������һ����̫������ġ����޸衱����
�ܰ���ļҾ߹�����Ҳ��Ϊ���š����ﲢû���ˣ�ֻ��һ���Ҷ�������
�̲衣���������¥��ͨ������¥�Ķ��㡣
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"out" : __DIR__"tingyudoor",
		"up" : __DIR__"tingyulou2",
	]));

        set("objects", ([
		__DIR__"npc/zuyuan_q" : 1,
	]));

	setup();
	replace_program(ROOM);
}