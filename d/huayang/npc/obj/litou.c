// plow.c

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(CYN"��ͷ"NOR, ({"li tou", "plow", "li"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѻ��������ͷ������ȥȷʵֻ����ţ�����ö���\n");
                set("value", 5000);
                set("material", "iron");
		set("distance", 1);
                set("wield_msg", "$N������$n������ʵ��̫�����֣��ɴ౧�ڻ��\n");
                set("unwield_msg", "$N�������е�$n���۵û����ǳ������Ϳ������ˡ�\n");
        }

        init_hammer(25);
        setup();
}

