//���𽣷�
//Write by phoenix 1999.12.29

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int main(object me, string arg)
{
        string *style = ({
"$N��̤-"HIR"��"HIW"-��λ����������֮�������Ž���������$n��Ҫ����",
"$N�Ų�-"HIG"ˮ"HIW"-��λ�����ִ���$n��˲ʱ�ͽ�$n����Χס��",
"$N��̤-"HIY"��"HIW"-��λ������$N��ǰһ�ݣ�����֮����$n�ʹ̹�ȥ��",
"$N����-"HIC"��"HIW"-��λ��������������֮���������㣬�ִ�$n������Ҫ����",
"$NԾ��-"HIM"ľ"HIW"-��λ��������������֮�����¶��ϣ�Ѹ���ޱȣ�������$n��Ҫ����"
});
        object ob,ob1,*obs;
        string who1,msg;
        int exp,i;
        me=this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("�����ֹս����\n");
        if( me != this_player() )
        return 0;
        if( !arg || sscanf(arg, "to %s", who1) != 1 )
                return notify_fail("ָ���ʽ: array to <ĳ��>\n");
        if( !objectp(ob1 = present(who1, environment(me))))
                return notify_fail("�Ҳ���" + who1 + "��\n");
        if( !living(ob1) )
                return notify_fail("�ⲻ�ܶ�������ʹ���󷨡�\n");
        if(!pointerp(obs=me->query_team()))
        return notify_fail("������Ӳſ��Է�����ʽ��\n");
        if(sizeof(obs)>=5)
        return notify_fail("�����������ˣ���\n");
        if(!pointerp(obs=me->query_team())
        ||!me->is_team_leader())
        return notify_fail("ֻ�ж�������ſ��Է�����ʽ��\n");
        if(me->query_temp("start_zhenfa"))
        return notify_fail("�������Ѿ��ڽ����У�\n");
        for(i=0;i<sizeof(obs);i++)
        {
                if(!obs[i])
                return notify_fail("����Ҫ������϶��顣\n");
                if(environment(obs[i])!= environment(me))
                return notify_fail("�������Ա����ȫ������ߡ�\n");
                if(!obs[i]->query_skill("tianyu-zhenfa"))
                return notify_fail("����������˲�����ʹ�������󷨡�\n");
                if(obs[i]->query_skill("tianyu-zhenfa")<60)
                return notify_fail("����������������󷨻�������졣\n");
                if(!objectp(ob=obs[i]->query_temp("weapon")))
                return notify_fail("��Ķ���������û�б�����\n");
                if(ob->query("skill_type") != "sword")
                return notify_fail("��Ķ���������û���ý���\n");
        }
        
        message_vision(HIY"\n\n$N�ߺ�һ����"HIR"��������!!!��\n"HIY"������������һ���ſ�����̤���а��ԣ����������������
        �������л���������������ˣ�һ���Ӱ�$n���������С� \n\n"NOR,me,ob1);
        for(i=0;i<sizeof(obs);i++)
        {
                
                ob=obs[i]->query_temp("weapon");
                exp=200/5*sizeof(obs);
                obs[i]->add_temp("apply/attack", exp);
                obs[i]->add_temp("apply/parry", exp);
                obs[i]->add_temp("apply/dodge", exp);
                msg = HIW +  style[i] + NOR;
                message_vision(msg,obs[i],ob1); 
                COMBAT_D->do_attack(obs[i],ob1,ob,0);
                obs[i]->fight_ob(ob1); 
                if(!ob1->is_killing(me))
                ob1->kill_ob(obs[i]);
                        
       }
       me->set_temp("start_zhenfa",1);
       call_out("start_array",5,me);
       return 1;
}

int start_array(object me,object *obs)
{
        int i,exp;
        obs=me->query_team();
          
        for(i=0;i<sizeof(obs);i++)
        {
                
                if(obs[i]->is_fighting())
                {
                        tell_object(environment(obs[i]),HIW"�������ٵ���ת�ţ�����֮��Խת�졢һ���������ս���\n" NOR);
                        call_out("start_array",5,obs[i]);
                        return 1;
                }
                else
                {
                        exp=200/5*sizeof(obs);
                        me->set_temp("start_zhenfa",0);
                        tell_object(environment(obs[i]),HIW"�������Ѿ���ϣ����������λ��\n" NOR);
                        obs[0]->add_temp("apply/dodge",-exp);
                        obs[0]->add_temp("apply/parry",-exp);
                        obs[0]->add_temp("apply/attack",-exp);
                        obs[1]->add_temp("apply/dodge",-exp);
                        obs[1]->add_temp("apply/attack",-exp);
                        obs[1]->add_temp("apply/parry",-exp);
                        obs[2]->add_temp("apply/attack",-exp);
                        obs[2]->add_temp("apply/dodge",-exp);
                        obs[2]->add_temp("apply/parry",-exp);
                        obs[3]->add_temp("apply/attack",-exp);
                        obs[3]->add_temp("apply/dodge",-exp);
                        obs[3]->add_temp("apply/parry",-exp);
                        obs[4]->add_temp("apply/parry",-exp);
                        obs[4]->add_temp("apply/attack",-exp);
                        obs[4]->add_temp("apply/dodge",-exp);
                        return 1;
                }
        }
}                               
