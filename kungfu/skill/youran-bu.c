// youran-bu.c  

#include <ansi.h>
inherit SKILL;
string *dodge_msg = ({
    HIM "$n�������ĵ���������һ�����պñܹ�����������Ĺ��ơ�\n"NOR,
     YEL"����$nǡ����������һ�����������һ�С�\n"NOR,
        WHT "����$n����Ʈ��������һ�ݣ����ѱܿ���\n"NOR,
         HIC"$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n"NOR,
       CYN "����$n����һ�ã������һ�����˸��ա�\n"NOR,
       HIY "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n"NOR,
         HIW"$n����΢�Σ��о����յرܿ�����һ�С�\n"NOR,
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ��޷���Ȼ������\n");
        me->receive_damage("qi", 20);
        return 1;
}

