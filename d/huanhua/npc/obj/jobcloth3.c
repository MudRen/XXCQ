// liangong-fu.c

inherit ITEM;

void create()
{
	set_name("���·�", ({ "po yifu", "po", "yifu", "cloth" }));
	set("long", "����һ����ϴ���˵��·���\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
	}
	setup();
}