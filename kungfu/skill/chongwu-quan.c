// ����ʹ�õ��书
// By ɽèAdx @ snow 99-12-12

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N������������$n��$l�ݺݵ�һҧ",
	"dodge": 30,
	"damage_type": "����"
]),
([      "action": "$N��ͷ��$n��$l����һײ",
	"dodge": 10,
	"damage_type": "����"
]),
([      "action": "$N�ú�����$n��$l����һ��",
	"dodge": -20,
	"damage_type": "����"
]),
([      "action": "$N��צ����$n��$lһץ",
	"dodge": 10,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }   

mapping query_action()
{
	if ( random(5)==3 ) {
		return ([
		"action": HIR"$NͻȻ��ȫ��ë����������������ץ��$n"NOR,
		"damage_type": "ץ��"]);
	}
	return action[random(sizeof(action))];
}
