#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"�����"NOR,({"zhentian gu","gu"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���ġ�\n");
                set("value", 0);
                set("material", "skin");
                set("no_drop","�ⶫ�������뿪�㡣\n");
              }
}


