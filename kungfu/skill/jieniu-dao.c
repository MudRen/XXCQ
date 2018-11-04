// made by lks

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N�ص����գ�һ�С�˳�졹���������¶��ϻ��˸��뻡����$n��
$l��ȥ",
        "force" : 160,
        "dodge" : -10,
        "parry" : 5,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "˳��",
        "damage_type" : "����"
]),
([      "action" : "$N�����������⣬������˼��һ�С����项������$w��ֱ����$n��$l",
        "force" : 180,
        "dodge" : -10,
        "parry" : 10,
        "damage": 20,
        "lvl" : 12,
        "skill_name" : "����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��������ࡹ��$w�ƾ�����������Ȼ��ˢ��һ�����϶�����$n����",
        "force" : 200,
        "dodge" : -5,
        "parry" : 5,
        "damage": 25,
        "lvl" : 18,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N���ַ�ִ�����������׼�Լ���һ�С�����һ�񡹣���һ����$wֱ��$n�ľ���ն
ȥ",
        "force" : 220,
        "dodge" : 5,
        "parry" : 5,
        "damage": 30,
        "lvl" : 24,
        "skill_name" : "����һ��",
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С��������ء����������⻯����㷱�ǣ���$n��$l��ȥ",
        "force" : 240,
        "dodge" : 10,
        "parry" : 5,
        "damage": 40,
        "lvl" : 30,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֺ�ִ$w��һ�С�����֮������š��ת������ֱ����$n��˫��
",
        "force" : 260,
        "dodge" : 15,
        "parry" : 15,
        "damage": 50,
        "lvl" : 36,
        "skill_name" : "����֮��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ò����������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
        "force" : 280,
        "dodge" : 15,
        "parry" : 15,
        "damage": 60,
        "lvl" : 42,
        "skill_name" : "���ò��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��������ס���$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��
",
        "force" : 320,
        "dodge" : 10,
        "parry" : 20,
        "damage": 75,
        "lvl" : 54,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����ƽָ��һ�С��Ҷ���ţ����һƬƬ�йǵ�����쫷�����$n��
ȫ��",
        "force" : 370,
        "dodge" : 5,
        "parry" : 25,
        "damage": 90,
        "lvl" : 60,
        "skill_name" : "�Ҷ���ţ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������������\n");
/*
        if ((int)me->query("yiqiguan-riyue") < 1)
                return notify_fail("���һ�������»��̫ǳ,��û�ﵽ�������������ľ��硣\n");
*/
        if ((int)me->query_skill("blade", 1) < 50)
                return notify_fail("��ĵ������̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("jieniu-dao",1);

if (level < 60 )
zhaoshu--;
if (level < 55 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;

return action[random(zhaoshu)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("���������������ţ������\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jieniu-dao/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
        
        if( damage_bonus < 100 ) return 0;
        if (!(me->query("yiqiguan-riyue"))) return 0;
        if( random(damage_bonus/2) > victim->query_str() ) {        
        if (me->query("yiqiguan-riyue")==1) {
        victim->receive_wound("qi", (damage_bonus - 100) / 2 );
        msg= WHT "$nһ���������������м��ӵġ������������ھ����ˣ�$N�ٺ�ֱЦ��\n" NOR;
        }
        if (me->query("yiqiguan-riyue")==2) {
        victim->receive_wound("qi",damage_bonus/2 );
        msg= CYN "$nһ���������������м��ӵġ��Ƿ��켫���ھ����ˣ�$N�ٺ�ֱЦ��\n" NOR;
        }
        return msg;
        }
}


