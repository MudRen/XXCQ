// Item dashitou.c  
// Created by Zeus 1999.5.27
// Modified by Zeus 1999.5.27
// 
// 

inherit ITEM;

void create()
{
        set_name( "��ʯͷ",({ "da shitou"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���ʯͷ��\n");
                set("value", 100);
                set("material", "stone");
        }
}
