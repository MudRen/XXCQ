
#include <weapon.h>

inherit RAKE;

void create()
{
        set_name("ľ��", ({"mu pa", "pa", "rake"}));
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
        init_rake(10);
        setup();
}

