// Item baiqiuji.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.3.27
// 
// 

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"zhu","ru zhu"}));
        set_weight(40);
        if (clonep())
	set_default_object(__FILE__);
        else {
                set("long", "һֻ���÷��������ζ��һ����\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}
