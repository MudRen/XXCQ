// zhujian.c ��
// by Load

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIG"��"NOR,({ "zhu jian", "jian", "sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("rendu",200);
		set("material", "bamboo");
		set("long", "����һ�����������������Ƴɵ����񽣣��䲻������ȴ�����ˡ�\n");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_sword(30);
	setup();
}
