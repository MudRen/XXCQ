// mengmian.c �����
// By godzilla 11.20.99
#include <ansi.h>
inherit NPC;
void copy(object me);
void create()
{
        string *name=({"Ľ����","���Ѵ�","�����","��Ǯ","�Ϲ�ѩ","ŷ���Ʒ�","˾ͽ��","����","���","����","Ѫ�޺�"});
        set_name(name[random(sizeof(name))], ({ "killer" }));
        set("long",
                "������Сѩ������ɱ���ŵ�ɱ�֡�\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "friendly");
        set("kill", 200);
        set("score",-500);

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 400+random(200));
        set("max_jing", 300+random(300));
        set("neili", 500+random(300));
        set("max_neili", 300+random(300));

        set("combat_exp", 25000+random(20000));
        
        set_skill("force", 30+random(20));
        set_skill("dodge", 30+random(20));
        set_skill("unarmed", 30+random(20));
        set_skill("parry", 30+random(20));
        set_skill("blade", 30+random(20));
        set_skill("xiuluo-dao", 30+random(20));
       
        map_skill("parry", "xiuluo-dao");
        map_skill("blade", "xiuluo-dao");

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
}
/*
void init()
{
	object me;
	me = this_player();
	::init();
     if (me->query_temp("do_job2")&&this_object()->query("tianyu")==me->name())
	{
		call_out("copy",0, me);
		
	}
}
void copy(object me)
{
	object ob;
	ob=this_object();
	if(me->query("combat_exp")>85000)
	{
    ob->set("combat_exp",me->query("combat_exp")/3*2);
	ob->set("qi",me->query("max_qi"));
	ob->set("max_jingli",me->query("max_jingli"));
	ob->set("eff_jingli",me->query("max_jingli"));
	ob->set("jingli",me->query("max_jingli"));
	ob->set("max_neili",me->query("max_neili"));
	ob->set("neili",me->query("max_neili"));
	ob->set_skill("force",(int)me->query_skill("tianyu-qijian",1));
	ob->set_skill("dodge", (int)me->query_skill("tianyu-qijian",1)); 
	ob->set_skill("parry",(int)me->query_skill("tianyu-qijian",1)); 
     ob->set_skill("xiuluo-dao",50+random(50));
	ob->set_skill("blade",(int)me->query_skill("tianyu-qijian",1));
      }
	
}
*/
