// /d/taohua/teibagua.c
// adx 3:55 99-2-6
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT"���־�"NOR, ({ "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", WHT"����һ��С�������飬����Զ�"HIW+
			"��du book��"NOR+WHT"�����Ӷ���д�֡�\n"NOR);
		set("value", 100);
		set("material", "silk");
		set("skill", ([
			"name":	"literate",
			"exp_required":	0,
			"jing_cost":	20,
			"difficulty":	20,
			"max_skill":	20
		]) );
	}
}
