// Item facai.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BLK"��������"NOR, ({"routuan"}));
        set_weight(400);
        if (clonep()) set_default_object(__FILE__);
        else {
                set("long", "һ���ɷ��˲��������ƳɵĹ������ˡ�\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 6);
                set("food_supply", 80);
        }
}
