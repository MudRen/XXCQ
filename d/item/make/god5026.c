// ITEM Made by player /d/item/make/god5026.c
// Written by ITEMMAKER(Doing Lu 1998/11/2)	Sun Dec 19 11:56:13 1999
#include <ansi.h>

#include <weapon.h>

inherit SWORD;

string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
	set_name("[1;31m���񱦽�[2;37;0m", ({ "godsword" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("unit", "��");
		set("long", "������[1;33m�����ë[2;37;0m����[1;32m����֮Ѫ[2;37;0m���ƶ��ɵ�һ�ѽ�\n�����Ͽ���һ��С�֣�����(god)\n\n");
		set("value", 500000000);
		set("materail", "[1;33m�����ë[2;37;0m");
		set("wield_msg", "$Nһ����Х������һ��[1;31m���񱦽�[2;37;0m��\n");
		set("unwield_msg", "$N����һĨ��������[1;31m���񱦽�[2;37;0m��\n");
	}
	init_sword(8600);
	setup();
}
