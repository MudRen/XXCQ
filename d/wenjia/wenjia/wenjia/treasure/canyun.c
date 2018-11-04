// Item xiangshi.c
// Created by Zeus 1999.4.3
// Modified by Zeus 1999.6.9
// 
// 

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_fang", "diu");
}

int do_fang(string);

void create()
{
        set_name("��ʶ������", ({"xiangshi"}));

        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��СС���޻���һ��Ҳ����������������ʿ��֮ɫ����¼���������ʶ�����С���\n");
                set("value", 10000000);
        }
        setup();
}

int do_fang(string arg)
{
        object me, obj;
        int my_exp,obj_exp,beishu;

        me = this_player();

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if( !objectp(obj = present(arg, environment(me)) ) )
                return notify_fail("����û������ˡ�\n");
 
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if( obj == me )
                return notify_fail("��suicide ָ���ȽϿ졣\n");

        my_exp = me->query("combat_exp");
        obj_exp = obj->query("combat_exp");
        beishu = my_exp / obj_exp;

        if (wizardp(me)) {
                message_vision("$N�ľ�����"+my_exp+"\n",me);
                message_vision("$N�ľ�����"+obj_exp+"\n",obj);
                message_vision("$N�ľ������$n�ľ�����"+beishu+"\n",me,obj);
        }


//      message_vision(HIY "\n    $N˵������֪����������--���ǽ���Ÿո���ʶ��ȴ���Ѿ���\n"+
//              "������ֻ��Ե��ʶ�������粨��Ҳ���ն࣬�������²�����ʶ\n"+
//              "����ν�ǡ���ʶ�����С���......��\n"NOR, me);

//      message_vision(HIY "\n    ����ϧ֪�������ף�Ҳû���ã����ǲ��ò�����--������ֹ��\n"+
//              "ʶ�����У�����ʶ�ڡ����ꡯ���ģ���\n"NOR, me);

        message_vision(HIY "    ͻȻ����$NСС���������һ�\n"+
                "    ����Ѹ�ٱ��͡�\n"+
                "    ˵Ҳ�������ţ�ԭ�ȣ�����ֻ��һ���޻���\n"+
                "    СС�ģ�����ģ����ɵģ��һҵġ���$N�Ŀ������Ư��\n"+
                "�˳�����\n"+
                "    Ҳ��Ʈ���˳�����\n"+
                "    ����Ѹ����仯��Ѹ���״�\n"+
                "    ���͡�\n"+
                "    һ���ӣ��ѳ�����һ���ơ�\n"+
                "    ���ơ�\n"+
                "    һ��ܴ�ܴ�����ƣ�����$n��\n"NOR,me,obj); 

//�ҵľ����ǵ��˵�10��ʱ�����˼�����
        if (  my_exp / obj_exp  >= 10 )  
        {
                obj->die();
                tell_object(me, GRN "�������ǰ�ľ��ﲻ���������������ϵ�Ҳ������ʹ��\n"+CYN+"���еġ��������Ѿ��������ˡ�\n" NOR );
                tell_object(obj,HIB "���Ȼ����ȫ��Ƥ������۷��һ��ʹ������ͻȻ��������!\n" NOR );
                destruct(this_object());
                return 1;     
        }

//�ҵľ����ǵ��˵�3��10��ʱ��������һ���Ķ���
//        if ( (((int)me->query("combat_exp") / (int)obj->query("combat_exp")) >= 3) &&
//            (((int)me->query("combat_exp") / (int)obj->query("combat_exp")) <= 10) )  
//        {
//                obj->receive_damage("qi", (me->query("max_qi")/30));
//                obj->receive_wound("qi",  (me->query("max_qi")/30));
//                obj->apply_condition("xiangshi_poison", 100 - me->query("con") - me->query_skill("force") +1+ me->query_condition("xiangshi_poison"));
//                message_vision(HIB "$P��Ȼ����ȫ��Ƥ������۷��һ��ʹ������ͻȻ��������!\n" NOR,me,obj);
//                destruct(this_object());
//                return 1;     
//        }

//���˵ľ������ҵ�10��3��ʱ�����˻��⡣
//        if ( (( (int)obj->query("combat_exp") / (int)me->query("combat_exp")) <= 10)&&
//            (((int)obj->query("combat_exp") / (int)me->query("combat_exp")) >= 3) )  
//        {
//                destruct(this_object());
//                return 1;     
//        }

//���˵ľ������ҵ�10����ʱ�����˷�����
//        if ( ( (int)obj->query("combat_exp") / (int)me->query("combat_exp")) >= 10)  
//        {
//                me->die();
//                destruct(this_object());
//                return 1;     
//        }
          destruct(this_object());
          return 1;

}
