// laozi16.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( WHT"ʫ��"NOR, ({ "shijing", "book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","�й���һ��ʫ����\n");
		set("value", 4000);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",
			"exp_required":	0,
			"jingli_cost":  35,
			"difficulty":	10,
			"max_skill":	95,
			"min_skill":	70,
		]) );
	}
}