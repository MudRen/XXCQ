// longsword.c ����

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(WHT"����"NOR, ({ "chang jian", "jian", "sword" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����߳�����ͨ��������һ��Ľ��Ͷ�����˽���\n");
                set("value", 1500);
                set("material", "iron");
                set("rendu", 110);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(15);
        setup();
}
