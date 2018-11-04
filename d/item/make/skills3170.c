// ITEM Made by player /d/item/make/skills3170.c
// Written by ITEMMAKER(Doing Lu 1998/11/2)	Sat Dec 18 01:45:07 1999
#include <armor.h>

inherit CLOTH;

string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
	set_name("armor[2;37;0m", ({ "ÁúÁÛ¼×" }));
	set_weight(2400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("item_file_name", __FILE__);
		set("unit", "¼ş");
		set("long", "ÕâÊÇÓÉ[1;32m²ø»êË¿[2;37;0m¸¨ÒÔ[31m¼¦Ñª²İ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼ş¼×\n¼×ÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎä¹¦(skills)\n\n");
		set("value", 2250000);
		set("materail", "[1;32m²ø»êË¿[2;37;0m");
		set("wear_msg", "[33m$NËæÊÖÒ»»Ó£¬ÅûÉÏÁËarmor[2;37;0m[33m¡£[2;37;0m\n");
		set("remove_msg", "[33m$NÂÔÎ¢Ò»¶¶£¬ÊÕÆğÁËarmor[2;37;0m[33m¡£[2;37;0m\n");
		set("armor_prop/armor", 30);
	}
	setup();
}
