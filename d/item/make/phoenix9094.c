// ITEM Made by player /d/item/make/phoenix9094.c
// Written by ITEMMAKER(Doing Lu 1998/11/2)	Sun Jun 21 13:21:51 1998
#include <armor.h>

inherit CLOTH;

string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
	set_name("¼×[2;37;0m", ({ "jia" }));
	set_weight(1800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("item_file_name", __FILE__);
		set("unit", "¼ş");
		set("long", "ÕâÊÇÓÉ[1;32m±ù²ÏË¿[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼ş¼×¡£\n¼×ÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º»ğ·ï»Ë(phoenix)\n\n");
		set("value", 12500000);
		set("materail", "[1;32m±ù²ÏË¿[2;37;0m");
		set("wear_msg", "[33m$NËæÊÖÒ»»Ó£¬ÅûÉÏÁË¼×[2;37;0m[33m¡£[2;37;0m\n");
		set("remove_msg", "[33m$NÂÔÎ¢Ò»¶¶£¬ÊÕÆğÁË¼×[2;37;0m[33m¡£[2;37;0m\n");
		set("armor_prop/armor", 170);
	}
	setup();
}
