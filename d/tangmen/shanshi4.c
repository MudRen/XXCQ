//shanshi4


#include <ansi.h>
inherit ROOM;

int do_qiao(string arg);

void create ()
{
        set ("short", "ɽ��");
        set ("long", @LONG
�����Ǻ�ɽһ���谵��ɽ����ɽ���������Ѳ���ղ���ô��ľ��
ï�������ǹ�ͺͺ��û��һ��ֲ������ɽʯ����������ĳ��ɫ
���󣬲�֪�봦���ʯͷ��ʲô��ͬ��������Ʈ��һ����������ζ��
�����ж���Ǳ���ڸ������뿪����ɡ�
LONG);
        set("area","����");
        set("outdoors", "tangmen");
        set("exits", ([
                "northup" : __DIR__"shanshi3",
                "southwest" : __DIR__"shanshi5",
        ]));
        set("shi", 5);
        setup();
}

void init()
{
	add_action("do_qiao","qiao");
}

int do_qiao(string arg)
{
        object me, enemy;
        int jingli_cost;

        me = this_player();
        jingli_cost = (-1) * (10 + random(15));

        if ( !arg || ( arg != "shi" ) )
                return notify_fail("�����ʲô��\n");

        if ( me->query_temp("find") )
                return notify_fail("���Ѿ��ҵ�һ�龫����ʯ�ˣ�û�������ٴ�һ�飡\n");

	if ( me->query("jingli") <= ( - jingli_cost ) )
		return notify_fail("��̫ƣ���ˣ�û�о����ټ��������ˡ�\n");

	if ( (int)query("shi") >= 1 )
        {
		message_vision(YEL"$N�������е��������ص����ڵ��Ե�ɽʯ�ϡ�\n"NOR, me);
		if ( random(1 + me->query("kar") - 10 ) >= 3 )
		{
			message_vision(HIG"$N����ɽʯ�������������������ڸ�����������һ��飡\n$N��ͷ��Ҫ�����ʯ��ͻȻһֻ��Ы��ʯ�����˳�����\n"NOR, me);
			enemy = new(__DIR__"npc/xiezi");
			enemy->move(this_object());
			new(__DIR__"obj/kuangshi")->move(this_object());
			enemy->kill_ob(me);
			me->fight_ob(enemy);
			me->set_temp("find",1);
		}

	        me->add("jingli", jingli_cost);
		add("shi",-1);
        }
	else
                return notify_fail("ɽ���ߵ�ɽʯ���������ˣ�û�п����õ��ˡ�\n");

        return 1;
}

int valid_leave(object me, string dir)
{
	object ob;
	int true;
	if ( objectp( present("duxie", environment(me))) )
	{
		ob = present("duxie", environment(me));
		true = 1;
	}
	else 
		true = 0;
	if ( ( (dir == "southwest") || (dir == "northup") ) && objectp( present("kuang shi", me))  && true && living(ob))
		return notify_fail("��Ы��ס�����뿪�ĵ�·������ֻ��ɱ�����������ˣ�\n");
	else
		return ::valid_leave(me, dir);
}