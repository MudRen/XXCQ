// shanhu-baicai.c ɺ���ײ�
// by Load

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"ɺ���ײ�"NOR, ({"shanhu baicai", "shanhu", "baicai"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������䣬����ˬ�ڣ��������˵�ɺ���ײˡ�\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
