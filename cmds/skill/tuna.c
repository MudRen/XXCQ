// Create By Lanny

#include <skill.h>

inherit F_CLEAN_UP;

private int respirate_cost;
private int respirating(object me);
private int halt_respirate(object me);

int main(object me, string arg)
{

        seteuid(getuid());
        
        if (me->is_busy()) 
                return notify_fail("��������æ���أ�\n");

        if (me->query_temp("xuet"))
                return notify_fail("�㻹��ר�Ķ���ɡ�\n");

        if (me->query_temp("mache")) return notify_fail("����������������\n");
        if (me->query_temp("chuan")) return notify_fail("���ڵ�������������\n");

        if( me->is_fighting() )
                return notify_fail("ս�������ɣ�����ֻ�����ɲ���������\n");

        if( !arg || !sscanf(arg, "%d", respirate_cost))
                return notify_fail("��Ҫ��������Ϣ���У�\n");

        if (respirate_cost <= 9)
                return notify_fail("�㲻�����ɣ�\n");

        if( (int)me->query("qi") < respirate_cost )
                return notify_fail("��������Ϣ���㣬�޷����о�����\n");

        write("������۾���ʼ����������\n");
        me->set_temp("pending/exercise", 1);
        me->set_temp("respirate_cost", respirate_cost);
        message_vision("$N��ϥ���£���ʼ����������\n", me);
        me->start_busy((: respirating :), (: halt_respirate :));
        return 1;
}

int respirating(object me)
{
        
        
        int respirate_cost = (int)me->query_temp("respirate_cost");
        int jingli_gain = 1 + (int)me->query_skill("force") / 10;


        if (respirate_cost < 1)
                return 0;

//      me->set_temp("respirate_cost", respirate_cost = respirate_cost - jingli_gain);
        
        if ( me->query("qi") >= jingli_gain )
        {
                me->add("jingli", jingli_gain);
                me->set_temp("respirate_cost", respirate_cost-= jingli_gain);
                me->add("qi", -jingli_gain);
        }
        else
        {
                me->add("jingli", me->query("qi"));
                respirate_cost -= me->query("qi");
                me->set_temp("respirate_cost", respirate_cost-= me->query("qi"));
                me->set("qi", 0);
        }
                

        if (respirate_cost > 0)
                return 1;


        me->delete_temp("pending/exercise");
        respirate_cost = 0;
        
        message_vision("$N������ϣ�����˫�ۣ�վ��������\n", me);
        
       if((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
                return 0;
        else {
                if ((int)me->query("max_jingli") > (int)me->query_skill("force") * 10)
                {
                        write("��ľ�����Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
                        me->set("jingli", (int)me->query("max_jingli"));
                        return 0;
                }
                else
                {
                        me->add("max_jingli", 1);
                        me->set("eff_jingli", (int)me->query("max_jingli"));
                        me->set("jingli", (int)me->query("max_jingli"));
                        write("��ľ��������ˣ���\n");
                        return 0;
                }
        }
}

int halt_respirate(object me)
{
        respirate_cost = 0;
        if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
                me->set("jingli", (int)me->query("max_jingli") * 2);        
        me->delete_temp("pending/exercise");
        return 1;
        
        
}

int help(object me)
{
        write(@HELP
ָ���ʽ : respirate|tuna [<�ķѡ���Ϣ������>]
 
�������У����á������������������������项�ķ�������ľ�
ת��ɾ�����

See also: exercise
HELP
        );
        return 1;
}
