// item: turou.c
// Created by Zeus 1999.4.10
// Modified by M.A.D. 1999.7.21
// 
// 

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"tu rou", "tu"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����Ѫ�����Ұ���⡣\n");
                set("unit", "��");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}
