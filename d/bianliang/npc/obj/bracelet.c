//bracelet.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
    set_name( HIG "�������" NOR, ({ "bracelet" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "һֻ���µ���������\n");
        set("unit", "ֻ");

        set("value", 100000);


        set("material", "jade");
                set("armor_prop/armor", 0);
        set("armor_prop/personality", 10);
        set("wear_msg", "$N����ؽ�һֻ$n�����������ϡ�\n");
        set("remove_msg", "$N����ذ�һ��$n�����ϳ���������\n");
        set("no_sell",1);
        set("female_only", 1);

        }
        setup();
}


