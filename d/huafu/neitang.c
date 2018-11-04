// neitang.c ����
// mlf ���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"�����ǻ������ã�����ֻ�����˵����Ѻ����ŵ��Ӳ������ڡ������
����ȱ�ĵط�����������λ���������н�˿����Ŀ��棬����������
����һ�������"HIB"������"NOR"��ʯ��ֽ�Լ��ķ��ı��������������ǻ��ݷ�����
�ҡ����������ŵġ�\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"south" : __DIR__"zoulang1",
	]));
	set("objects",([
		__DIR__"npc/huakufa" : 1,
	]));
	set("item_desc",([
		"door" : "���ǹ��ŵģ�������һ��Կ�׿ס�\n",
	]));
	set("pen_moved",1);
	setup();
}

void init()
{
	add_action("do_move","move");
	add_action("do_unlock","unlock");
}

int do_move(string arg)
{
	object ob,me=this_player();
	object where=environment(me);
	if (arg!="pen") return 0;
	if (!where->query("pen_moved"))
		return notify_fail("�����Ѿ����ƶ��ˡ�\n");
          if (ob = present("bedroomkey", this_player()))
		return notify_fail("�����ɶ��\n");
	ob=new(__DIR__"obj/key");
	ob->move(me);
	message_vision(HIG"$N�ƿ�����,����һ��Կ�ס�\n"NOR,me);
	me->set_temp("doorisok",1);
	set("pen_moved",0);
	return 1;
}

int do_unlock(string arg)
{
	object ob,room;
	if (query("exits/east"))
		return notify_fail("���Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "door"))
		return notify_fail("��Ҫ��ʲô��\n");
     if (!(ob = present("bedroomkey", this_player())))
		return notify_fail("�㲻��������\n");
	message_vision(
	"$N��һ��Կ�״��������ţ�����Կ��ȴ����.\n", this_player());
	destruct(ob);
	if (this_player()->query_temp("doorisok"))        
        {
	set("exits/east", __DIR__"woshi");
	if(!( room = find_object(__DIR__"woshi")) )
        room = load_object(__DIR__"woshi");
	if(objectp(room))
    	{
        set("exits/east", __DIR__"woshi");
        message_vision("$N��������ţ�ֻ��֨��һ�����ſ��ˡ�\n",this_player());
        room->set("exits/west", __FILE__);
        message("vision","ֻ��֨��һ���������Ŵ�������ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
    	}
        this_player()->set_temp("doorisok",0);
        } 
	return 1;
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"woshi")) )
        room = load_object(__DIR__"woshi");
    if(objectp(room))
    {
        delete("exits/east");
        message("vision","ֻ��ƹ��һ�����������Զ������ˡ�\n",
            this_object());
        message("vision","��Ӵ���ֽ���ȥ�ˣ�\n" ,
			this_object());
        room->delete("exits/west");
        message("vision","ֻ��ƹ��һ�����������Զ�����������\n", room);
        message("vision","���ˣ�����ȥ�ˣ�\n" ,
			room );
     }
	return 1;
}
