// Item sanzijing.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.3.28
// 
// 

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( "���־�", ({ "sanzijing"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        CYN
                        "\n\t��֮�����Ա��ơ�\n"
                        NOR
                );
                set("value", 500);
		set("material", "paper");
                set("skill", ([
                        "name":"literate",      // name of the skill
                        "exp_required":	0,      // minimum combat experience required
                        "jingli_cost": 10,      // jing cost every time study this
                        "difficulty":  15,      // the base int to learn this skill
                        "max_skill":   31,      // the maximum level you can learn
                ]) );
        }
}
