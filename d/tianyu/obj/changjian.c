// longsword.c ����
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
          set_name(HIC"����"NOR, ({ "tianyu sword", "sword", "jian" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ�ľ��ֽ���һ��Ľ��Ͷ�����˽���\n");
                set("value", 100);
                set("sword",1);
                set("nopawn",1);
                set("material", "steel");
                set("wield_msg", HIC"$N��ৡ���һ�����һ��$n"+HIC+"�������С�\n"NOR);
                set("unwield_msg",HIC "$N�����е�$n"+HIC+"��ؽ��ʡ�\n"NOR);
        }
        init_sword(50);
        setup();

}
