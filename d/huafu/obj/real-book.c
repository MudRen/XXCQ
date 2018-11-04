// sword_book.c

inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIW"һҶ�ؼ�"NOR, ({ "yiye miji", "miji" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"һ�����ƵĹ��飬�������ÿ���д����һҶ�ؼ�����\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name": 	"yiye-zhiqiu",	// name of the skill
			"exp_required":	500000,		// minimum combat experience required
							// to learn this skill.
			"jingli_cost":	30,		// jing cost every time study this
			"difficulty":	30,		// the base int to learn this skill
							// modify is jing_cost's (difficulty - int)*5%
             "max_skill":    280     // the maximum level you can learn
							// from this object.
		]) );
	}
}
