// jiuyunjiu.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("æ∆Ã≥", ({"jiuyunjiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "“ªÃ≥…œ∫√µƒæ≈‘Õæ∆°£\n");
		set("unit", "Ã≥");
		set("value", 100);
		set("max_liquid", 5);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "æ≈‘Õæ∆",
		"remaining": 5,
		"supply": 15,
		"drunk_apply": 3,
	]));
}
