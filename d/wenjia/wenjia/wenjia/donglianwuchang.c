// Room: donglianwuchang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;

void init();
int do_da(string);

void create ()
{
        set ("short", "�����䳡");
        set ("long", @LONG
����һ����������㳡���㳡��Χ����һЩ�����ܣ�������������
�Ÿ�ʽ���������ڱ�����һ��С���ӣ���ʱ����������������ѧ�á�����
��һ������ҡҡ�λεĹ���ľ���ϣ�������ð�ɳ�Ӷ�(diu)����
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
                "south" : __DIR__"guanjiafang",
        ]));

        setup();
}

void init()
{
        add_action("do_da", "diu");
}

int do_da(string arg)
{
        object me;
        int jingli_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "jiaren" ) )
                return notify_fail("�����ʲô��\n");

        jingli_cost = (-1) * random(20);
        qi_cost = (-1) * random(20);

        me->add("jingli", jingli_cost);
        me->add("qi", qi_cost);

        if ( me->query("jingli") <= (- jingli_cost) || me->query("qi") <= (-qi_cost) )
                return notify_fail("��̫ƣ���ˣ�û�о��������ˡ�\n");

        message_vision("$N�ںü��ƣ�ץ��һ��ɳ������˶�ȥ��\n", me);

        if ( me->query_skill("lphand", 1) < 10 )  
        {
                message_vision("���$N����ɳ��һ��Ҳû���м��ˡ�\n", me);
   		
        } else if ( me->query_skill("lphand", 1) < 20 )
        {
                message_vision("$N����ɳ����һ�붪�м��ˡ�\n", me);
        } else 
        {
                message_vision("Bingo!$N����ɳ��ȫ�м��ˡ�\n", me);
        }
 
        if ( me->query_skill("lphand", 1) < 30)
        {
                me->improve_skill("unarmed", me->query("int"));
                me->set_temp("hitted",1);
        }
        if ( !me->query_temp("hitted") )
        { 
                write("��������ڶ�ɳ�Ӷ��Լ�ûʲô�����ˣ�\n");
        }
        return 1;
}