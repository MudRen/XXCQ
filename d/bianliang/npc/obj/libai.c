// laozi16.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( WHT"���ȫ��"NOR, ({ "libaiquanji", "book", "libai","shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","��ף�����̫�ף��˳ƾ��ɡ�ʫ�ɡ����ɡ�\n");
		set("value", 2000);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",
			"exp_required":	0,
			"jingli_cost":  25,
			"difficulty":	10,
			"max_skill":	75,
			"min_skill":	50,
		]) );
	}
}