// jiedao.c �䵶
// by Load

#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name(YEL"ľ��"NOR, ({ "mubi" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "wood");
		set("distance", 2);
		set("long", "����һ���߰볤�Ľ䵶���������������ֳ��أ����Ǿ�����ɡ�\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	init_club(20);
	setup();
}
