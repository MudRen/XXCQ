// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ƺ�С��");
	set("long", @LONG
�߽��ƺ�С���������Ҳ���Ҵ�һ�£���Ϊ佻����ɵ�������������
¥�������鰸����ܱʼ��飬��ʱ��վ�����ⲽ����˼�����ҿ�ǽ������
�����˸ߵ���ܣ���������˸����鼮������ǽ�������һ��������
LONG
	);


	set("exits", ([
"south" : __DIR__"menqian",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/xilou" : 1,
	]));

	setup();
	replace_program(ROOM);
}
