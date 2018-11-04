// Room: xilianwuchang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// Modified Long and Checked Bugs
// 
inherit ROOM;

void init();
int do_yue(string);

void create ()
{
        set ("short", "�����䳡");
        set ("long", @LONG
����һ����������㳡���㳡��Χ����һЩ�����ܣ�����
���������Ÿ�ʽ�����������������ȣ�������һ���ּ�С���ɡ�
����ǰ��һ��ɳ�أ����Ƿ����(yue)��ȥ��
LONG);
        set("area","����");
	set("valid_startroom", 1);
        set("outdoors", "wenjia");

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 2,
        ]));

        set("exits", ([
                "east" : __DIR__"xizoulang",
                "north" : __DIR__"xiaojing",
        ]));
        setup();

}

void init()
{
        add_action("do_yue", "yue");
}

int do_yue(string arg)
{
        object me;
        int jingli_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "shachi" ) )
                return notify_fail("�����ʲô��\n");

        jingli_cost = (-1) * random(20);
        qi_cost = (-1) * random(20);

        me->add("jingli", jingli_cost);
        me->add("qi", qi_cost);

        message_vision("$N��һ������������һ�ᣬ˫���뿪���档\n", me);

        if ( (int)me->query_skill("dodge", 1) < 10 )  
        {
                message_vision("�����ž����һ��$N��ɳ�ض���ˤ���ˡ�\n", me);
        } else if ( (int)me->query_skill("dodge", 1) < 20 )
        {
                message_vision("$Nҡҡ�λε�����ɳ�ض��棬���ˤ����\n", me);
        } else 
        {
                message_vision("$N��һ����������������ɳ�ض��棡\n", me);
        }
 
        if ( (int)me->query_skill("dodge", 1) < 30)
        {
                me->improve_skill("dodge", me->query("int"));
                me->set_temp("jumped",1);
        }
        if ( !me->query_temp("jumped") )
        { 
                write("����÷ǳ����׵ľ�������ɳ�أ����Լ�ûʲô���ðɣ�\n");
        }
        return 1;
}