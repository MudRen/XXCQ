// Item baiguo.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(WHT"�׹�������"NOR, ({"baiguo"}));
        set_weight(400);
        if (clonep()) set_default_object(__FILE__);
        else {
                set("long", "һ���ɰ׹�������Ȳ������ɵĹ������ˡ�\n");
                set("unit", "��");
                set("value", 200);
                set("food_remaining", 5);
                set("food_supply", 50);
        }
}
