// lugu.c Ұ¹��

inherit ITEM;

void create()
{
	set_name("¹��", ({"lu gu", "gu", "bone"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ո��޳�����Ұ¹��ͷ��\n");
		set("unit", "��");
		set("value", 300);
	}
}