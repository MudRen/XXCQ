// lugu.c ¹��

inherit ITEM;

void create()
{
	set_name("¹��", ({"lu rong", "rong"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һζ��������ҩ�ģ�¹�ס�\n");
		set("unit", "��");
		set("value", 1500);
	}
}