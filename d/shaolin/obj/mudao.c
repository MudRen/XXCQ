// mudao.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(YEL"ľ��"NOR, ({ "mu dao", "dao", "blade" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "wood");
		set("long", "����һ��ľ�ƵĶ̵���������ɮϰ����ô˵����������ˡ�\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(5);
	setup();
}