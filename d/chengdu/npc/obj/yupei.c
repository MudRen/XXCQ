#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
        set_name(HIW"����"NOR, ({"yu pei", "pei", "yu"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 2000);
		set("long", "һö���壬���滹����һЩͼ����\n");
		set("material", "steel");
		set("armor_prop/armor", 1);
		
        }
	setup();
}

