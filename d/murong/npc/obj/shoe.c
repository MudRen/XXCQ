// shoes.c
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(GRN"̤ѩ�޺�"NOR, ({ "shoes", "xie" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","����һ˫С�ɵ�Ů��Ь��\n");        
                set("unit", "˫");
                set("material", "boots");
                set("armor_prop/dodge", 1);
        }
        setup();
}
