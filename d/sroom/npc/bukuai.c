// bukuai.c 
// god
#include <ansi.h>
inherit NPC;


void create()
{
        set_name("����", ({ "bukuai" }));
        set("title", "�ĺ�����");
        set("gender", "����");
        set("age", 43);
        set("str", 20);
        set("dex", 20);
        set("long", "���ǳ�͢�����Ĳ��졣\n");
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "heroism");

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);

        set("neili", 500); 
        set("max_neili", 500);
        set("jiali", 10);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_chat", "chat");
        add_action("do_chat","chat*");
        add_action("do_rumor","rumor");
        add_action("do_rumor","rumor*");
        add_action("do_new","new");
        add_action("do_new","new*");
        add_action("do_party","party");
        add_action("do_party","party*");
        add_action("do_es","es");
        add_action("do_es","es*");
}
int do_chat()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "������ɫһ�����ȵ����������������������\n" NOR);
   tell_object(ob, HIR "������ͷ����ǰ�������ɷ�˵��һ��������"
                  +"Ƥ������,���˹�ȥ��\n" NOR);
   ob->unconcious();
   return 1;
}
int do_rumor()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "��������ɫһ�����ȵ����������������������\n" NOR);
   tell_object(ob, HIR "������ͷ����ǰ�������ɷ�˵��һ��������"
                  +"Ƥ������,���˹�ȥ��\n" NOR);
   ob->unconcious();
   return 1;
}
int do_party()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "������ɫһ�����ȵ����������������������\n" NOR);
   tell_object(ob, HIR "������ͷ����ǰ�������ɷ�˵��һ��������"
                  +"Ƥ������,���˹�ȥ��\n" NOR);
   ob->unconcious();
   return 1;
}
int do_new()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "������ɫһ�����ȵ����������������������\n" NOR);
   tell_object(ob, HIR "������ͷ����ǰ�������ɷ�˵��һ��������"
                  +"Ƥ������,���˹�ȥ��\n" NOR);
   ob->unconcious();
   return 1;
}
int do_es()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "������ɫһ�����ȵ����������������������\n" NOR);
   tell_object(ob, HIR "������ͷ����ǰ�������ɷ�˵��һ��������"
                  +"Ƥ������,���˹�ȥ��\n" NOR);
   ob->unconcious();
   return 1;
}


