// Room: donglianwuchang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.10
// �޸��书���ࡣ
// 

inherit ROOM;

void init();
int do_da(string);

void create ()
{
        set ("short", "�����䳡");
        set ("long", @LONG
����һ����������㳡���㳡��Χ����һЩ�����ܣ�����
���������Ÿ�ʽ���������ڱ�����һ��С���ӣ���ʱ����������
������ѧ�á�������һ��ľ�ˣ��������(da)����
LONG);
        set("area","����");
	set("valid_startroom", 1);
        set("outdoors", "wenjia");

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 2,
        ]));

        set("exits", ([
                "west" : __DIR__"dongzoulang",
                "east" : __DIR__"xuetang",
                "north" : __DIR__"bingqifang",
        ]));
        setup();
}

void init()
{
        add_action("do_da", "da");
}

int do_da(string arg)
{
        object me;
        int jingli_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "muren" ) )
                return notify_fail("�����ʲô��\n");

        jingli_cost = (-1) * random(20);
        qi_cost = (-1) * random(20);

        me->add("jingli", jingli_cost);
        me->add("qi", qi_cost);

        message_vision("$N�ںü��ƣ���ľ�˴�ȥ��\n", me);

        if ( (int)me->query_skill("atrike", 1) < 10 )  
        {
                message_vision("���$N�����ִ��ʮ���ۡ�\n", me);
   		
        } else if ( (int)me->query_skill("strike", 1) < 20 )
        {
                message_vision("$N�����ֲ���ôʹ�ˡ�\n", me);
        } else 
        {
                message_vision("$N���þ����С��һ�������ף�\n", me);
        }
 
        if ( (int)me->query_skill("strike", 1) < 30)
        {
                me->improve_skill("strike", me->query("int"));
                me->set_temp("hitted",1);
        }
        if ( !me->query_temp("hitted") )
        { 
                write("����ô�ľ�˶��Լ�ûʲô�����ˣ�\n");
        }
        return 1;
}