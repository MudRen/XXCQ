// qinghulu.c ��ˮ��«
// by Load

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(CYN"��ˮ��«"NOR, ({"hulu", "bottle"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������«�Ƴɵ�ˮ������������Я����\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 10);
	}

	set("liquid", ([
		"type": "water",
		"name": "ɽȪˮ",
		"remaining": 10,
		"drunk_supply": 30,
	]));
}