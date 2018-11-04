// jitui.c ¼¦ÍÈ

#include <weapon.h>
#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name(HIY"¿¾¼¦ÍÈ"NOR, ({ "jitui", "tui", "ji" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»Ö¦¿¾µÃÏãÅçÅçµÄ¼¦ÍÈ¡£\n");
		set("unit", "¸ù");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 15);
	}
	setup();
}