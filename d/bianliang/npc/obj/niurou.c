// jitui.c ¼¦ÍÈ

#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name(YEL"½´Å£Èâ"NOR, ({ "jiang niurou", "jiang", "niurou", "rou" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÒ»¿éÉ¢·¢×Å½´ÏãµÄ½´Å£Èâ¡£\n");
		set("unit", "¿é");
		set("value", 200);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
	setup();
}