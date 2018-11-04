// NPC: wenkongzi.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.4.3
// Modified Study
// 

#include ansi.h

inherit NPC;

void greeting(object);
void init();
int do_wen(string);

void create()
{
        set_name("�¿���", ({ "wen kongzi", "kongzi", "wen"}) );
        set("gender", "����" );
        set("age", 30+random(10));
        set("long",
                "�¿������¼�������īˮ�����ˡ�\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("rank_info/respect", "��ʦ");

        set("qi", 200);
        set("max_qi", 200);
        set("jingli", 300);
        set("max_jingli", 300);

        set_skill("literate", 300);

        add_money("silver", 10);

        setup();
}

void init()
{	
        object ob;

        ::init();
        add_action("do_wen","xue");

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        say("�¿��ӿ������˽������������е��飬˵��������λ" + RANK_D->query_respect(ob)
             + "�ǵ���������ѧϰ���𣿡�\n");
}

int do_wen(string arg)
{
        object me;
        int jingli_cost,qi_cost,pot;

        me = this_player();

        if ( !arg || ( arg != "literate" ) )
              return notify_fail("�����ʲô��\n");

        jingli_cost = (-1) * random(5);
        qi_cost = (-1) * random(5);
        pot = me->query("potential") - me->query("learned_points");

        if (pot<=0) return notify_fail("��û��Ǳ���ˣ���ôѧϰ�����\n");

        if (me->is_fighting()) return notify_fail("������ս������ôѧϰ�����\n");

        if ( me->query("jingli")+jingli_cost0 || me->query("qi")+qi_cost<0)
        return notify_fail("�������̫���ˣ���Ҫѧ�ˡ�\n");

        if ( me->query_skill("literate",1) >= 300 ) 

               return notify_fail("�¿��Ӷ�$N˵�����������ѧ�ʱ��һ��ḻ�ˡ��߰�!\n");

        me->add("jingli", jingli_cost);
        me->add("qi", qi_cost);
        me->add("learned_points", 1);

        message_vision("$N���¿������ѧ�ʡ�\n", me);
        me->improve_skill("literate", me->query("int")*200+me->query_skill("literate",1)/10);
        return 1;
}
