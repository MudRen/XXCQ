// Item unknownp.c  ��֪����ҩ
// Created by Zeus 1999.5.27
// Modified by Zeus 1999.5.29
// 
// 

inherit ITEM;

void create()
{
        set_name( "��֪����ҩ",({ "du yao"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��Сֽ��������װ��һЩ��ɫ�ķ�ĩ����ô��Ҳ��������ʲô��ҩ��\n");
                set("value", 50);
                set("material", "unknown");
        }
}
