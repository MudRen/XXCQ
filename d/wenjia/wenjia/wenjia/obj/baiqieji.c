// Item baiqiuji.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.3.27
// 
// 

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���м�", ({"ji","baiqie ji"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ոճ�¯�İ��м��������¼������³Է��������ġ����ŵ�������ζ�̲�ס����ˮ��\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}
