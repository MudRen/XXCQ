// ������
// Ȩ����ͨ�������Ṧ֮һ

inherit SKILL;

mapping *action = ({
([
        "action" : "$n�벻������һʽ��������⡹���������У���󵹷���һ�ɿ��⡣\n",
]),
([
        "action" : "$nһʽ��һ��ƽ����������һ�Σ�ǰ���߳ߣ�����������$N�Ĺ��ơ�\n",
]),
([
        "action" : "$n�����㣬һʽ����ҡֱ�ϡ�������������$N����ǰ��û����$n�ټ���\n",
]),
([
        "action" : "$n���Ų�æ����һ����һʽ����ͥ�Ų�������������$N�Ĺ������˿ա�\n",
]),
([
        "action" : "$n������𣬿��м�����̤��һ����ת��һʽ���������ơ�����ӯ�����������⡣\n",
]),
([
        "action" : "$n˫��һչ���������ᣬһʽ�����������˳��֮�ƻ���սȦ��\n",
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
        if( (int)me->query("dex") < 20 )
                return notify_fail("�������ʵ��̫�����ˣ����ʺ������Ʋ���\n");
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
                return notify_fail("�������̫���ˣ�������ϰ���Ʋ���\n");
        me->receive_damage("qi", 20);
        return 1;
}
