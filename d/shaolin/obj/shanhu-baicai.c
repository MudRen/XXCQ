// shanhu-baicai.c Éºº÷°×²Ë
// by Load

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"Éºº÷°×²Ë"NOR, ({"shanhu baicai", "shanhu", "baicai"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»Åèºì°×Ïà¼ä£¬´àÄÛË¬¿Ú£¬ÇåÏãÓÕÈËµÄÉºº÷°×²Ë¡£\n");
		set("unit", "ÅÌ");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
