// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥����");
	set("long", @LONG
��¥�����������͵�������¥�Ķ��㡣�㻷��һ��������ֶ����
�������һ�������ֻ࣬��һ����Բ�����İѺ�ľԲ�ΰ��ڶ�����
�䣬����һ���鰸��һ�������ǽ�������ϱ����涼�д�����ͨ��������
��ȫ��������®��һ���������ٴ���������һ���������ƺ�����֪����
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"down" : __DIR__"tingyulou",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/kaiyan" : 1,
	]));

	setup();
	replace_program(ROOM);
}