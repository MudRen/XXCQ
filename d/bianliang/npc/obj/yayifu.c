// yayi_cloth.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(WHT"���۷�"NOR, ({ "yayi fu", "fu", "cloth" }));
	set("long", "����һ��ո�µİ��޲����ɵ����۷�����\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 300);
		set("armor_prop/armor", 5);
	}
	setup();
}
