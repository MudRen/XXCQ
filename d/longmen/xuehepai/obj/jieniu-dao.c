

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;

inherit BLADE;

void create()
{
        set_name(HIY"��ţ��"NOR, ({ "jieniu dao", "dao" }));
          set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ѩ���Ľ�ţ�������м�������Ѫ��������������ƥ��
ӳ���������˵���Ѫ������֮һ��\n");
            set("value", 500000);
               set("no_break",1);
               set("endure",150);
                set("material", "steel");
                set("wield_msg", WHT "ֻ�������һ������ţ��������ת������Ծ��$N���С�\n" NOR);
                set("unwield_msg", WHT "$N��ת��ţ������ৡ��ز��뵶�ʡ�\n" NOR);
        }
          init_blade(60);
        setup();
}

