// boots.c Ƥѥ
 
#include <armor.h>
#include <ansi.h>

inherit BOOTS;
 
void create()
{
	set_name(CYN"Ƥѥ"NOR, ({ "pi xue", "xue", "shoes" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "˫");
		set("long", "����һ˫���Ϻ�ţƤ����Ƥѥ����˵���Ϻ����ڡ����Ա����㲿��\n");
		set("value", 500);
		set("armor_prop/dodge", 5);
		set("armor_prop/armor", 3);
	}
	setup();
}