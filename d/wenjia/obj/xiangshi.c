// Item xiangshi.c
// Created by Zeus 1999.4.3
// Modified by Zeus 1999.4.17
// δд�����е������
// 

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_fang", "diu");
}

void create()
{
        set_name("��ʶ������", ({"xiang shi"}));

        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��СС���޻���һ��Ҳ����������������ʿ��֮ɫ����¼���������ʶ�����С���\n");
                set("value", 10000000);
        }
        init_blade(100);
        setup();
}

int do_fang(string arg)
{
        object me, obj;
        me = this_player();

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");
 
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if(obj == me)
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

//      message_vision(HIY "\n    $N˵������֪����������--���ǽ���Ÿո���ʶ��ȴ���Ѿ���\n"+
//              "������ֻ��Ե��ʶ�������粨��Ҳ���ն࣬�������²�����ʶ\n"+
//              "����ν�ǡ���ʶ�����С���......��\n"NOR, me);

//      message_vision(HIY "\n    ����ϧ֪�������ף�Ҳû���ã����ǲ��ò�����--������ֹ��\n"+
//              "ʶ�����У�����ʶ�ڡ����ꡯ���ģ���\n"NOR, me);

        message_vision(HIY "\n    ͻȻ����$NСС���������һ�\n"+
                "    ����Ѹ�ٱ��͡�\n"+
                "    ˵Ҳ�������ţ�ԭ�ȣ�����ֻ��һ���޻���\n"+
                "    СС�ģ�����ģ����ɵģ��һҵġ���$N�Ŀ������Ư��\n"+
                "�˳�����\n"+
                "    Ҳ��Ʈ���˳�����\n"+
                "    ����Ѹ����仯��Ѹ���״�\n"+
                "    ���͡�\n"+
                "    һ���ӣ��ѳ�����һ���ơ�\n"+
                "    ���ơ�\n"NOR, me);

        message_vision(HIY "\n    һ��ܴ�ܴ�����ƣ�����$N��\n"NOR, obj);

        tell_object(obj, HIR "\n���;���������հ��ʹ����־������ͷ����һƬ�հף�\n" NOR);


//���˵ľ������ҵ�1/10��ʱ�����˼�����
        if ( ((int)me->query("combat_exp", 1) / (int)obj->query("combat_exp", 1)) > 10 )  
        {
                obj->die();
                destruct(this_object());
                return 1;     
        }

//���˵ľ������ҵ�1/3��1/10��ʱ��������һ���Ķ���
        if ( (((int)me->query("combat_exp", 1) / (int)obj->query("combat_exp", 1)) > 3)&&
            (((int)me->query("combat_exp", 1) / (int)obj->query("combat_exp", 1)) <10) )  
        {
                obj->receive_damage("qi", 100);
                obj->receive_wound("qi",  100);
                destruct(this_object());
                return 1;     
        }

//���˵ľ������ҵ�10��3��ʱ�����˻��⡣
        if ( (((int)obj->query("combat_exp", 1) / (int)me->query("combat_exp", 1)) <10)&&
            (((int)obj->query("combat_exp", 1) / (int)me->query("combat_exp", 1)) >3) )  
        {
                destruct(this_object());
                return 1;     
        }

//���˵ľ������ҵ�10����ʱ�����˷�����
        if ( ((int)obj->query("combat_exp", 1) / (int)me->query("combat_exp", 1)) >10)  
        {
                me->die;
                destruct(this_object());
                return 1;     
        }
}
