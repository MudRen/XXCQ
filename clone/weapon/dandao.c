#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(WHT"����"NOR, ({"dan dao","dandao", "dao", "blade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1500);
                set("material", "iron");
                set("rendu", 150);
                set("long", "����һѰ���ĵ����������ߴ糤,��Լ�����߽��ء�\n");
                set("wield_msg", "$N���һ�����λε�$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
        init_blade(15);
        setup();
}
