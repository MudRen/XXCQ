#include <weapon.h>
inherit THROWING;
void create()
{
	set_name("������", ({ "tie lianzi", "lianzi", "zi" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�������Ƶ�����״������\n");
		set("unit", "��");
		set("value", 0);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 0);
		set("damage", 5);
	}
	init_throwing(5);
	setup();
}
