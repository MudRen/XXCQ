inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "tun");
}

void create()
{
	set_name("��ҩ", ({"cao yao","cao","yao"}));
        set("unit", "��");
	set("long", "����һ����ͨ�Ĳ�ҩ��\n");
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
if(arg=="yao") 
{
tell_object(this_player(), HIG "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR );
this_player()->set_temp("nopoison", 1);
this_player()->set("eff_jingli",this_player()->query("max_jingli"));
this_player()->set("jingli",this_player()->query("max_jingli"));
this_player()->set("eff_qi",this_player()->query("max_qi"));
this_player()->set("qi",this_player()->query("max_qi"));
destruct(this_object());
}
return 1;
}