inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIC "��ţ��" NOR, ({"rou"}));
	set_weight(50);

	if (clonep())
		set_default_object(__FILE__);
	else
	{
	        set("unit", "��");
		set("long", "����һ�̽����������µ���ţ�⣬���¾Ƶĺòˡ�\n");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 20);
	}
        setup();
}