// peizi.c

inherit ITEM;

void create()
{
	set_name("����", ({"peizi"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ƾƵ�ԭ�ϡ�\n");
		set("unit", "��"); 
		set("value", 40);
	}
}