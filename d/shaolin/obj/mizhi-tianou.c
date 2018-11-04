// bocai-fentiao.c ÃÛÖ­ÌğÅº

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(WHT"ÃÜÖ­ÌğÅº"NOR, ({"mizhi tianou", "tianou"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅèÏãÌğÈíÅ´£¬É«Ôó·ÛºìµÄÃÛÖ­ÌğÅº¡£\n");
		set("unit", "ÅÌ");
		set("value", 1);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
