// sengxie ɮЬ
// by Load

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIC "ɮЬ" NOR, ({ "seng xie", "xie", "shoes" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "һ˫�ֹ����Ƶ��಼ɮЬ��\n");
		set("value", 200);
		set("material", "boots");
		set("armor_prop/dodge", 5);
	}
	setup();
}