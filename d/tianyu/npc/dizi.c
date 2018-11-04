//Npc ����
//by godzilla 11.18.99

#include <ansi.h>

int ask_ruguan();

inherit NPC;

void create()
{
        set_name("�عص���", ({"dizi"}));
        set("long",
                "������Ϊר��Ϊʦ�����عصĵ��ӡ�\n"
        );
        set("gender", "����");
        set("attitude", "peaceful");
        set("age", 44);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 700);
        set("max_jingli", 700);
        set("neili", 1000);
        set("jingli",1000);
        set("max_neili", 1000);
        set("jiali", 60);
        set("combat_exp", 80000);
        
        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("strike",80);
        set_skill("parry", 80);
        set_skill("sword",90);
        set_skill("tianyu-qigong",80);
        set_skill("tianyu-qijian",85);
        set_skill("tianyu-bufa",80);
        
        map_skill("sword", "tianyu-qijian");
        map_skill("force", "tianyu-qigong");
        map_skill("dodge", "tianyu-bufa");
        map_skill("parry", "tianyu-qijian");
 
        set("inquiry", ([
        "�չ�"       : (: ask_ruguan :),
        ]));
        create_family("������", 7, "����");
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
        carry_object("/clone/weapon/changjian")->wield();
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
int ask_ruguan()
{       
        object ob,me;
        ob=this_object();
        me=this_player();
          if(me->query("family/family_name")!="������")  
{
         command("say ���뱾��������������֪�˻��Ӻ�̸��\n");
          return 1;
}
        if (me->query_skill("tianyu-qijian",1)<=100)
{
            command("say ���������𽣷���Ϊ�����������ܱչأ�\n");
           return 1;
}
        if (environment(ob)->query("mask/�չ�")>=3)
        {
        	tell_object(me,"�����Ѿ������������ڱչ��������˶����ӣ��㻹�ǵȻ������ɣ�\n");
        	return 1;
        }	 
        tell_object(me,"�ðɣ�����Խ�ȥ�����ˡ�\n");
        command("party "+me->name()+"��ʼ�չ��������𽣷����������Ӳ���ɧ�ţ���\n");
        me->set_temp("xiulian_sword",1);
        environment(ob)->add("mask/�չ�",1);
        me->move("/d/tianyu/lgs");
        tell_object(environment(ob),me->name()+"���عص��ӵĴ����½������������������\n");
        return 1;
        
}
