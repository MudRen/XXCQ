//jingshen-zhi.c -����ָ
//����ָ��24ָ,��24��������,���⹥������
//����ָ�������ϸ�,�����н���,����������,������Ӱ��ϴ�

inherit SKILL;

mapping *action = ({
([	"action" : "$N���ֱ�������ƽ�أ�Сָ��㣬һָ��������������ů�⼤����$n��$l",
	"force" : 30,
        "dodge" : -5,
	"lvl" : 0,
	"damage": 10,
	"skill_name" : "����",
	"damage_type" : "����"
]),
([	"action" : "$N���μӿ죬������ָ��㼸�£�ͻȻʳָһͦ��һʽ����ˮ������$n",
	"force" : 60,
        "dodge" : -5,
	"lvl" : 9,
	"damage": 20,
	"skill_name" : "��ˮ",
        "damage_type" : "����"
]),
([	"action" : "$NͻȻԽ����գ�һʽ�����ݡ����Ӹ����£�˫��Ĵָ����ָ����Ȼ����",
	"force" : 90,
        "dodge" : 5,
	"lvl" : 18,
	"damage": 30,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$N����΢ת����Ȼ��ָ��һʽ�����֡�����������ָ�������",
	"force" : 120,
        "dodge" : 5,
	"damage": 40,
	"lvl" : 27,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$N��Ȼ��Ŀ��һָ�Դ�����������ġ�����������������ָ����$n��$l",
	"force" : 150,
        "dodge" : 15,
	"damage": 50,
	"lvl" : 36,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$N˫����ͣ�����ָ������һָ�����꡹����ָ֮����$n������ȥ",
	"force" : 180,
        "dodge" : 20,
	"damage": 60,
	"lvl" : 45,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$N���缱�磬ͻȻ�۽�$n��һָ�����ġ���һ֧���滺��������ȥ",
	"force" : 210,
        "dodge" : 25,
	"damage": 70,
	"lvl" : 54,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��С������������ָ�ҵ���һ����������ٱ��ָ������$n��$l��ȥ",
	"force" : 240,
        "dodge" : 30,
	"damage": 80,
	"lvl" : 63,
	"skill_name" : "С��",
        "damage_type" : "����"
]),
([	"action" : "$N�������ߣ�ɲ�Ǽ���Ȼ�Ƶ���$n�������ָ����������һָ��â�֡��Ӻ��������$n",
	"force" : 280,
        "dodge" : 35,
	"damage": 90,
	"lvl" : 72,
	"skill_name" : "â��",
        "damage_type" : "����"
]),
([	"action" : "$N���չָ��һָ�����ޱȵġ�������������Ĵָ����������$n��$l",
	"force" : 320,
        "dodge" : 50,
	"damage": 100,
	"lvl" : 81,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$NͻȻ��ǰ������$n��æ���мܣ�$N����һ�٣�һʽ��С�����Ѵ���ǰ",
	"force" : 360,
        "dodge" : 35,
	"damage": 110,
	"lvl" : 90,
	"skill_name" : "С��",
        "damage_type" : "����"
]),
([	"action" : "$N����Ĵָһ����ָ��ָָ�������һ�ƴ�Щ��̫����â�ġ��������$n",
	"force" : 400,
        "dodge" : 35,
	"damage": 120,
	"lvl" : 99,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$N����Сָһָ�������һ��ָ��ƮȻ����$n��$l��$n�������޲��",
	"force" : 440,
        "dodge" : 35,
	"damage": 130,
	"lvl" : 108,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$N����Сָ��һ���������ޡ������ޱȵġ������$n�������ƺ���Щ��֪����",
	"force" : 480,
        "dodge" : 35,
	"damage": 140,
	"lvl" : 117,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$N������У�ƮȻ����һָ���ɵġ���¶����ն��£������޴Ӷ���",
	"force" : 520,
        "dodge" : 35,
	"damage": 150,
	"lvl" : 126,
	"skill_name" : "��¶",
        "damage_type" : "����"
]),
([	"action" : "$N��ָ��������·ֱ�̣�һʽ����֡���ȫ�޻�������ʵ��",
	"force" : 560,
        "dodge" : 35,
	"damage": 160,
	"lvl" : 135,
	"skill_name" : "���",
        "damage_type" : "����"
]),
([	"action" : "$Nһָ����¶����������ң����Ϻ��£�������ס��$n��������·",
	"force" : 610,
        "dodge" : 35,
	"damage": 170,
	"lvl" : 144,
	"skill_name" : "��¶",
        "damage_type" : "����"
]),
([	"action" : "$N�����пգ�ʮָ�յ㣬��˪����һʽˮ��к�ذ�Ĺ���$n��$l",
	"force" : 660,
        "dodge" : 35,
	"damage": 180,
	"lvl" : 153,
	"skill_name" : "˪��",
        "damage_type" : "����"
]),
([	"action" : "$N��������ָ��㣬��������ָ׷��һָ����ָ��һ�ͣ�һָѸ���ġ�����������$n",
	"force" : 710,
        "dodge" : 35,
	"damage": 190,
	"lvl" : 162,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$Nָ��������⣬����һʽ��Сѩ����������ָ�������������$n��Ҫ��",
	"force" : 760,
        "dodge" : 35,
	"damage": 200,
	"lvl" : 171,
	"skill_name" : "Сѩ",
        "damage_type" : "����"
]),
([	"action" : "$N����������ʮ��ָ��һʽ����ѩ��ǡ�������ѩ����$n",
	"force" : 810,
        "dodge" : 35,
	"damage": 230,
	"lvl" : 180,
	"skill_name" : "��ѩ",
        "damage_type" : "����"
]),
([	"action" : "$N�Ų���Σ�ָ������һ�ɺ��磬һָ���������䴩��$n��$l",
	"force" : 860,
        "dodge" : 35,
	"damage": 260,
	"lvl" : 185,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$N����΢չ��Ʈ�����ɣ�����ʳָ������ʳָͬ�㣬һʽ��С�������˳�ȥ",
	"force" : 910,
        "dodge" : 35,
	"damage": 290,
	"lvl" : 190,
	"skill_name" : "С��",
        "damage_type" : "����"
]),
([	"action" : "$N���о��Ⱪ�ǣ�ʮָ�ҵ���һʽ���󺮡�����ƥ�ĺ�������$n����",
	"force" : 960,
        "dodge" : 35,
	"damage": 320,
	"lvl" : 195,
	"skill_name" : "��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="yingzhao-gong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ָ������֡�\n");
	if ((int)me->query_skill("finger", 1) < (int)me->query_skill("jingshen-zhi", 1)/2)
		return notify_fail("��Ļ���ָ����򲻹����޷�����ѧ����ָ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ָ��\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("jingshen-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ָ��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"jingshen-zhi/" + action;
}

