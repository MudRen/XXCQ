//Npc:�������
//Write by godzilla 1999.12.22

#include <ansi.h>
inherit NPC;

int ask_me();
int jiangshang2();
void create()
{
        set_name("�������", ({ "guanshi","shi" }));
        set("long",@LONG
����ר�Ÿ����������ӽ��͵ù��¡�\n
LONG
        );
        set("title",HIW"������"NOR);  
        set("gender", "����");
        set("age", 45);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000);
        set("qi",3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 1200000); 
        set("per",20);
        set("max_jingli", 1500);
        set_skill("tianyu-bufa", 100);
        set_skill("literate", 80);
        set_skill("force", 100);
        set_skill("tianyu-qigong", 100);
        set_skill("dodge", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
             set_skill("tianyu-qijian",100);
        
        map_skill("force", "tianyu-qigong");
        map_skill("dodge", "tianyu-bufa");
        map_skill("parry", "tianyu-qijian");
        map_skill("sword", "tianyu-qijian");
       
        set("inquiry", ([
                "����" : (: ask_me :),
        ]));
        setup(); 
        carry_object(__DIR__"obj/cloth2")->wear(); 
        carry_object("/clone/weapon/changjian")->wield();
}
int ask_me()
{
        object gold;
        object me=this_player();
        int age,m,gong,i;
        age =(int)me->query("age");
        m=(int)me->query("give_jiang");
        gong=(int)me->query("gongxun");
              
        if (gong >= 200)
        {
              if(me->query("family/family_name")!="������")
              {
                command("say ��Ϊ"+ RANK_D->query_respect(me)+"��������Ҫ������?\n");
                return 1;
              }            
              if(m<age)
              {
                i=gong/5;
                if(i>1000)
                i=1000;
                message_vision(CYN"$N�ͳ�һ�����ӷ��˷���Ȼ���$n˵��:������Ϊ������˲�����!��������һ��Ľ���\n"NOR,this_object(),me);
                gold=new("/clone/money/gold");
                gold->set_amount(i);
                gold->move(me);
                message_vision(CYN"$N˵��ݸ���$n"+YEL+chinese_number(i)+CYN+"���ƽ�\n"NOR,this_object(),me); 
                me->set("give_jiang",age);
                return jiangshang2();
              }
              command("say �����Ľ����Ѿ���ȡ�ˡ�\n");
              return 1;
        
        }
        else
        {
              if(me->query("family/family_name")!="������")
              {
                command("say ��Ϊ"+ RANK_D->query_respect(me)+"�γ�������?\n");
                return 1;
              }
              command("say �����ڹ��׻�������������ȡ����\n");
              return 1;
        }                  
                

}
int jiangshang2()
{
        object ob,me;
        me=this_player();
        if(2>random(3))
        {
                command("say ���������ҩ����������ҩ�����һ������!\n");
                ob=new(__DIR__"obj/dan");
                ob->move(me);
                command("say ���ҩ������Ҫ��ͷ��Ҫ�ã�ҩ�����Ʋ��ף��м�!\n");
                return 1;       
        }
        return 1;
}           
