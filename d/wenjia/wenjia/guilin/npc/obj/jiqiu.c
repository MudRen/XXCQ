// Item jiqiu.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"���㳴����"NOR, ({"jiqiu"}));
        set_weight(400);
        if (clonep()) set_default_object(__FILE__);
        else {
                set("long", "һ�����ط������Ĺ������ˡ�\n");
                set("unit", "��");
                set("value", 400);
                set("food_remaining", 5);
                set("food_supply", 80);
        }
}
