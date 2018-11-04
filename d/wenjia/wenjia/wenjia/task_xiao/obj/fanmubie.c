// Item fanmubie.c
// Created by Zeus 1999.7.31
// Modified by Zeus 1999.7.31
// 
// 

inherit ITEM;

void init();
int do_eat(string arg);

void create()
{
        set_name( "·¬Ä¾±î",({ "fanmubie"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿Ã");
                set("long","ÕâÊÇÒ»¿Ã·¬Ä¾±î¡£\n");
                set("value", 10000);
                set("material", "");
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;
        me=this_player();
        message_vision("$N³ÔÏÂÒ»¿Ã·¬Ä¾±î£¬ÊÖ½ÅÕõÔúÁË¼¸ÏÂ£¬ÖĞ¶¾ËÀÁË¡£",me);
        me->die();
        destruct(this_object());
        return 1;
}
