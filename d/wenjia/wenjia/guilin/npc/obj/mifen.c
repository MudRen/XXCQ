// Item mifen.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BLU"���������׷�"NOR, ({"mifen"}));
        set_weight(400);
        if (clonep()) set_default_object(__FILE__);
        else {
                set("long", "һ�����ط������������׷ۣ������Ĺ��ַ�ζС�ԡ�\n");
                set("unit", "��");
                set("value", 300);
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}
