// Item yaolou.c  
// Created by Zeus 1999.7.30
// Modified by Zeus 1999.7.30
// 
// 

inherit ITEM;

void create()
{
        set_name( "ҩ¨",({ "yao lou"}));
        set_weight(500);
        set_max_encumbrance(80000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��ҩ¨��\n");
                set("value", 100);
                set("material", "bamboo");
        }
}
