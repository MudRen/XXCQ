// tiehuwan.c ������
// by Load

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name( WHT"������"NOR, ({ "hu wan", "huwan", "wan" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
                set("long", "����һ��Ƥ�ʵĻ��������������������Ա����󲿡�\n");
		set("value", 300);
		set("material", "wrists");
		set("armor_prop/armor", 4);
	}
	setup();
}
