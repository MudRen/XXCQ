// tiefu.c

#include <weapon.h>
#include <ansi.h>
inherit AXE;

void create()
{
	set_name(CYN"����"NOR, ({ "tie fu", "axe", "fu", "tiefu"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������õ����������������ǳ�˳�֡�\n");
		set("value", 1000);
		set("distance", 2);
                set("material","iron");
		set("wield_msg", "$N�ó�һ�ѿ����$n���������е���������\n");
		set("unwield_msg", "$N��$n�����ڱ���\n");
	}
	init_axe(20);
	setup();
}
