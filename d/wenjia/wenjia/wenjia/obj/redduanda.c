// Item redduanda.c ��װ�̴�
// Created by Zeus 1999.5.28
// Modified by Zeus 1999.5.28
// 
// 

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIR"��װ�̴�"NOR, ({ "duanda" }));
        set("long", "����һ����ɫ��" + HIR"��װ�̴�"NOR + "�������¼ҵ��������ӵ�ͳһװ������һ���ķ�������\n");
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
