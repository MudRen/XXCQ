// caifang.c ��
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","��");
        set("long",
"�����ǻ����Ĳ񷿣����￴��ȥҪ�ȱ��˵Ĳ񷿸ɾ����ˣ���������
���ζ����ĵ��Ӿ����������æ��Ե�ʡ����������һ�Ѳ񣬲��º�����
ʲô������\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"west" : __DIR__"chanting",
                "east" : __DIR__"liangcang",
	]));
	set("book_count",1);
     set("chai_moved",1);
	setup();
}

void init()
{
	add_action("do_move","move");
	add_action("do_pull","pull");
}

int do_move(string arg)
{
	object ob=this_player();
	object where=environment(ob);
	if (arg!="��") return 0;
    if (!where->query("chai_moved"))
                return notify_fail("���Ѿ����ƿ��ˡ�\n");
    set("chai_moved",0);
        return notify_fail("�����ƿ���,������һ�����塣\n");
}

int do_pull(string arg)
{
	object ob,me=this_player();
       object where;
        where=environment(me);
	if (arg!="����") return 0;
    if( where->query("chai_moved") )
                return notify_fail("����Χû���ⶫ����\n");
        if((int)me->query_str()<22)
        	return notify_fail("������̫С,û���������塣\n");
        message_vision("$Nʹ�����̵���������������������\n",me);
        if (!(where->query("book_count")))
              return notify_fail("����ʲô��û�С�\n");
        ob=new(__DIR__"obj/sword-book");
        ob->move(me);
        message_vision(HIG"$N������һ���飡\n"NOR,me);
        where->set("book_count",0);
        return 1;
}

	
