// ������
// Ȩ����ͨ�������Ṧ֮һ

inherit SKILL;

mapping *action = ({
([
        "action" : "$n����һ�ݣ��������磬һʽ��ƽ�����ס����Ѷ㿪$N�Ĺ�����\n",
]),
([
        "action" : "$n����$N���ƣ�����ȫ��������һʽ��������ȫ������������$N���ŵ�$N��æ����һ�ԡ�\n",
]),
([
        "action" : "$n����΢������һ̤�أ�һʽ��һŭ���졹������������$N����ǰ��û����$n�ټ���\n",
]),
([
        "action" : "$n���㲻����ͻȻ���һ��������һʽ�������������$N����һ�٣�$n����ƶ��˿�ȥ��\n",
]),
([
        "action" : "$n����һ����һʽ���������硹�����ض��У��ܿ���$N�ķ�â��\n",
])
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage)
{
        return usage == "dodge" ;
}

int valid_learn(object me)
{
        if( (int)me->query("dex") < 15 )
                return notify_fail("���������࣬ѧ�Ɀ�ص����������²����ʡ���\n");
        return 1;
}

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);

        return action["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("�������̫���ˣ�������ϰ��������\n");
        me->receive_damage("qi", 25);
        return 1;
}

