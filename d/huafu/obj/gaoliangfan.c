// gaoliangfan.c

inherit ITEM;

void create()
{
	set_name("������", ({"gaoliangfan"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������\n");
		set("unit", "��"); 
		set("value", 40);
	}
}