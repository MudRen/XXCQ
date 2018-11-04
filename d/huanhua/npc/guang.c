// by mulan

inherit NPC;
int ask_me();
int ask_me1();

void create()
{
        set_name("����", ({"guang shu", "guang"}));
        set("gender", "����");
        set("title", "�ư�");
        set("age", 62);
        set("long", "һ�������ɨ��������\n");

        set("attitude", "peaceful");
        set("str", 15);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("bac", 25);

        set("qi", 3000);
        set("max_qi", 3000);
        set("jingli", 2000);
        set("max_jingli", 2000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 60);
        
        set("combat_exp", 1000000);
        set("shen", 10000);
        
        set_skill("force", 180);
        set_skill("jiuqu-xinfa", 180); 
        set_skill("strike", 180);
        set_skill("feixu-zhang", 180);
        set_skill("dodge", 180); 
        set_skill("huanhua-shenfa", 180); 
        set_skill("sword", 200); 
        set_skill("cuff", 100);
        set_skill("parry", 150); 
        set_skill("literate", 150); 
        set_skill("huanhua-jian", 200); 
        set_skill("confu", 120); 
        
        map_skill("force", "jiuqu-xinfa");
        map_skill("cuff", "tiexian-quan");
        map_skill("dodge", "huanhua-shenfa");
        map_skill("strike", "feixu-zhang");
        map_skill("parry", "huanhua-jian");
        map_skill("sword", "huanhua-jian");

        prepare_skill("strike", "feixu-zhang");
        prepare_skill("cuff", "tiexian-quan");
        
        create_family("佻�����", 2, "����");
        set("inquiry", ([
                "����¥" : "���Ǹ�ɨ�ص�,��������!",
		"������" : (:ask_me:),
		"���ɲ���" : (:ask_me1:),
        ]) );

        setup();

        carry_object("/d/huanhua/npc/obj/changshan")->wear();
        carry_object("/d/huanhua/npc/obj/gusong")->wield();
}

int ask_me()
{
	command("ah "+ this_player()->query("id"));
	command("say �Ҿ��ǰ�!����ô֪���ҵ���?\n");
	this_player()->set_temp("ask_jian",1);
        return 1;
}

int ask_me1()
{
	if(!this_player()->query_temp("ask_jian")) return 0;
	command("ok");
      command("give "+"tiaozhou"+" to "+this_player()->query("id"));
        return 1;
}

