// red_silk.c

#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
        set_name(RED"��˿��"NOR, ({ "red silk", "silk" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ����������ĺ�˿������������һ���������޵ĸо���\n");
		set("unit", "��");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "cloth");       
                set("armor_prop/armor", 1);
        }
	setup();
}
