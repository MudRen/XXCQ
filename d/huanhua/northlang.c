// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����Ľ�®�����಻�ϵĻ������ӵģ��������ڵı�����ȵ�����
�ֱ��ǻ�̳�ͱ���Ժ�������Ż���������ͨ��ƺ�С�����߻��ȵȵط���
��ʱ��佻������߹����
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"qianroad2",
		"north" : __DIR__"northyuan",
		"west" : __DIR__"northlang_2",
	]));

        set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}