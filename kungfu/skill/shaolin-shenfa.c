// shaolin-shenfa.c ������
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([      "action" : "$nһʽ��һέ�ɽ�����ǰ��Žż�Ÿ��࿿��������������ˮ�㻬�����ࡣ\n",
]),
([      "action" : "$nһʽ�������Ӳ�����˫��ǰ�죬ȫ������ƽ�ɣ���ʱ������$N���������ơ�\n",
]),
([      "action" : "$nһʽ���Ʋ����Ρ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
]),
([      "action" : "$nһʽ������Ӱ����һת��䣬����˷�Ʈ����������$n����Ӱ����$N������롣\n",
]),
([      "action" : "$nһʽ���������ա���ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���\n",
]),
([      "action" : "$nһʽ������˫�ɡ��������������������ݷ����У���$Nͷ����Ծ������\n",
]),
([      "action" : "$nһʽ��������ˮ����˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
]),
([      "action" : "$nһʽ���ɷ�鳲�������������ݰ㼱ת�������γ�һ�������У���$N������䣬�������á�\n",
])
});

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_enable(string usage)
{
    return usage == "dodge";
}

int valid_learn(object me)
{
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
   return notify_fail("�������̫���ˣ���������������\n");
    me->receive_damage("qi", 20);
    return 1;
}

