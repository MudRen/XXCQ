// longsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("����", ({ "jian qiao", "qiao" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ʣ����ֿ�����������ʹ��\n");
		set("rendu", 120);
		set("material", "iron");
		set("wield_msg", "$N�������������������С�\n");
		set("unwield_msg", "$N�����е�$n���¹������ϡ�\n");
	}
	init_sword(5);
	setup();
}