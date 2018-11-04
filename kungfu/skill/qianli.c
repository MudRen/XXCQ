// SKILL: qianli.c ����ǧ�� �¼�������
// Created by Zeus 1999.5.1
// Modified by Zeus 1999.5.7
// 
// 

inherit SKILL;

mapping *action = ({
([	"action" : "$n˫�ֲ���������Ť��,һʽ��������ѩ������$N�����������С������˳�����\n",
]),
([	"action" : "$n˫��ͬʱ���Ƽ�ǿ��һʽ�����������$n������էͣ��$N��ǰ��$N��������֣�$n����Ӱ��ת����$N����\n",
]),
([	"action" : "$nһʽ��������������ɫ���࣬������б��Ʈ����$N�Ĺ����ֿ��ˡ�\n",
]),
([	"action" : "$n����������������ֹ���էͣ�����ֹ���������һʽ�����ﶾ�С���$n�𹥷��ˣ�������������һ�ߡ�\n",
]),
([	"action" : "$n�������Ƴ��졢�������Ƴ��أ�����¡����һʽ�����������������������$N�ı���\n",
]),
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
	if( (int)me->query("qi") < 40 )
		return notify_fail("�������̫���ˣ�������������ǧ���\n");
	me->receive_damage("qi", 20);
	return 1;
}
