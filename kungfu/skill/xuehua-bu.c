// xuehua-bu.c ѩ���� 
// god  
#include <ansi.h>
inherit SKILL;
string *dodge_msg = ({
    "ֻ��$nһ�С�����˳��Ȼ���������ڿգ�˫�����ϣ���ֱ���������࣬�����$N��һ�С�\n",
    "$n������ת��һʽ����ȥ�����С�ͷ��ǰͦ�������ո���ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
    "$n˫��ץ�أ�����΢�Σ�һ�С����Ǳ��ҹ���о����յرܿ���$N��һ�С�\n"
    "����$n����Ʈ����һʽ������һ��졹������һ�ݣ����ѱܿ���\n",
    "$nһ��������ϸ������������ݳ�����֮Զ���ܿ���$N���������ƣ��������۽�$N���ԡ�\n",
    "$nʹ�����������ɲ�����˫���繳��һ��ƮȻ�ݳ��������ŵء�\n"
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
                return notify_fail("�������̫���ˣ��޷�ѩ��������\n");
        me->receive_damage("qi", 15);
        return 1;
}

