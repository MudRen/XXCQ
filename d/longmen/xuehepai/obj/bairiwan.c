
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
        set_name(HIB"����ʮ����"NOR, ({"bairi wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�˵�ͨ����ҩ�����������߹������Ե��ޱȡ�\n");
                set("value", 10000);
                set("no_drop",1);
        }
        setup();
}

int do_eat(string arg)
{
        int neili,neili_limit;

        object me = this_player();

        if (arg!="��" || arg!="wan")
                return notify_fail("��Ҫ��ʲô��\n");

        if( me->is_busy() )
                return notify_fail("�𼱣������ԣ������ˡ�\n");

        me->start_busy(2);
        me->set_temp("neili_save",(int)me->query("max_neili"));
        message_vision(HIG "$N����һ�Ű���ʮ���裬ֻ���������ޱȡ�\n" NOR, me);
        

        me->apply_condition("bairi-du", 100);
        
        destruct(this_object());
        return 1;
}

