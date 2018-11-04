// woshi.c ����
// mlf ���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"�����ǻ��ݷ������ң���ֵ������ҵİ���ʮ�ּ򵥣�ֻ��һ������
���������Ӻ�һ�Ŵ������ϵ�"HIY"����"NOR"Ҳû�����ͷ��������Ȼ����ȥ�ܺ�
�ᣬ���Ǻܸɾ���\n"
	);
	set("valid_startroom",1);
	set("item_desc",([
		"��" : "���ϳ��˱��Ӿ�ʣһ��"HIW"��ͷ"NOR"�ˡ�\n",
	]));
	setup();
}

void init()
{
	add_action("do_pull","pull");
	add_action("do_zhuan","zhuan");
	add_action("do_open","open");
	add_action("do_enter","enter");
}

int do_pull(string arg)
{
	object me=this_player();
          if (arg!="beizi") return 0;
	if (me->query_temp("marks/pull"))
                return notify_fail("�����Ѿ����㷭�����߰��㡣\n");
	me->set_temp("marks/pull", 1);
        message_vision("���ӱ�$N��������,$NʲôҲû���֡�\n",me);
	return 1;
}

int do_zhuan(string arg)
{
     object me=this_player();
          if (arg!="zhentou") return 0;
	if( !me->query_temp("marks/pull") )
                return notify_fail("�����ɶ��\n");
	message_vision("$NͻȻ����һ������,ǽ�ϳ�����һ����(enter)��\n",me);
	set("zhuan",1);
	return 1;
}

int do_enter(object me)
{
	object room;
	object where;
        me=this_player();
	where=environment(me);
	if(!where->query("zhuan"))
          return notify_fail("��Ҫ����ȥ��\n");
	if(!( room = find_object(__DIR__"mishi")) )
          room = load_object(__DIR__"mishi");
	message_vision("$N�����һ�����š�\n",me);
        me->move(room);
	set("zhuan",0);
        return 1;
}

int do_open(string arg)
{
	object room;

	if (query("exits/west"))
		return notify_fail("�������Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "door" && arg != "west"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"neitang")) )
		room = load_object(__DIR__"neitang");
	if(objectp(room))
	{
		set("exits/west", __DIR__"neitang");
		message_vision("$Nʹ���������Ŵ��˿�����\n",this_player());
		room->set("exits/east", __FILE__);
		message("vision","�������˰������Ŵ��ˡ�\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"neitang")) )
		room = load_object(__DIR__"neitang");
	if(objectp(room))
	{
		delete("exits/west");
		message("vision","ֻ��ƹ��һ�����������Զ�����������\n",this_object());
                message("vision","���ˣ�����ȥ�ˣ�\n" ,
			this_object());
		room->delete("exits/east");
		message("vision","ֻ��ƹ��һ�����������Զ�����������\n",room);
                message("vision","��Ӵ���ֽ���ȥ�ˣ�\n" ,
			room );
	}
}
