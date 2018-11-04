// liangong-fu.c

inherit ITEM;

void create()
{
	set_name("´ý¶¨", ({ "dan"}));
	set("long", "´ý¶¨¡£\n");
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "paper");
		set("value", 60);
		set("unit", "ÕÅ");
	}
	setup();
}