//chufang.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������źС���еĳ����������а����ߡ��������ӣ�һЩ����
����Χ��������һ�߿���������һ��̸���Ž����ϵ�һЩ����ԹԹ��
��Ӧ�ÿ������ʦ���(serve)��
LONG);
	set("exits", ([
			"south" : __DIR__"nzlangn3",
	]));
	set("no_fight", 1);
	set("area", "����");
	setup();
}
void init()
{
	add_action("do_serve","serve");
}

int do_serve()
{
	object ob, food, water;
	ob = this_player();
        food=new(__DIR__"obj/jiangnr");
        water=new(__DIR__"obj/donggt");

 	if( (present("rou", ob)) && (present("tang", ob)) )
	{
		message_vision(HIC "\n��ʦ���������ţ����ȳ�������Ҫ��\n" NOR, ob);
		return 1;
	}
	else
	{
		if ( (present("rou", ob)) )
		{
			message_vision(HIC "\n��ʦ��һ�붬��������$N��ǰ����������ţ����гԵĻ�Ҫ������\n" NOR, ob);
		        water->move(ob);
			return 1;
		};
		if ( (present("tang", ob)) )
		{
			message_vision(HIC "\n��ʦ��һ�̽�ţ�����$N��ǰ����������ţ����кȵĻ�Ҫ������\n" NOR, ob);
		        food->move(ob);
			return 1;
		}
		else
		{
			message_vision(HIC "\n��ʦ��һ�̽�ţ�⡢һ�붬��������$N��ǰ��\n" NOR, ob);
		        food->move(ob);
        		water->move(ob);
			return 1;
		}

	}
}