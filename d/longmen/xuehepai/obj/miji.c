// laozi16.c

#include <ansi.h>

inherit ITEM;

void create()
{
         set_name( CYN"��Ѫ�ؼ�"NOR, ({ "book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                 set("long","����һ����ѧ�����鼮��\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
                         "name": "huaxue-dafa",        // name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jingli_cost":  15, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
                         "min_skill":    100,     // the maximum level you can learn
                         "max_skill":    200,     // the maximum level you can learn
		]) );
	}
}
