// gangzhang.c ����

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(WHT"����"NOR, ({ "tiezhang", "zhang" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ڴ��ص����ա�\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "iron");
		set("distance", 3);
		set("wield_msg", "$N���һ��$n���˵ߣ�����˫���С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_staff(25);
	setup();
}