// sugar.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        string *order = ({HIW "�����" NOR,HIM "����" NOR, HIY "��÷" NOR, HIR "�����ɿ���" NOR, HIG "����" NOR});
        set_name( (order[random(5)]), ({ "sugar" }) );
        set_weight(80);
        set("value", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���߼�ϲ�ǡ�\n");
                set("unit", "��");
                set("food_remaining", 2);
                set("food_supply", 10);

        }
}

