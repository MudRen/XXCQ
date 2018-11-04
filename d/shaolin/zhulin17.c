// Room: /city/milin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬï�ܵ������֣����������Ѿ�û��·�ˣ�ֻ����Χ��������
�����֮����������������ͷ��һ�߽�������·���ʧ�˷�����˵��Ƭ
������ͨ�����ʯ�ıؾ�֮·��
LONG );
	set("exits", ([
		"east" : __DIR__"zhulin14",
		"west" : __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
	]));
        set("objects",([
                "/kungfu/class/shaolin/baocan" : 1,
                "/kungfu/class/shaolin/baoyue" : 1,
                "/kungfu/class/shaolin/baohua" : 1,
                "/kungfu/class/shaolin/baoxue" : 1,
                "/kungfu/class/shaolin/baofeng" : 1,
        ]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}
