// blade.c

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(HIW"�˵�"NOR, ({ "cai dao", "dao"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 200);
		set("material", "iron");
		set("distance", 1);
		set("long", "����һ���в��õĲ˵����ż�����������ƴ��Ҳ�ɡ�\n");
		set("wield_msg", "$N���һ��Ѫ���ܵ�$n�������С�\n");
		set("unequip_msg", "$N��$nС�ĵı������ϡ�\n");
	}
	init_blade(8);
	setup();
}
