#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIC "�����" NOR, ({"biyu gao", "gao"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
        set("long", "����ҩ���Ⱦ��������Ľⶾ��ҩ,��˵�ܽ�Ѫ�ӵľ綾��\n");
       set("value", 35000);
   }
   setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("��Ҫ��ʲô��\n");

tell_object(this_player(), HIG "��ֻ����ں󣬿ڸ������һ����Ѫ���о��ö��ˡ�\n" NOR );
   if ((int)me->query_condition("hx_poison") > 0) {
 me->apply_condition("hx_poison", 0);
   }

   destruct(this_object());
   return 1;
}

