// gangdao.c

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(HIW"��������"NOR, ({ "bieli liangjian","liangjian","jian","sword" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������������Щ���ݵ����ͽ��������������ϱ�����彣��\n");
		set("value", 1000);
		set("rendu", 200);
		set("material", "steel");
		set("wield_msg", WHT"$N����һ�Σ�$n"WHT"���ʣ���һ������ѿա�\n"NOR);
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(45);
	setup();
}