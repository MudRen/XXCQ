// wlywine.c

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIW "����Һ" NOR, ({ "wly","wine" }) );
        set_weight(10);
        if( clonep() )
             set_default_object(__FILE__);
        else {
        set("long", "һ������Һ��\n");
                set("unit", "��");
                set("value", 0);
                set("max_liquid", 20);
        }
        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "alcohol",
                "name": "����Һ",
                "remaining": 20,
                "drunk_apply": 5,
        ]) );
}

