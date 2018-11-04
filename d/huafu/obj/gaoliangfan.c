// gaoliangfan.c

inherit ITEM;

void create()
{
	set_name("¸ßÁ»·¹", ({"gaoliangfan"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»Íë¸ßÁ»·¹¡£\n");
		set("unit", "Íë"); 
		set("value", 40);
	}
}