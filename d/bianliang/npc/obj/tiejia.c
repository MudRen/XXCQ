// jinjia.c ���

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIB"������"NOR, ({"hantie jia","jia", "armor"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "��");
		set("long", "һ���Ϻú�����������ף������������⣮\n");
                set("material", "steel");
                set("value", 50000);
		set("wear_msg","����һ����$N�ѽ�"HIB"������"NOR"��������ƽ��һ�����䣡\n");
                set("armor_prop/armor", 30);
		set("armor_prop/dodge", -5);
        }
        setup();
}


