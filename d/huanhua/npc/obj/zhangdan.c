#include <ansi.h>
inherit ITEM;
int do_songdan(string arg);
void create()
{
        set_name(RED"�ʵ�"NOR, ({ "zhang dan", "zhangdan" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���Ǹ�ĳ�˵�һ���ʵ���(give  xxx)\n");
                set("value", 100);
                set("material", "steel");
        }
        setup();
}
void init()
{
        add_action("do_songdan","give");
}
int do_songdan(string arg)
{
        object who,me,where;
        int exp,exp1,pot,pot1;
        exp=80+random(50);
        exp1=350+random(100);
        pot=30+random(30);
        pot1=150+random(60);
        me=this_player();
        where = environment(me);
        if(!arg||arg=="")
        return notify_fail("��Ҫ���ܺ���˭��\n");
        if(!objectp(who = present(arg, environment(me))) || !living(who))
        return notify_fail("����û������ˡ�\n");
        if(who->query("name")!=this_object()->query("human"))
        return notify_fail("������Ų����͸����ġ�\n");
        if (file_name(where)!=this_object()->query("where"))
        return notify_fail("�������̫�����ˣ������͵����͵ĵط�ȥ�ɡ�\n");
        if (!me->query_temp("do_job2"))
        {
                message_vision(HIW"$N���ܺ����������Ľ�����$n��\n"NOR,me,who);
                message_vision(HIR"$n���˿��ܺ���ͻȻ��$N���һ�������㾹Ȼ�Ҽ�ð�ܺ����������ɣ���\n"NOR,me,who);
                who->kill_ob(me);
                destruct(this_object());
                return 1;
        }       
        if(me->query_temp("jiefei_1"))
        {
                message_vision(CYN"$N��"+RED+"�ʵ�"+CYN+"���������Ľ�����$n�� \n"NOR,me,who);
                me->add("combat_exp",exp1);
                me->add("potential",pot1);
                me->delete_temp("do_job2");
                me->delete_temp("jiefei_1");
                me->apply_condition("do_songdan", 0);
                destruct(this_object());
                return 1;
        }
        message_vision(CYN"$N��"+RED+"�ʵ�"+CYN+"���������Ľ�����$n�� \n"NOR,me,who);
        me->delete_temp("do_job2");
        me->start_busy(3);        
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->apply_condition("do_songdan", 8);
        destruct(this_object());
        return 1;
}         

