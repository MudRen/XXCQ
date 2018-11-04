//canting               ����Ѫ����--����

#include <ansi.h>
#include <room.h>
inherit ROOM;
int delete_busy();

void create()
{
           set("short","����");
	set("long", @LONG
������Ѫ���ɵķ����������Ƹ������һ�������˱Ƕ������������
�������������ʡ�ƽʱ���������Ⱥ���˽��ͣ��߳Ա������ڵ������Լ�
�����ϵĶ���ԹԹ��������ˣ��������ʦ���(serve)��
LONG);
	set("valid_startroom",1);
	set("exits", ([
        	"west" : __DIR__"qingyunge",
                  "north" : __DIR__"wuqifang",
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
	if(query("busy"))
		return notify_fail("�Բ����������æ������΢��һ�°ɣ�\n");
	set("busy",1);
	call_out("delete_busy",5);
	ob = this_player();
        food=new(__DIR__"obj/niqiu");
        water=new(__DIR__"obj/longjing");

        if( (present("niqiu", ob)) && (present("longjing cha", ob)) )
	{
               message_vision(HIC "��ʦ����$N����ţ����ȳ�������Ҫ����\n" NOR, ob);
		delete_busy();
		return 1;
	}
	else
	{
                if ( (present("niqiu", ob)) )
		{
                        message_vision(HIC "��ʦ��һ�����������$N��ǰ����������ţ����гԵĻ�Ҫ������\n" NOR, ob);
		        water->move(ob);
			return 1;
		};
                if ( (present("longjing cha", ob)) )
		{
                        message_vision(HIC "��ʦ��һ��������������$N��ǰ����������ţ����кȵĻ�Ҫ������\n" NOR, ob);
		        food->move(ob);
			return 1;
		}
		else
		{
                        message_vision(HIC "��ʦ��һ������������һ�����������$N��ǰ��\n" NOR, ob);
		        food->move(ob);
        		water->move(ob);
			return 1;
		}

	}
}

int delete_busy()
{
	delete("busy");
}
