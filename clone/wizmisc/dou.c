inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG "�ɶ�" NOR, ({"dou"}));
        set("unit", "��");
	set("long", "����һ��ǧ���ѵõ��ɶ����Ǽ������˻�һ��ʱ������ֳ����ģ���˵\nһ�žͿ��Իָ�ȫ���ľ����������е��˴���\n");
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
if(arg=="dou") 
{
tell_object(this_player(), HIG "��ֻ��һ�����������ķΣ���ʱ���е��˿ڶ���ԭ�ˣ�������ɷ��������ˬ��\n" NOR );
this_player()->set_temp("nopoison", 1);
this_player()->set("jingli",this_player()->query("max_jingli"));
this_player()->set("eff_qi",this_player()->query("max_qi"));
this_player()->set("qi",this_player()->query("max_qi"));
this_player()->set("neili",this_player()->query("max_neili"));
destruct(this_object());
}
return 1;
}
