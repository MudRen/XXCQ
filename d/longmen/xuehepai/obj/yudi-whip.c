
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;

inherit WHIP;

void create()
{
        set_name(HIW"��ر�"NOR, ({ "yudi bian", "bian","whip" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������鱦����رޡ��˱���Ѫ������֮һ��\n");
          set("value", 500000);
               set("no_break",1);
               set("endure",120);
                set("material", "steel");
                set("wield_msg", HIR "$Nವ�һ���������������رޡ�\n" NOR);
                set("unwield_msg", HIR "$N����ر��̺ã����������䡣\n" NOR);
        }
          init_whip(60);
        setup();
}

