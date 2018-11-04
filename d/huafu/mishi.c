// mishi.c ����
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"����һ�����ң�����ܰ��������м����һ�����ӣ�����һ��ҹ����
��ɢ������͵Ĺ�â��ʹ������ϡ������Χ��һ�У�ǽ�Ϲ���һ��ɽˮ��
��hua����ǽ����һ����ܣ���ܣ�shelf���Ϸ���һЩ�飨book����\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"out" : __DIR__"woshi",
	]));
         set("item_desc",([
		"shelf" : "������һ�����Ƶ��顣\n",
          ]));
	set("book_count",1);
	setup();
}

void init()
{
	add_action("do_get","get");
	add_action("do_search","search");
	add_action("do_si","si");
}

int do_get(string arg)
{
	object ob,me=this_player();
	object where=environment(me);
	if (arg!="book from shelf") return 0;
	if (!where->query("book_count"))
		return notify_fail("���Ѿ����������ˡ�\n");
	ob=new(__DIR__"obj/fake-book");
	ob->move(me);
	message_vision("$N����һ���顣\n",me);
	set("book_count",0);
	return 1;
}

int do_search(string arg)
{
	object me=this_player();
	if (arg!="hua" && arg!="��") return 0;
	message_vision("$N���ֻ��мв㡣\n",me);
	me->set_temp("marks/search",1);
	return 1;
}

int do_si(string arg)
{
	object ob,me=this_player();
	if (arg!="hua" && arg!="��") return 0;
	if (!me->query_temp("marks/search"))
		return notify_fail("�����ɶ?\n");
          if (query("books"))
		return notify_fail("����տ���Ҳ��\n");
        ob=new(__DIR__"obj/real-book");
        ob->move(me);
        message_vision("$N�ѻ��𿪣�������һ�����Ƶ��顣\n",me);
             set("books",1);
        return 1;
}


