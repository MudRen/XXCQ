// lupi.c Ұ¹Ƥ

inherit ITEM;

void create()
{
	set_name("Ұ¹Ƥ", ({"lu pi", "pi"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������Ұ¹Ƥ������ȥ����⻬��\n");
		set("unit", "��");
		set("value", 200);
	}
}