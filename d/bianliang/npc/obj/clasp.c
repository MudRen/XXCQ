//clasp.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name( YEL "������" NOR, ({ "clasp" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "һ֧��˿�߱��������λ���\n");
        set("unit", "֧");

        set("value", 100000);


        set("material", "gold");
                set("armor_prop/armor", 0);
        set("armor_prop/personality", 15);
        set("wear_msg", "$N����ذ�һ֧$n���ڷ����ϡ�\n");
        set("remove_msg", "$N����ذ�һ֧$n�ӷ����ϳ���������\n");

                set("female_only", 1);

        }
        setup();
}

