// ITEM Made by player /d/item/make/god8521.c
// Written by ITEMMAKER(Doing Lu 1998/11/2)	Sun Dec 19 11:49:22 1999
#include <armor.h>

inherit CLOTH;

string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
	set_name("[1;31m����ս��[2;37;0m", ({ "godjia" }));
	set_weight(12000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("item_file_name", __FILE__);
		set("unit", "��");
		set("long", "������[1;36m��������[2;37;0m����[1;32m����֮Ѫ[2;37;0m���ƶ��ɵ�һ����\n���Ͽ���һ��С�֣�����(god)\n\n");
		set("value", 500000000);
		set("materail", "[1;36m��������[2;37;0m");
		set("wear_msg", "[33m$N����һ�ӣ�������[1;31m����ս��[2;37;0m[33m��[2;37;0m\n");
		set("remove_msg", "[33m$N��΢һ����������[1;31m����ս��[2;37;0m[33m��[2;37;0m\n");
		set("armor_prop/armor", 8100);
	}
	setup();
}
