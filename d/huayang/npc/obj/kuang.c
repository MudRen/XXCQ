#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"���"NOR, ({ "kuang" }) );
        set_weight(1000);
        set_max_encumbrance(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ƾ�ϸ���������װһЩ���\n");
                set("value", 100);
        }
}

int is_container() { return 1; }

