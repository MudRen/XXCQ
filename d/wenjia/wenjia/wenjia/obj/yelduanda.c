// Item yelduanda.c ��װ�̴�
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"��װ�̴�"NOR, ({ "duanda" }));
        set("long", "����һ����ɫ��" + HIY"��װ�̴�"NOR + "�������¼ҵ��Ĵ����ӵ�ͳһװ������һ���ķ�������\n");
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
