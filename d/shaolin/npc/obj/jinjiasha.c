// jinjiasha.c ��������
// by Load

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY"��������"NOR, ({ "jia sha", "sha", "cloth" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ�����ӲӵĽ������ģ�ֻ�����ָ�ɮ�ſɴ��š�\n");
		set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 30);
        }
        setup();
}

