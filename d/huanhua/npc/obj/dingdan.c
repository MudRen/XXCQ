// liangong-fu.c

inherit ITEM;

void create()
{
	set_name("����", ({ "dan"}));
	set("long", "������\n");
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "paper");
		set("value", 60);
		set("unit", "��");
	}
	setup();
}