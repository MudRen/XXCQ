// bocai-fentiao.c ��֭��ź

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(WHT"��֭��ź"NOR, ({"mizhi tianou", "tianou"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������Ŵ��ɫ��ۺ����֭��ź��\n");
		set("unit", "��");
		set("value", 1);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
