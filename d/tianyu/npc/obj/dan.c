// dan.c
//Write by godzilla

inherit ITEM;
#include <ansi.h>

void create()
{
        string *name=({HIY"�����"NOR,HIC"��¶��"NOR,YEL"�󻹵�"NOR,HIW"����ɢ"NOR,MAG"���ĵ�"NOR,RED"���߸�"NOR});
        set_name(name[random(sizeof(name))], ({"dan","wan"}));
        set("unit", "��");
        set("long", "����������ҩ���ṩ�ĵ�ҩ���Է���(fu)��\n");
        setup();
}
void init()
{
        add_action("do_eat", "fu");
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("��Ҫ����ʲô��\n");
        if(arg=="dan"||arg=="wan")
        {
                tell_object(environment(this_player()),HIR+this_player()->name()+"������һ�������۵ĵ���\n"NOR);
                tell_object(this_player(), HIG "��ֻ��һ�������ӵ���ӿ����˵�����������\n" NOR);
                this_player()->set("eff_jing",this_player()->query("max_jing"));
                this_player()->set("jing",this_player()->query("max_jing"));
                this_player()->set("eff_qi",this_player()->query("max_qi"));
                this_player()->set("qi",this_player()->query("max_qi"));
                this_player()->set("douzhi",this_player()->query("max_douzhi"));
                this_player()->set("neili",this_player()->query("max_neili")*2);
                destruct(this_object());
        }
        return 1;
}

