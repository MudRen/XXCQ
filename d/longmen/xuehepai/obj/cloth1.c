// cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(RED"Ѫ��"NOR, ({ "xue yi", "yi", "cloth" }) );
        set("long","����Ѫ���ɵͼ����Ӵ��Ĵ�����ݵ��·���\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}


