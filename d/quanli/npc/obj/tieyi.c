// jinjia.c ���

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIY"����"NOR, ({"tie yi","tie", "yi", "armor"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "��");
		set("long", "һ���ɷ������Ƭ֯�͵ĺ�ɫ���¡�\n");
                set("material", "steel");
                set("value", 50000);
                set("armor_prop/armor", 20);
		set("armor_prop/dodge", -5);
        }
        setup();
}