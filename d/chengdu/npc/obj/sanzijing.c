// laozi16.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( WHT"���־�"NOR, ({ "sanzi jing", "sanzi", "jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ������ʶ�ֵĿα�������д�ţ���֮�����Ա��ƣ����������\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jingli_cost":  10, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	40,	// the maximum level you can learn
		]) );
	}
}
