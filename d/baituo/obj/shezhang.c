#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name("����" NOR, ({ "she zhang", "shezhang", "zhang"}));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������������ߵ����ȡ�\n");
		set("value", 500);
		set("material", "steel");
	}
	init_staff(30);
	setup();
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 3);
        return 0;
}
