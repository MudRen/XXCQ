// fruit.c 
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;          
string* titles = ({
	HIY"��Բ"NOR,
	MAG"����"NOR,
	BLU"����"NOR,
	MAG"��֦"NOR,
});
void create()
{
	set_name(titles[random(sizeof(titles))], ({ "fruit" }));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������ɿڵ�"+titles[random(sizeof(titles))]+"��\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
