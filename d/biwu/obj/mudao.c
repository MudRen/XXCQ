// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("ľ��", ({ "blade" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������Ƴɵ�ľ�����䲻������ȴ�����ˡ�\n");
		set("value", 0);
		set("material", "bamboo");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_blade(10);
	setup();
}
