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
	set_name("armor[2;37;0m", ({ "���ۼ�" }));
	set_weight(2400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("item_file_name", __FILE__);
		set("unit", "��");
		set("long", "������[1;32m����˿[2;37;0m����[31m��Ѫ��[2;37;0m���ƶ��ɵ�һ����\n���Ͽ���һ��С�֣��书(skills)\n\n");
		set("value", 2250000);
		set("materail", "[1;32m����˿[2;37;0m");
		set("wear_msg", "[33m$N����һ�ӣ�������armor[2;37;0m[33m��[2;37;0m\n");
		set("remove_msg", "[33m$N��΢һ����������armor[2;37;0m[33m��[2;37;0m\n");
		set("armor_prop/armor", 30);
	}
	setup();
}
