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
	set_name("[35m����˿[2;37;0m", ({ "si" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("unit", "��");
		set("long", "������[33m����ʯ[2;37;0m����[31m��Ѫ��[2;37;0m���ƶ��ɵ�һ����\n�ޱ��Ͽ���һ��С�֣�����(chuchu)\n\n");
		set("value", 2250000);
		set("materail", "[33m����ʯ[2;37;0m");
		set("wield_msg", "$Nһ����Х������һ��[35m����˿[2;37;0m��\n");
		set("unwield_msg", "$N����һĨ��������[35m����˿[2;37;0m��\n");
	}
	init_whip(30);
	setup();
}
