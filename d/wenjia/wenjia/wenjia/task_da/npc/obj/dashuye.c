// Item dashuye.c
// Created by Zeus 1999.5.27
// Modified by Zeus 1999.5.27
// 
// 

inherit ITEM;

void create()
{
        set_name( "����Ҷ",({ "da shuye"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ƭ");
                set("long","����һƬ��Ҷ��\n");
                set("value", 50);
                set("material", "wood");
        }
}
