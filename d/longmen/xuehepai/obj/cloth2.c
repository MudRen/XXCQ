// cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
          set_name(YEL"һ����"RED"Ѫ��"NOR, ({ "xue yi", "yi", "cloth" }) );
        set("long","����Ѫ���ɵ��Ӵ��Ĵ�����ݵ��·���\n����б����һ�������\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}
