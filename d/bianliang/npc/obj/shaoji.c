// kaoya.c ��Ѽ

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"�ռ�"NOR, ({"shaoji", "ji"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�ոճ�¯�ĵ����ռ������˿��ž�����ˮ��\n");
		set("unit", "ֻ");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 60);
	}
}
