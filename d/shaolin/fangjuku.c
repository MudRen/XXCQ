// Room: /d/shaolin/fangjuku.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���߿�");
	set("long", @LONG
����һ��ܴ�ķ��䣬��ǽ����ط���һ��������ӣ����ٹ����ų�
���ţ�¶������ĸ��ַ��ߣ�Ʒ��֮�࣬������ƽ������һλ����ɮ����
��ͷ����һ������Ļ��ߡ��������Ҳû��ע�⡣
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"yaopinku",
		"south" : __DIR__"wuqiku",
	]));

	set("objects",([
		__DIR__"obj/tiebeixin" : 1,
		__DIR__"obj/tiehuwan" : 1,
		__DIR__"obj/tiezhitao" : 1,
	]));

	setup();

	replace_program(ROOM);
}

