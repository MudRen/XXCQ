// ITEM Made by player /d/item/make/skills8737.c
// Written by ITEMMAKER(Doing Lu 1998/11/2)	Sat Dec 18 01:11:07 1999
#include <armor.h>

inherit CLOTH;

string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
	set_name("ÁúÁÛ¼×[2;37;0m", ({ "armor" }));
	set_weight(2400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("item_file_name", __FILE__);
		set("unit", "¼ş");
		set("long", "ÕâÊÇÓÉ[1;32m²ø»êË¿[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼ş¼×¡£\n¼×ÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎä¹¦(skills)\nÕâÊÇ´ÓÁúÉíÉÏÄÃÀ´µÄÁúÁÛ¼×[2;37;0m\n");
		set("value", 3750000);
		set("materail", "[1;32m²ø»êË¿[2;37;0m");
		set("wear_msg", "Ö»¼ûÒ»Éù¾ŞÏì¡£¡£¡£ÁúÁÛ¼×ÒÔ´©ÔÚÄãÉíÉÏÁË![2;37;0m\n");
		set("remove_msg", "[33m$NÂÔÎ¢Ò»¶¶£¬ÊÕÆğÁËÁúÁÛ¼×[2;37;0m[33m¡£[2;37;0m\n");
		set("armor_prop/armor", 50);
	}
	setup();
}
