// marry_dress
#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name( HIW "��ɫ��ɴ" NOR, ({ "dress" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/personality", 5);
                set("armor_prop/armor", 3);
                set("wear_msg","$N����һ��$n��\n");
                set("remove_msg","$��$n����������\n");
        }
}

