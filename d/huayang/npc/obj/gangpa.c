// rake.c

#include <weapon.h>
#include <ansi.h>

inherit FORK;

void create()
{
        set_name(HIW"�ְ�"NOR, ({ "gang pa", "pa","rake" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("material", "iron");
		set("distance", 3);
                set("long", "һ���������߳ݸְң�����ɹ��ʳʱ���õġ�\n");
                set("wield_msg", "$N����һ��$n����ͷ�ϻ�����һȦ��\n");
        }
        init_fork(20);
        setup();
}