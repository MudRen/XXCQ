
#include <weapon.h>
#include <ansi.h>
inherit ARROW;

void create()
{
        set_name(CYN"����"NOR, ({ "tie gong", "gong" ,"arrow"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ��������һ������ֶ�����˹���\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ���ӱ����ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ر���\n");
        }
        init_arrow(25);
        setup();
}

