// Item dashuzhi.c
// Created by Zeus 1999.5.27
// Modified by Zeus 1999.5.27
// 
// 

inherit ITEM;

void create()
{
        set_name( "����֦",({ "da shuzhi"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֦");
                set("long","����һ֦����֦��\n");
                set("value", 100);
                set("material", "wood");
        }
}
