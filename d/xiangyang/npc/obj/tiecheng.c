// gangzhang.c ����

#include <weapon.h>
#include <ansi.h>
inherit STICK;

void create()
{
	set_name(WHT"����"NOR, ({ "tie cheng", "tie", "cheng" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ĳӣ���������ȥ����һ��������\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "iron");
		set("wield_msg", "$N������һ��$n�������е�������\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_stick(15);
	setup();
}
