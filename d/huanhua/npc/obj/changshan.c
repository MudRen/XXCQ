// longpao.c
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(WHT"֯������"NOR, ({"zhijin changshan","changshan","shan","cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("long",
"һ����ɫ��佻�֯�����Ƶĳ������ʵطǳ��Ĳ�������Ҳ�ܺá�\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 10);
             }
	setup();
}

