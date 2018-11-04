// mala-doufu.c ÂéÀ±¶¹¸¯

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(WHT"ÂéÀ±¶¹¸¯"NOR, ({"mala doufu", "doufu"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅèÑÕÉ«ºìÁÁ£¬Ï¸ÖĞ´øÄÛ£¬ÏãÀ±¿É¿ÚµÄÂéÀ±¶¹¸¯¡£\n");
		set("unit", "ÅÌ");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
