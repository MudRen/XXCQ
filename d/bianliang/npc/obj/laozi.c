// laozi.c

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name( WHT"�����ļ�"NOR, ({ "laozi wenji", "wenji", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ������ѧ������

    ����\n");
        set("value", 180000);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",
			"exp_required":	0,
            "jingli_cost":  100,
			"difficulty":	10,
            "max_skill":    210,
            "min_skill":    180,
		]) );
	}
}
