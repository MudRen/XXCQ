// Item chouduan.c ���
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(CYN"���"NOR, ({ "chouduan" }));
        set("long", "����һ����ɫ��" + CYN"���"NOR + "���¼�ֻ�е��������Ӳ��ܴ����˷��Σ��ǵ�λ��������\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 200);
                set("armor_prop/armor", 30);
        }
        setup();
}
