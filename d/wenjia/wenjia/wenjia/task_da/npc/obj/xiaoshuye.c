// Item xiao shuye.c
// Created by Zeus 1999.5.27
// Modified by Zeus 1999.5.27
// 
// 

inherit ITEM;

void create()
{
        set_name( "С��Ҷ",({ "xiao shuye"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ƭ");
                set("long","����һƬС��Ҷ��\n");
                set("value", 50);
                set("material", "wood");
        }
}
