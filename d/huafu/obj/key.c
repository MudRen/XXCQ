//key.c
inherit ITEM;
void create()
{
     set_name( "Կ��", ({ "bedroomkey" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�����ص�Կ�ס�\n");
                set("value", 0);
                set("material", "iron");
                set("no_drop","�ⶫ�������뿪�㡣\n");
              }
}
