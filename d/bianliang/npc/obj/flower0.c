//flower.c

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR "�ʻ�" NOR, ({ "flower" }) );
    set_weight(3);
    if( clonep() )
        set_default_object(__FILE__);
        else {
        set("long", "һ���ʻ���\n");
                set("unit", "��");
                set("value", 0);
         }
    setup();
}

