// dongxiangfang.c ���᷿
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","���᷿");
        set("long",
"����Ҳ�ǻ������ʷ����ڣ�����ÿ��Ǯ�Ƴ������Ŀ�����������
������һЩ��ɫ�Ĺ��ӣ���֪����Щʲô��������table���϶���Сɽһ
�����ʲ����ܼ���һ������æµ��д��ʲô�� ���ζ����ĵ��ӿ���������
�쵽��ͬ��нˮ������\n"
	);
	set("exits",([
		"north" : __DIR__"dongting",
	]));
	set("item_desc", ([
		"table" : "�������ҵĶ����ʲ���\n",
	]));
	set("objects",([
		__DIR__"npc/tang" : 1,
	]));
	set("valid_startroom",1);
	set("book_count",1);
	setup();
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object ob, me= this_player();
	object where=environment(me);
	if (arg!="zhang bu" && arg!="bu") return 0;
	if (!where->query("book_count"))
		return notify_fail("�ʲ��Ѿ����˷������߰��㡣\n");
	ob = new(__DIR__"obj/strike-book");
	ob->move(where);
	message_vision("ֻ������ž����һ����һ�������������\n",me);
	set("book_count",0);
	return 1;
}
		
	
