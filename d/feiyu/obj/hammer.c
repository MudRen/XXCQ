// Item yaochu.c  
// Modified by zeus@blade.sword.smile Oct.14.1999
// 

inherit ITEM;

void create()
{
        set_name( "����",({ "hammer"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��������\n");
                set("value", 100);
                set("material", "iron");
        }
}
