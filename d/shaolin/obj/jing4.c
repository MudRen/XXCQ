// fojing11.c

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

string* titles = ({
	"�����۾�",
	"���о�",
	"������",
	"Ħ�ɾ�",
	"���۱�",
});

void create()
{
	set_name(YEL + titles[random(sizeof(titles))] + NOR, ({ "jing", "shu", "book" }));
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��𾭣���ҳ�Ѿ����ƣ���������������µ�����˼�롣\n");
		set("value", 1000);
		set("material", "paper");
		set("replace_file", "/d/shaolin/obj/jing1");
		set("skill", ([
			"name":	"buddha",
			"exp_required" : 0,
			"jingli_cost" :	50,
			"difficulty" : 20,
			"min_skill" : 41,
			"max_skill" : 80,
		]));
	}
}