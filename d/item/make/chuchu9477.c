// ITEM Made by player /d/item/make/chuchu9477.c
// Written by ITEMMAKER(Doing Lu 1998/11/2)	Sat Dec 18 01:00:15 1999
#include <ansi.h>

#include <weapon.h>

inherit WHIP;

string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
	set_name("[35mÍüÇéË¿[2;37;0m", ({ "si" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("unit", "¸ù");
		set("long", "ÕâÊÇÓÉ[33mºÚÕäÊ¯[2;37;0m¸¨ÒÔ[31m¼¦Ñª²İ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ù±Ş\n±Ş±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º³ş³ş(chuchu)\n\n");
		set("value", 2250000);
		set("materail", "[33mºÚÕäÊ¯[2;37;0m");
		set("wield_msg", "$NÒ»ÉùÇåĞ¥£¬¶¶³öÒ»¸ù[35mÍüÇéË¿[2;37;0m¡£\n");
		set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË[35mÍüÇéË¿[2;37;0m¡£\n");
	}
	init_whip(30);
	setup();
}
