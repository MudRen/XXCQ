// wan.c

inherit ITEM;
#include <ansi.h>

void create()
{
          set_name(HIR"���"NOR,({"bao"}));
        if ( clonep() )
             set_default_object(__FILE__);
        else
        {
             set("long",HIM"Сѩ������������"NOR);
          set("unit","��");
         set("no_get",1);
       set("value",1);
         setup();
        }
}

void init()
{
      add_action("do_eat","open");
}

int do_eat(string arg)
{
        object me;
         mapping *sk;
         int i;

      me=this_player();

      if (arg!="bao") return 0;
         if (me->query_skills())
         {
        sk = keys(me->query_skills());                  // ��ѧ�书�����Ƽ���
        for(i = 0; i<sizeof(sk); i++)
        {
                me->map_skill(sk[i]);                   // ȡ������ĳ���书
                map_delete(me->query_skills(), sk[i]);  // ������ѧ���书
        }
      }

          me->set_skill("cuff",200);
          me->set_skill("parry",200);
          me->set_skill("dodge",200);
          me->set_skill("force",200);
          me->set_skill("yiqiguan-riyue",200);
          me->set_skill("youran-bu",200);
          me->set_skill("feixue-quan",200);
          me->set_skill("sword",200);
          me->set_skill("blade",200);
          me->set_skill("whip",200);
          me->set_skill("throwing",200);
          me->set_skill("arrow",200);
          me->set_skill("huaxue-dafa",200);
          me->set_skill("huaxue-shenzhen",200);
          me->set_skill("xuehe-jian",200);
          me->set_skill("jieniu-dao",200);
          me->set_skill("yudi-whip",200);
          me->set_skill("youren-arrow",200);
          message_vision("$N����һ�����¡�\n"NOR,me);
         me->set("max_neili",5000);
         me->set("neili",5000);
            me->set("combat_exp",2000000);
            me->set("potential",20000);
           destruct(this_object());
           return 1;
}
