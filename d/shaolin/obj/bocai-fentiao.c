// bocai-fentiao.c ���˷���
// by Load

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIG"���˷���"NOR, ({"bocai fentiao", "fentiao", "bocai"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������䣬����ɿڵĲ��˷�����\n");
		set("unit", "��");
		set("value", 1);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
