//�廢�ϻ굶


inherit SKILL;

mapping *action = ({
        ([      "name":                 "������ʳ",
                "action":
"$N����Ծ�ڿ��У����������ʳһ�㣬����$w��������֮�ƣ���$n��ͷ����",
                "dodge":		0,
		"parry":		0,
                "damage":		15,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���˳ɻ�",
                "action":
"$Nչ���Ṧ��$n��Χ�ɱ�����������$n��ȥ������$nֻ��������Ӱ����������ͬ\n�ķ����������ɾ���ʧ��",
                "dodge":		0,
		"parry":		0,
                "damage":		20,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "���ٻ���",
                "action":
"$Nһ���޺����$n���л�����ֹ���ô˻��ᣬ$Nһ������$n��$l��ԭ�����廢\n�ϻ굶�е�ɱ�֡����ٻ�����",
		"dodge":		0,
		"parry":		0,
                "damage":		25,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "����ƽ��",
                "action":
"$N���ƻ��������ڵ��ϣ�һʽ������ƽ����������$w������$n��˫����ȥ",
                "dodge":		0,
		"parry":		0,
                "damage":		10,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�ﻢ����",
                "action":
"$Nվ�������������֮��������$w�У���$n��������һ�������С��ﻢ���¡�\n������Ȼ������������Ȼ��Ч",
                "dodge":		0,
		"parry":		0,
                "damage":		30,
                "damage_type":  "����"
        ]),
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 100 )
		return notify_fail("�����������������ѧ�廢���ŵ���\n");
        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������������\n");

        return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�����̫�ͣ�������ȥ����Σ�յģ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("��������������޷���ϰ�廢�ϻ굶��\n");
	me->receive_damage("qi", 20);
	me->add("neili", -10);
	message_vision("$N������ѧ����һ���廢�ϻ굶��\n", me);
	return 1;
}

int valid_enable(string usage)
{
        return usage=="blade"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
