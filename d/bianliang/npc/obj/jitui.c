// jitui.c ����

#include <weapon.h>
#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name(HIY"������"NOR, ({ "jitui", "tui", "ji" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ֦����������ļ��ȡ�\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 15);
	}
	setup();
}