// lurou.c Ұ¹��

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("¹��", ({"lu rou", "rou"}));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����Ѫ�����Ұ¹�⣬�ܲ��ġ�\n");
		set("unit", "��");
		set("value", 300);
		set("food_remaining", 5);
		set("food_supply", 60);
	}
}