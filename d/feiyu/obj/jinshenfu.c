// Item jinshenfu.c �����
// Created by M.A.D. 1999.7.21
// Modified by M.A.D. 1999.7.21
// 
// 

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIR"�����"NOR, ({ "fu" }));
        set("long", "����һ��" + HIR"�����"NOR + "�����Ƿ����������㡱��ͳһװ������һ���ķ�������\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 200);
                set("armor_prop/armor", 10);
        }
        setup();
}
