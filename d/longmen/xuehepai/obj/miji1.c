// laozi16.c

#include <ansi.h>

inherit ITEM;

void create()
{
         set_name( CYN"�����ؼ�"NOR, ({ "book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                 set("long","����һ����ѧ�����鼮��\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
                        "name": "longmen-shengong",        // name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jingli_cost":  15, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
             "max_skill" : 60,
		]) );
	}
}
