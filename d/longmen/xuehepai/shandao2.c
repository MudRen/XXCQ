//shandao1��c      by baby


#include <ansi.h>
int do_qiao(string arg);
inherit ROOM;

int do_qiao(string arg);

void create ()
{
        set ("short", "ɽ��");
        set ("long", @LONG
�����Ǻ�ɽһ���谵��ɽ����ɽ�����������ǹ�ͺͺ��û��һ��ֲ��
�����ɽʯ����������ĳ��ɫ����֪���봦���ʯͷ��ʲô��ͬ������
�ж���Ͷ���Ǳ���ڸ������뿪����ɡ�
LONG);
        set("valid_startroom", 1);
        set("outdoors", "����");
        set("exits", ([
		"south" : __DIR__"shandao1",
		"north" : __DIR__"shandao3",
        ]));
        set("shi",500);
        setup();
}

void init()
{
        add_action("do_qiao","knock");
}

int do_qiao(string arg)
{
        object me;
        object weapon;
        int jingli_cost;

        me = this_player();
        weapon=me->query_temp("weapon");
       jingli_cost = (-1) * (10 + random(10));

        if ( !arg || ( arg != "shi" ) )
                return notify_fail("�����ʲô��\n");

        if ( !(me->query_temp("job_start")))
                return notify_fail("��û����������ʲôѽ��\n");
        
        if (!weapon || (weapon->query("id")!="hammer"))
                return notify_fail("������û���������ѵ����֣�\n");

        if ( me->query_temp("find") )
                return notify_fail("���Ѿ��ҵ�һ���ʯ�ˣ�û�������ٴ�һ�飡\n");
        
          if ( me->query("qi") <= ( - jingli_cost ) )
                return notify_fail("��̫ƣ���ˣ�û�о����ټ��������ˡ�\n");

         if (me->is_busy())
                   return notify_fail("����æ���ء�\n");
        if ( (int)query("shi") >= 1 )
        {
                message_vision(YEL"$N�������е��������ص����ڵ��Ե�ɽʯ�ϡ�\n"NOR, me);
                if ( random(15)<4 )
                {
                        message_vision(HIG"$N����ɽʯ�������������������ڸ�$N��������һ��飡\n"NOR, me);
                        new("/kungfu/class/xuehepai/obj/shi")->move(me);
                        me->set_temp("find",1);
                }
                me->add("qi", jingli_cost);
                add("shi",-1);
                me->start_busy(2);
        }
        else
                return notify_fail("ɽ���ߵ�ɽʯ���������ˣ�û�п����õ��ˡ�\n");

        return 1;
}

