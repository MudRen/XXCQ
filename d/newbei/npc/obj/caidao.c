// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("�˵�", ({ "caidao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", "����һ���в��õĲ˵���\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
	}
	init_blade(5);
	setup();
}
