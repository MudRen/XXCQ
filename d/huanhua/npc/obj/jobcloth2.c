// liangong-fu.c

inherit ITEM;

void create()
{
	set_name("�ɾ��·�", ({ "ganjing yifu", "ganjing", "yifu", "cloth" }));
	set("long", "����һ���ո�ϴ�õĸɾ��·���\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
	}
	setup();
}