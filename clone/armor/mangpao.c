// ����
//By ɽèadx @ CuteRabbit 19:28 99-5-28

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIR"����"NOR, ({ "mangpao", "mang", "pao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", HIM"����һ�����ۣ���͢���ٵĹٷ���һ���˲�����㴩����\n"NOR);
                set("material", "cloth");
		set("value", 50000);
                set("armor_prop/armor", 50);
        }
        setup();
}

