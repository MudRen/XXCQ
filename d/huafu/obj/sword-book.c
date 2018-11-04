// sword_book.c

inherit ITEM;

void create()
{
	set_name("��������--�����ƪ��", ({ "sword book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"������д������������ -- �����\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name": 	"sword",	// name of the skill
			"exp_required":	10000,		// minimum combat experience required
							// to learn this skill.
			"jingli_cost":	25,		// jing cost every time study this
			"difficulty":	25,		// the base int to learn this skill
							// modify is jing_cost's (difficulty - int)*5%
            "max_skill":    100,     // the maximum level you can learn
            "min_skill":    30,
		]) );
	}
}
