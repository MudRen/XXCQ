// tiezhitao.c ��ָ��
// by Load 

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name( WHT"��ָ��"NOR, ({ "zhi tao", "tao", "zhi" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "�������������������ָ�ף����Ա���ָ�ؽڡ�\n");
		set("value", 800);
		set("material", "finger");
		set("armor_prop/armor", 5);
	}
	setup();
}
