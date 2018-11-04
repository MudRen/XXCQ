//Npc ����
//by godzilla 11.18.99

#include <ansi.h>

inherit F_MASTER;

inherit NPC;

void create()
{
        set_name("����",({"xiao he","xiao","he"}));
        set("long","�������������£��ų�Ϊ��׷��һ�������ӣ�\n");
        set("title",HIW"������"NOR);
        set("nickname",HIR"׷��һ��"NOR);
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
       
        set_skill("strike",140);
        set_skill("dodge",140);
        set_skill("tao",150);
        set_skill("force", 140);
	set_skill("parry", 140);
	set_skill("sword", 140);
	set_skill("literate", 140);
        set_skill("tianyu-qigong",140);
        set_skill("tianyu-qijian",105);
        set_skill("tianyu-bufa",140);
        set_skill("tianyu-zhenfa",80);
        
        map_skill("sword", "tianyu-qijian");
        map_skill("force", "tianyu-qigong");
        map_skill("dodge", "tianyu-bufa");
        map_skill("parry", "tianyu-qijian");
        
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

void greeting(object me)
{
	if( !me || environment(me) != environment() )
	return 0;
        command("smile "+me->query("id"));
}
void attempt_apprentice(object ob)
{
	
	if(ob->query("family/master_name")=="ף��")
	{
		command("say ��Ȼ�����Ѿ���ף�ĵĵ��ӣ��α��ֵ��������?\n");
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
 



