// ����
//By ɽèadx @ CuteRabbit 19:28 99-5-28

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIM"����"NOR, ({ "jinduan", "jin", "duan" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", HIM"����һ�������Ľ��У�����ĸ����Ǿ���������\n"NOR);
		set("wear_msg", WHT "$N�ó�һ��������"+HIM"����"NOR+WHT"��������\n" NOR);
		set("remove_msg", WHT "$N��"+HIM"����"NOR+WHT"����������������\n" NOR);
                set("material", "cloth");
		set("value", 5000);
                set("armor_prop/armor", 20);
        }
        setup();
}

