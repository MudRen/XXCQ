// jiedao.c �䵶
// by Load

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIW"�䵶"NOR, ({ "jie dao", "dao", "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "iron");
		set("rendu", 150);
		set("long", "����һ���߰볤�Ľ䵶���������������ֳ��أ����Ǿ�����ɡ�\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	init_blade(20);
	setup();
}
