// laozi16.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( WHT"��ѧ�¾�"NOR, ({ "daxue", "book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","Sorry,��Ҳû������

	��С��\n");
		set("value", 6000);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",
			"exp_required":	0,
			"jingli_cost":  45,
			"difficulty":	10,
			"max_skill":	115,
			"min_skill":	90,
		]) );
	}
}