// �����潣 tianyu-qijian.c 
// write by godzilla 1999.11.5

#include <ansi.h>
inherit SKILL;
mapping *action =
({([
        "action" : "$Nһ�С����ҽ𹳡������־���$w�����������������$n��ȥ",
        "skill_name" : "���ҽ�",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 0,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$N������$wֱ��������һָ����󷴽�����$n��$l,�������������潣�������ơ�ָ��һ����",
        "skill_name" : "ָ��һ��",
        "force" : 110,
        "dodge" : -10,
        "lvl" : 10,
        "damage" : 55,
        "damage_type" : "����",
]),
([      "action" : "ֻ��$N����$wһ����һ�С�÷����Ū����$n���˹�ȥ",
        "skill_name" : "÷����Ū",
        "force" : 120,
        "dodge" : -20,
        "lvl" : 20,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$N������һ�С�����ն�ߡ���$n�����Ĵ��˹�ȥ",
        "skill_name" : "����ն��",
        "force" : 130,
        "dodge" : -10,
        "lvl" : 30,
        "damage" : 75,
        "damage_type" : "����",

]),
([      "action" : "$Nһ����Ц��һ�С���ӵ�к������ɽ����֮�Ʒ���$n��$l",
        "skill_name" : "���������",
        "force" : 140,
        "dodge" : -10,
        "lvl" : 40,
        "damage" : 80,
        "damage_type" : "����",
]),

([      "action" : "$N����$w����־һ����һ����������ա�ƽֱ�̳�",
        "skill_name" : "�������",
        "force" : 150,
        "dodge" : -10,
        "lvl" : 50,
        "damage" : 80,
        "damage_type" : "����",
]),

([      "action" : "$NͻȻ�������һ�󲽣�����Զ���룬һ�С���̶ӡ�¡������˳�ȥ",
        "skill_name" : "��̶ӡ��",
        "force" : 160,
        "dodge" : -5,
        "lvl" : 60,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$N��һ��������ʹ���������ѩ��������$w���·��ɣ�����Ʈѩ�����$n����$p��Ҳ�ֲ����ĸ����棬�ĸ��Ǽ�",
        "skill_name" : "�����ѩ",
        "force" : 170,
        "dodge" : -5,
        "lvl" : 70,
        "damage" : 85,
        "damage_type" : "����",
]),
([      "action" : "$N����$w���ݣ�һ����ŭ���񻨡����˳�ȥ,���������潣�����޳���ɱ�����͵�һ�У�����$wһ���һ��ش���$n,��$p��������",
        "skill_name" : "ŭ����",
        "force" : 180,
        "dodge" : -15,
        "lvl" : 80,
        "damage" : 90,
        "damage_type" : "����",

]),
([      "action" : "$N���ָ߾�$w�����һ��ʹ�����������ء����϶���ն��$n�������ޱȣ�������ӿ",
        "skill_name" : "��������",
        "force" : 190,
        "dodge" : -20,
        "lvl" : 90,
        "damage" : 100,
        "damage_type" : "����",

]),

([      "action" : "$N����ǰ��ʹ�������쳤Ц��������$w����һ����������$n��$l",
        "skill_name" : "���쳤Ц",
        "force" : 200,
        "dodge" : -20,
        "lvl" : 100,
        "damage" : 120,
        "damage_type" : "����",

]),
});
string  *msg = ({

HIC"$N����$w"HIC"�������䣬�������������Ʋ�����һ�С�����������,��������$nϮ����"NOR,
HIC"����δ�꣬$N����$w"HIC"�Ľ���ȴ�ѷ���,�����쳤Ц���������ճ��������������ѩ��\n�����̳���������������,����$n��$l"NOR,
HIC"$w"HIC"���Ž������ڿ��������ɻأ�һʽ������һ������Ѹ�ײ����ڶ�֮�Դ���$n��������\n�������ʮ��ʽ���е�һ��"NOR,
HIC"ͻȻ��������һ��������������һ����������㻮�Ƴ��գ���һʽ��ŭ����硹��\n�����������죬ɱ��������!"NOR,
HIC"$N���ط������͵Ļ���һ����һ�С�ʯ���쾪������ն�˳�ȥ�����к󷢶���������\nȻ���Ѵ�����$n��$l"NOR,
HIC"ֻ��$w"HIC"����$n�����·��ɣ�$w"HIC"��Ծ�鶯�����������������Ƶ����������絶���\nҪ��$n��������,��һ�С��乭���ա�"NOR,
HIC"$N�������𣬱���ʹ�����Ż����ա������˾ŵ�������һ������$n��ȥ"NOR,
HIC"$N���η�ת��һ����ŭ����硹����$n,ͻȻ����;�������磬������������ա�\n�����˴�����׷�������"NOR,
HIC"ɱ�������������ռ䣬��Ȼ��Ѫ������Ѿ��̳���������Х���У�$w"HIC"��ֱ�ɡ���б\n�ɡ������������׹��������,��ʱ��$n��ȫ����·�ѱ�����"NOR,
HIC"�͵���$w"HIC"��$n$l��ȥ��$N��ʽ���䡸ŭ���񻨡�������̶ӡ�¡��������ҽ𹳡���Ȼ\n�ݳ�����$p����ж��֮ʱ������$p��$l"NOR,
HIC"ת�ۼ�$w"HIC"����̵�$n��$nȴ������ͷ�����������һһ��������$w"HIC"���糤�����۾�һ\n�㣬��Ȼ����������$n��$l"NOR,
HIC"$NĿ��ת���Ķ���$n��һ�С�������ġ��ͷ��˳�ȥ������ƽ�����棬�����������\n����$p�ķ���˺��֧������"NOR,
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}
void skill_improved(object me)
{
   int skill=me->query_skill("tianyu-qijian", 1);
   if(skill >= 150 && !me->query("tianyu_1"))
   {
         me->set("tianyu_1", 1);   
         tell_object(me, HIW"\n\n��Ȼ����������������潣ÿһ�ж��������ظ��ţ���̼�������
�������潣�ľ���"+HIR+"��������"+HIW+"�����ʮ���н����Ѿ���Ȼ����,������
������һ���µľ��磡\n"NOR);
         me->add("int",1);
          
   }

}
int valid_learn(object me)
{

        if((int)me->query_int() <=25)
            return notify_fail("�����潣����Ҫ����һ�����򡱣������Բ�������ѧϰ\n");
        if((int)me->query("max_neili") < 100)
            return notify_fail("�������������\n");
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
        string message;
        level   = (int)me->query_skill("tianyu-qijian",1);
        if( me->query("tianyu_1"))
        {             
             message = msg[random(sizeof(msg))];
             return ([
             "action":message,
             "damage":(random(5)+1)*100,
             "damage_type":"����",
             "dodge": -10,
             "force":250+random(300)
            ]);

        }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/5)];

}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon;
        weapon=me->query_temp("weapon");
        if (!objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("id") != "jinhong jian")
        return 0;
        if( damage_bonus < 100 )
        return 0;
        else
        {
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return HIY"ֻ��һ����⻮����"+me->name()+"����"HIR"��罣"HIY"���·��ɣ�ɲ�Ǽ䵫�����⣬������Ӱ\n"NOR;
        }
        
}        

int practice_skill(object me)
{
       return notify_fail("�����潣��������������\n");
}

string perform_action_file(string action)
{
    return __DIR__"tianyu-qijian/" + action;
}




