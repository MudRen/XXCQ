#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name("����", ({ "hammer" }) );
        set_weight(8500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ�Ĵ��ӡ�\n");
                set("value", 0);
                set("no_drop",1 );
                set("material", "copper");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(25);
        setup();
}

