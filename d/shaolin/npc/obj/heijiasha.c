// heijiasha.c ��ߺڲ�����
// by Load

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY"���"HIB"�ڲ�"HIY"����"NOR, ({ "jia sha", "sha", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ����ɴ���ơ���˿�ɱߵ����ģ��������޺��������ġ�\n");
		set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

