// jinchuang.c ��ҩ

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
              add_action("do_eat", "eat");
}

void create()
{
          set_name(HIY"������"NOR, ({"xingshen wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("unit", "��");
      set("long", "����һ���Դ������ҩ�衣\n");
             set("value", 4000);
	}
	setup();
}

   int do_eat(string arg)
{
	if (!id(arg))
             return notify_fail("��Ҫ��ʲôҩ��\n");
           if ((int)this_player()->query("eff_jingli") == 
              (int)this_player()->query("max_jingli"))
             return notify_fail("�����ڲ���Ҫ�������衣\n");
	else {
            this_player()->receive_curing("jingli", 50);
           message_vision("$N����һ��������,������־������һЩ��\n", this_player());
		destruct(this_object());
		return 1;
	}
}
