//yaotian5

#include <ansi.h>
inherit ROOM;

int do_zhao(string arg);

void create ()
{
        set ("short", "ҩ��");
        set ("long", @LONG
���������Ŷ�ҩ����ҩ�ԡ�����Ŀ�����Ʈ����һ�����㣬�ŵ�
������ζ����ֻ����ͷ��һЩ���裬����ҩ���ǸϿ��뿪�ɡ�
LONG);
        set("area","����");
        set("outdoors", "tangmen");
        set("exits", ([
                "west" : __DIR__"yaotian4",
                "south" : __DIR__"yaotian2",
                "east" : __DIR__"yaotian6",
        ]));
        set("yao", 5);
        setup();
}

void init()
{
	add_action("do_zhao","zhao");
}

int do_zhao(string arg)
{
        object me;
        int jingli_cost;

        me = this_player();
        jingli_cost = (-1) * (5 + random(15));

        if ( !arg || ( arg != "yao" ) )
                return notify_fail("�����ʲô��\n");

        if ( me->query_temp("find") )
                return notify_fail("���Ѿ��ҵ���һ���ҩ�����Խ����ˣ�\n");

	if ( me->query("jingli") <= ( - jingli_cost ) )
		return notify_fail("��̫ƣ���ˣ�û�о�������ҩ�ˡ�\n");

	if ( (int)query("yao") >= 1 )
        {
		message_vision(YEL"$N����������С��������ڻ�����Ѱ����ҩ�ݡ�\n"NOR, me);
		if ( random(1 + me->query("kar") - 10 ) >= 3 )
		{
			message_vision(HIG"$N���ϵĲ����Ż����еĲ�ҩ�������ҵ���һ�ꡣ\n$N������ҩ��С�ĵ����ڻ��С�\n"NOR, me);
			new(__DIR__"obj/caoyao")->move(me);
			me->set_temp("find",1);
		}

	        me->add("jingli", jingli_cost);
		add("yao",-1);
        }
	else
                return notify_fail("���ﶼ�Ѿ��������ˣ�û��ʲô���ҵ��ˡ�\n");

        return 1;
}