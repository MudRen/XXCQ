// liangong-fu.c

inherit ITEM;

void create()
{
	set_name("´ý¶¨", ({ "huo"}));
	set("long", "´ý¶¨¡£\n");
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "iron");
		set("value", 500);
		set("unit", "·Ý");
	}
	setup();
}