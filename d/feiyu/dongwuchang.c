// Room: dongwuchang.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 

inherit ROOM;

void init();
int do_da(string);
int do_ci(string);

void create ()
{
        set ("short", "�����䳡");
        set ("long", @LONG
����һ�����Ķ����䳡����Χ����һЩɳ����ľ�ˣ������һ��ľ
��ҡҡ�λεĹ���ľ���ϣ�������ðѽ�ȥ��(ci)�����ұ��и���ɳ����
���������һȭ��(da)��ȥ�����Ա������������Ÿ�ʽ���������ڱ�����
һ��С���ӣ����Ǹ��������������߾��Ƕ�Ժ�ˡ����ϵ���һ��С·��
һֱͨ��Ϫ�ߡ�
LONG);
        set("area","����");
        set("valid_startroom", 1);
       
        set("objects", ([
                __DIR__"npc/feiyudizi" : 1,
        ]));

        set("exits", ([
                "west" : __DIR__"qianting",
                "east" : __DIR__"eroad",
                "north" : __DIR__"bingqifang",
                "south" : __DIR__"xiaojing1",
        ]));

        setup();
}

void init()
{
        add_action("do_da", "da");
        add_action("do_ci", "ci");
}

int do_da(string arg)
{
        object me;
        int jingli_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "shabao" ) )
                return notify_fail("�����ʲô��\n");

        jingli_cost = (-1) * random(15);
        qi_cost = (-1) * random(15);

        me->add("jingli", jingli_cost);
        me->add("qi", qi_cost);

        if ( me->query("jingli") <= (- jingli_cost) || me->query("qi") <= (-qi_cost) )
                return notify_fail("��̫ƣ���ˣ�û�о���ȥ�����ˡ�\n");

        message_vision("$N�ںü��ƣ�һȭ��ɳ����ȥ��\n", me);

        if ( me->query_skill("parry", 1) < 5 )  
        {
                message_vision("$N��������񶷣�����ֶ����ˡ�\n", me);
   		
        } else if ( me->query_skill("parry", 1) < 20 )
        {
                message_vision("$N��ɳ����û�����ȥ��\n", me);
        } else 
        {
                message_vision("�Ե�һ����ɳ����$N��÷���������\n", me);
        }
 
        if ( me->query_skill("parry", 1) < 30)
        {
                me->improve_skill("parry", me->query("int"));
                me->set_temp("hitted",1);
        }
        if ( me->query_skill("parry",1) >= 30 )
        { 
                write("��һ�¾Ͱ�ɳ�����ˣ���ɳ������ûʲô�����ˣ�\n");
        }
        return 1;
}

int do_ci(string arg)
{
        object me;
        int jingli_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "muren" ) )
                return notify_fail("�����ʲô��\n");

        jingli_cost = (-1) * random(15);
        qi_cost = (-1) * random(15);

        me->add("jingli", jingli_cost);
        me->add("qi", qi_cost);

        if ( me->query("jingli") <= (- jingli_cost) || me->query("qi") <= (-qi_cost) )
                return notify_fail("��̫ƣ���ˣ�û�о���ȥ�����ˡ�\n");

        message_vision("$N���������һ����ľ�˴�ȥ��\n", me);

        if ( me->query_skill("sword", 1) < 5 )  
        {
                message_vision("$N�������ὣ��������ľ��ֻ��������һ�¡�\n", me);
   		
        } else if ( me->query_skill("sword", 1) < 20 )
        {
                message_vision("$N��׼ľ�˵��ƶ���һ������ľ�˵�ҪѨ�ϡ�\n", me);
        } else 
        {
                message_vision("$N����һ�����Ѿ�����ľ�˵�Ҫ���ˡ�\n", me);
        }
 
        if ( me->query_skill("sword", 1) < 30)
        {
                me->improve_skill("sword", me->query("int"));
                me->set_temp("hitted",1);
        }
        if ( me->query_skill("sword",1)>= 30 )
        { 
                write("��һ�¾Ͱ�ľ�˴̵��ˣ�������ľ�˶���ûʲô�����ˣ�\n");
        }
        return 1;
}
