//Obj ��
//BY godzilla 11.18.99

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(RED"��"NOR, ({ "chaidao", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������õĲ񵶡�\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(5);
	setup();
}
