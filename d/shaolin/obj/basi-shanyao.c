// basi-shanyao.c ��˿ɽҩ
// by Load

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIM"��˿ɽҩ"NOR, ({"basi shanyao", "shanyao", "basi"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ɫ��õ�壬�������۵İ�˿ɽҩ��\n");
		set("unit", "��");
		set("value", 1);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
