// ITEM Made by player /d/item/make/skills5629.c
// Written by ITEMMAKER(Doing Lu 1998/11/2)	Sat Dec 18 01:50:13 1999
#include <ansi.h>

#include <weapon.h>

inherit SWORD;

string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
	set_name("Áú¹Ç½£[2;37;0m", ({ "sword" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("unit", "°Ñ");
		set("long", "ÕâÊÇÓÉ[33mºÚÕäÊ¯[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñ½£¡£\n½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎä¹¦(skills)\n\n");
		set("value", 3750000);
		set("materail", "[33mºÚÕäÊ¯[2;37;0m");
		set("wield_msg", "$NÒ»ÉùÇåĞ¥£¬¶¶³öÒ»°ÑÁú¹Ç½£[2;37;0m¡£\n");
		set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁËÁú¹Ç½£[2;37;0m¡£\n");
	}
	init_sword(50);
	setup();
}
