// beast.c

#include <race/beast.h>

mapping combat_action =
([
	"hoof": ([
		"action":		"$N�ú�����$n��$l����һ��",
		"damage":		100,
		"damage_type":	"����",
	]),
	"bite": ([
		"action":		"$N������������$n��$l�ݺݵ�һҧ",
		"damage":		20,
		"damage_type":	"ҧ��",
	]),
	"claw": ([
		"action":		"$N��צ����$n��$lһץ",
		"damage_type":	"ץ��",
	]),
	"poke": ([
		"action":		"$N������$n��$lһ��",
		"damage":		30,
		"damage_type":	"����",
	]),
	"knock": ([
		"action":		"$N��ͷ��$n��$l����һײ",
		"damage":		100,
		"damage_type":	"����",
	]),
]);

string *actions;

void create()
{
	actions = keys(combat_action);
}

void setup_beast(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	my["unit"] = "ֻ";

	if( undefinedp(my["actions"]) ) {
		if( pointerp(my["verbs"]) )
			ob->set("default_actions", (: call_other, __FILE__, "query_action" :) );
		else
			my["default_actions"] = ([
				"action": "$N����$n��%s��%s\n",
			]);
	}
	
	if( undefinedp(my["gender"]) ) my["gender"] = "����";
	if( undefinedp(my["age"]) ) my["age"] = random(40) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random(41) + 5;
	if( undefinedp(my["int"]) ) my["int"] = random(11) + 5;
	if( undefinedp(my["per"]) ) my["per"] = random(31) + 5;
	if( undefinedp(my["con"]) ) my["con"] = random(41) + 5;
	if( undefinedp(my["dex"]) ) my["dex"] = random(41) + 5;
	if( undefinedp(my["kar"]) ) my["kar"] = random(21) + 5;
	if( undefinedp(my["bac"]) ) my["bac"] = random(21) + 5;

	if( undefinedp(my["eff_douzhi"]) ) my["eff_douzhi"] = 100;
	if( undefinedp(my["max_douzhi"]) ) my["max_douzhi"] = 200;

	if( undefinedp(my["max_jingli"]) ) {
		if( my["age"] <= 3 ) my["max_jingli"] = 50;
		else if( my["age"] <= 10 ) my["max_jingli"] = 50 + (my["age"] - 3) * 20;
		else if( my["age"] <= 30 ) my["max_jingli"] = 190 + (my["age"] - 10) * 5;
		else my["max_jingli"] = my["max_jingli"] = 290 + (my["age"] - 30);
	}

	if( undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 5 ) my["max_qi"] = 50;
		else if( my["age"] <= 20 ) my["max_qi"] = 50 + (my["age"] - 5) * 25;
		else my["max_qi"] = my["max_qi"] = 425 + (my["age"] - 20) * 5;
	}
	//	NOTE: beast has no initial limbs defined, you must define it yourself.
	//	ob->init_limbs(LIMBS);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action(object me)
{
	string *act;

	act = me->query("verbs");
	return combat_action[act[random(sizeof(act))]];
}
