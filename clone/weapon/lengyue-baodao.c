// lengyue-baodao

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIW"���±���"NOR, ({ "lengyue dao", "blade" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIW"����һ�ѷ����ı������������ý�˿��˿����һ��üë
��֮�Ρ�\n"NOR);
                set("value", 100000);
                set("material", "steel");
                set("weapon/strength", 10);
                set("wield_msg", HIW "ֻ����ɭɭ��һ����⼤�������������˸����
,���±�������$N�����\n" NOR);
                set("unwield_msg", HIW "��ৡ���һ���������Ѳ��������±�����$N��
�����С�\n" NOR);
        }
        init_blade(1000);
        setup();
}
