//begonia.c
//by chx 5/21/98

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(HIM "���Ļ�" NOR, ({ "begonia","flower" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�使�������ĺ��Ļ���\n");
                set("unit", "��");
                set("value", 6);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
                set("female_only", 1);

        }
        setup();
}

