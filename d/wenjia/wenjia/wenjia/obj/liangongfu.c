// Item liangongfu.c ������
// Created by Zeus 1999.7.2
// Modified by Zeus 1999.7.2
// 
// 


#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("������", ({ "liangong fu", "cloth" }));
        set("long", "����һ���е�ɵ������������Ϻõ��鲼�Ƴɣ����൱�ķ�������\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 200);
                set("armor_prop/armor", 5);
                }
        setup();
}
