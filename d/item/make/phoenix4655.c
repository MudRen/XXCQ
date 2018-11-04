// ITEM Made by player /d/item/make/phoenix4655.c
// Written by ITEMMAKER(Doing Lu 1998/11/2)	Sat Dec 18 15:22:36 1999
#include <armor.h>

inherit CLOTH;

string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
	set_name("[1;36m÷è÷ëÖ®¼×[2;37;0m", ({ "jia" }));
	set_weight(1800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("item_file_name", __FILE__);
		set("unit", "¼ş");
		set("long", "ÕâÊÇÓÉ[1;32m±ù²ÏË¿[2;37;0m¸¨ÒÔ[1;36m½ğ¸ÕÉ°[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼ş¼×\n¼×ÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º»ğ·ï»Ë(phoenix)\n\n");
		set("value", 15000000);
		set("materail", "[1;32m±ù²ÏË¿[2;37;0m");
		set("wear_msg", "[33m$NËæÊÖÒ»»Ó£¬ÅûÉÏÁË[1;36m÷è÷ëÖ®¼×[2;37;0m[33m¡£[2;37;0m\n");
		set("remove_msg", "[33m$NÂÔÎ¢Ò»¶¶£¬ÊÕÆğÁË[1;36m÷è÷ëÖ®¼×[2;37;0m[33m¡£[2;37;0m\n");
		set("armor_prop/armor", 210);
	}
	setup();
}
