

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIC"��ɽ��"NOR, ({ "poshan dao", "dao" }));
          set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                 set("long", "����һ���ƾɲ����ĸֵ������滹��ȱ�ڡ�\n");
            set("value", 10000);
                set("no_break",1);
                set("material", "steel");
                set("wield_msg", YEL "$N�ӱ�����һ�Ѻܲ����۵ĵ���\n" NOR);
                set("unwield_msg", YEL "$NС������İ�����Ƶ����øɾ������ڱ���\n" NOR);
        }
         init_blade(70);
        setup();
}

