// longsword.c ����

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(WHT"����"NOR, ({ "wuqi", }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����߳������������ڸոմ��,���Ի�û��ĥ��\n");
		set("value", 1500);
		set("material", "iron");
		set("distance", 3);
		
	}
       init_sword(1);
	setup();
}
