// jinjia.c ���

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIY"�����Ӽ�"NOR, ({"jin jia","jinjia", "jia", "armor"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "��");
		set("long", "һ�����߽���֯�͵����ף�ֻ�н������ܴ���\n");
                set("material", "steel");
                set("value", 50000);
		set("wear_msg","����������һ�����죬$N�ѽ�"HIY"�����Ӽ�"NOR"�������ϣ����������棡\n");
                set("armor_prop/armor", 40);
		set("armor_prop/dodge", -10);
        }
        setup();
}


