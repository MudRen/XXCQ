//Npc ף��
//by godzilla 11.18.99

#include <ansi.h>

string ask_job();
int ask_gongxian();
inherit F_MASTER;

inherit NPC;

void create()
{
        set_name("ף��",({"zhu you","you","zhu"}));
        set("long","�������������£��ų�Ϊ����ɽһ������ף�ģ�\n");
        set("title",HIW"������"NOR);
        set("nickname",HIR"��ɽһ��"NOR);
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", 0);
        set("str", 30);
        set("int", 35);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 3500);
        set("max_jing", 3000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 100);
        set("combat_exp", 500000);
       
        set_skill("finger",150);
        set_skill("tianyu-zhenfa",80);
        set_skill("dodge",150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("literate", 150);
        set_skill("tianyu-qigong",150);
        set_skill("tao",150);
        set_skill("tianyu-qijian",110);
        set_skill("tianyu-bufa",150);
        
        map_skill("sword", "tianyu-qijian");
        map_skill("force", "tianyu-qigong");
        map_skill("dodge", "tianyu-bufa");
        map_skill("parry", "tianyu-qijian");
        set("inquiry", ([
        "job"       : (: ask_job :),
        "����"      : (: ask_gongxian :),   
        ]));
        create_family("������", 7, "����");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/cloth2")->wear();
}
void init()
{
        object me;
        ::init();
        if(interactive(me=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting",1,me);
        }       
}
string ask_job()
{       
        mapping quest;
        object ob,me;
        me=this_player();
        quest="/d/tianyu/quest/quest2"->query_quest();
/*
        if (me->query("family/family_name")!="������")
            return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";
*/
        if (me->query("combat_exp")<40000)
            return RANK_D->query_respect(me)+"���������̫Σ�գ��㻹��ȥ�ɱ�İɣ�";
        if (me->query_temp("do_job2",1))
            return RANK_D->query_respect(me)+"���������ʲô?��ȥ���ܺ���\n"; 
        if ( (int)me->query_condition("do_songxin" ) > 0 )
            return RANK_D->query_respect(me)+"���ڻ�û���ܺ�Ҫ��ȥ�ͣ�ЪϢ�����ɣ�\n";                   
        ob = new(__DIR__"obj/mihan");
        ob->move(me);
        me->set_temp("do_job2",1);
        me->apply_condition("do_songxin", 10+random(5));
        ob->set("where",quest["where_place"]);
        ob->set("human",quest["name"]);
        command("say ������һ���͸�"+quest["party"]+quest["name"]+"���ܺ���\n");
        command("say �¹��ش�һ·��һ��Ҫ����С�ģ���Ҫ��ʧ�ܺ���\n");
        message_vision("˵��$n�ݸ���$Nһ��"+RED+"�ܺ���\n"NOR,me,this_object());
        return "�ã�������·�ɡ�";
               
}
int ask_gongxian()
{
        object me = this_player();
         if(!me->query("gongxun"))
        {
                 return 1;
        }
        else
        {
                  command("say "+me->name()+"Ϊ��������"YEL+chinese_number((int)me->query("gongxun"))+CYN"�ι���,ϣ�������Ŭ����\n");   
                  return 1;
        }
} 
void greeting(object me)
{
        if( !me || environment(me) != environment() )
        return 0;
        command("smile "+me->query("id"));
}
void attempt_apprentice(object ob)
{
        
        if(ob->query("family/master_name")=="����")
        {
                command("say ��Ȼ�����Ѿ������ӵĵ��ӣ��α��ֵ��������?\n");
                return;
        }
        if(ob->query("int")<25)
        {
                command("say ������̫��������������ж����Ϊ�ġ�\n");
                return;
        }
        command("nod "+ob->query("id"));
        command("say ��������Ҫ������������");      
        command("recruit " + ob->query("id"));
         ob->set("class","tianyumen");
}       
 

