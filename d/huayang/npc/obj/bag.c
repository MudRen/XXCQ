#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"����"NOR, ({ "bu dai", "bag", "dai" }) );
        set_weight(500);
        set_max_encumbrance(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��Ѱ���Ĳ�������������װһЩ���\n");
                set("value", 100);
        }
}

int is_container() { return 1; }

