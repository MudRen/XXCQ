// ӭ����Ů��
//�Ǿ�ǧʥ 1999-12-14��

#include <ansi.h>
inherit NPC;

int do_hunli();

void create()
{
      
        set_name( HIR"ӭ����Ů"NOR, ({ "girl" }));
        set("gender", "Ů��");
        set("age", 20);
        set("long", "�����Ǻ���ׯר�Ŵ����Ͳμӻ����ӭ����Ů��\n");
        set("combat_exp", 7000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set("inquiry", ([
                "����"     : (: do_hunli :),
                "�μӻ���" : (: do_hunli :),
        ])); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
//      add_money("silver", 2);

}
int do_hunli()
{
  object me, ob ;
  
  me= this_player();

  ob= this_object();

 if (!( present("qing tie", me)) )
        {
say ("ӭ����Ů����һ��������������?��\n");
             return 1;
        }

  say("ӭ����Ů��"+(string)me->query("name")+"˵�����������������\n");

  say((string)me->query("name")+"�������˺���ׯ��\n");

 me->move( "/d/bianliang/hongniang-zhuang" );

  return 1;
}  

