// blade.c

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;

void create()
{
	set_name(HIC"�������"NOR, ({"xiangjian baodao","baodao", "dao", "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "steel");
		set("rendu", 250);
		set("long", "һ������ɫ�ĵ�������ë�Ϸ������������Ϳױ�����䵶��\n");
		set("wield_msg", CYN"$N���$n"CYN"���֣�����ӳ��һ��ѣ�⣬һ����֪�Ǳ�������\n"NOR);
		set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	init_blade(45);
	setup();
}
