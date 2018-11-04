// basi-shanyao.c °ÎË¿É½Ò©
// by Load

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIM"°ÎË¿É½Ò©"NOR, ({"basi shanyao", "shanyao", "basi"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅèÉ«ÈôÃµ¹å£¬ÌğÄÛÏãÄÛµÄ°ÎË¿É½Ò©¡£\n");
		set("unit", "ÅÌ");
		set("value", 1);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
