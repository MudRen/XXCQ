// jinsijia.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIY"�������"NOR, ({ "jinjia tieyi", "jinjia","tieyi"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_put", "1");
                set("no_beg", "1");
                set("no_drop", "1");
                set("no_steal", "1");
                set("value", 30000);
                set("material", "cloth");
                set("armor_prop/armor", 100);
        }
        setup();
}

