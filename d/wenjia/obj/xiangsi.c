// Item xiangsi.c
// Created by Zeus 1999.4.3
// Modified by Zeus 1999.4.3
// 
// 

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_fang", "diu");
}

void create()
{
        set_name("��˼������", ({"xiang si"}));

        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��СС�ĺ��ӣ�һ��Ҳ����������������ʿ��֮ɫ����¼���������˼�����С���\n");
                set("value", 500000);
        }
        init_blade(100);
        setup();
}

int do_fang(string arg)
{
        object me, obj;
        me = this_player();

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if(obj == me)
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
        message_vision(HIY "\n$N������˼�����С�����$n�ų��� \n\n"NOR, me, obj);

        tell_object(obj, HIR "\n���;���������հ��ʹ����־������ͷ����һƬ�հף�\n" NOR);

        obj->die();
        destruct(this_object());

        return 1;
}
