// liutiao.c ����

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(GRN"�ϳ����ص�������"NOR,({ "liu tiao", "liutiao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֦");
                set("value", 0);
                set("material", "bamboo");
                set("long", "����һ֦��������\n");
        }
        setup();
}
