// jitui.c ����

#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name(YEL"��ţ��"NOR, ({ "jiang niurou", "jiang", "niurou", "rou" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ��ɢ���Ž���Ľ�ţ�⡣\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
	setup();
}