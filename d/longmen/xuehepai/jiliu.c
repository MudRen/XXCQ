
inherit ROOM;
#include <ansi.h>
int do_yun(string arg);
void create()
{
        set("short","����");
        set("long",@LONG
���Ѿ����������Σ�յ����ż�����ǿ���ˮ�������������塣
�����γ������У�һ��С�ľͻᱻ����˺����Ƭ�����������Ȼ������
�ֺ�����ʾ��ȥ�˷�������������
LONG );
        set("exits",([
              "enter" : __DIR__"mishi",
        ]));
        set("outdoors","����");
        set("class","Ѫ����");
//        set("no_clean_up"�� 0);
        setup();
}

void init()
{
             object *obb;
             int i;

        obb=all_inventory(this_player());

        add_action("do_yun","lingwu");
        add_action("do_jump","tiao");
            if (interactive(this_player())) {
              if (this_player()->query_skill("longmen-shengong",1)>=60)
          {
               for (i=0;i<sizeof(obb);i++)  {
               if (obb[i]->is_character())
               {
              message("channel:snow",HIY"��������"HIC" ��˵"+obb[i]->query("name")+"��"+this_player()->query("name")+"�ƽ������ż�������״�Ҳ��̶á�\n"NOR,users());
                     obb[i]->die();
               }
         }
              return;
           }
                 if (!(this_player()->query_temp("chong")))
        {
                message_vision("$Nƴ��ȥ�˹��ֿ����е�ѹ�������Ǵ���Ȼ������̫ǿ���ˡ�����\n",this_player());
                this_player()->die();
	message("channel:rumor",HIY"��������"HIB"����"+this_player()->query("name")+"�������ż����У��������������ȫʬ��\n"NOR,users());
                return;
        }
        else if (this_player()->query("max_neili")<1000)
        {
                message_vision("��ȻѪ�ӳ���������˴󲿷ֵ�ѹ���������������̫���ˡ�������\n",this_player());
	message("channel:rumor",HIY"��������"HIB"����"+this_player()->query("name")+"�������ż����У��������������ȫʬ��\n"NOR,users());
                this_player()->die();
                return;
        }
        message_vision("$Nƴ��ȥ�˹��ֿ����е�ѹ����ֻ��ˮ��ֱ����������������\n",this_player());
         for (i=0;i<sizeof(obb);i++)  {
               if (obb[i]->is_character())
               {
              message("channel:snow",HIY"��������"HIC" ��˵"+obb[i]->query("name")+"��"+this_player()->query("name")+"�ƽ������ż�������״�Ҳ��̶á�\n"NOR,users());
                     obb[i]->die();
               }
         }

        this_player()->move(__DIR__"mishi");
            this_player()->delete_temp("xueheche");
        this_player()->unconcious();
        return;
           }
}

int do_yun(string arg)
{
        object me;
          int skills;

        me=this_player();
          skills=me->query_skill("longmen-shengong",1);
        
        if (!arg  || arg!="������")
                return notify_fail("��Ҫ����ʲô�书��\n");
                
        if ((skills*skills*skills/10)>me->query("combat_exp"))
             return notify_fail("��ľ��鲻�������ܼ�������\n");

          if (me->query("qi")<50 || me->query("jingli")<50)
                return notify_fail("�����ɫ̫���ˣ��������ɶ��\n");
       message_vision(HIY"$N������������ȫ�����ɼ��壬���ɼ�����ˢ��\n"NOR,me);
       message_vision(HIY"$N�����������о��������ڣ�������ת������������һ����ת��\n"NOR,me);
        tell_object(me,"������������˸���һ��������\n");
        me->improve_skill("longmen-shengong",random(10*me->query("int")));
         me->add("qi",-50);
         me->add("jingli",-20);
        return 1;
}

int do_jump(string arg)
{
           object me;
           me=this_player();

           if (!arg && arg!="out")
            return notify_fail("��Ҫ��������\n");

           if (me->query_skill("longmen-shengong",1)<100)
            return notify_fail("�����������Ϊ��������\n");

           message_vision("$N����һԾ���������ж�ȥ��\n",me);
           me->move(__DIR__"tanbian");
           message_vision("ֻ��$NͻȻ����̶��ð�˳�����\n",me);
           return 1;
}

