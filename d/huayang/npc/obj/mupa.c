
#include <weapon.h>
#include <ansi.h>
inherit FORK;

void create()
{
        set_name(YEL"ľ��"NOR, ({"mu pa", "pa", "fork"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 400);
                set("material", "wood");
		set("distance", 3);
                set("long", "����һ��������ľ�ң�����ɹ��ʳʱ���õġ�\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
        }
        init_fork(10);
        setup();
}

