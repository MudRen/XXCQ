// ITEM Made by player /d/item/make/adx2908.c
// Written by ITEMMAKER(Doing Lu 1998/11/2)	Sat Dec 18 00:25:55 1999
#include <armor.h>

inherit CLOTH;

string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
	set_name("[1;32m���ϱ���[2;37;0m", ({ "armor" }));
	set_weight(1800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("item_file_name", __FILE__);
		set("unit", "��");
		set("long", "������[1;32m����˿[2;37;0m����[1;36m���ɰ[2;37;0m���ƶ��ɵ�һ����\n���Ͽ���һ��С�֣�ɽè(adx)\n\n");
		set("value", 15000000);
		set("materail", "[1;32m����˿[2;37;0m");
		set("wear_msg", "[33m$N����һ�ӣ�������[1;32m���ϱ���[2;37;0m[33m��[2;37;0m\n");
		set("remove_msg", "[33m$N��΢һ����������[1;32m���ϱ���[2;37;0m[33m��[2;37;0m\n");
		set("armor_prop/armor", 210);
	}
	setup();
}
