// ding.c �Ҷ�

inherit NPC;
#include <ansi.h>

int ask_baishi();

void create()
{
	set_name("�Ҷ�", ({ "jia ding", "ding" }));
	set("age", 25);
	set("gender", "����");
	set("title","佻����ɵ��������ӡ�"CYN"Ȯ����Ա"NOR);
	set("long", "����һ����׳���������ӣ�ÿ����͸������ſڽ䱸���Ӵ����͡�\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 20000);
	set("shen_type", 1);

	set_skill("force", 50);
	set_skill("jiuqu-xinfa", 50); 
	set_skill("strike", 50);
	set_skill("feixu-zhang", 50);
	set_skill("dodge", 50); 
	set_skill("huanhua-shenfa", 50); 
	set_skill("sword", 50); 
	set_skill("parry", 50); 
	set_skill("literate", 50); 
	set_skill("confu", 40); 
	set_skill("huanhua-jian", 50); 

	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("parry", "huanhua-jian");
	map_skill("sword", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("佻�����", 6, "����");

        set("inquiry", ([
                "��ʦ" : (: ask_baishi:),
		"baishi" : (: ask_baishi:),
        ]) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/liangongfu")->wear();
}

int ask_baishi()
{
	object me,ob;
	mapping myfam;
	me = this_player();
	ob = this_object();

	if ((myfam = (mapping)me->query("family"))
		&& myfam["family_name"] == "佻�����" )
	{
		command("say ���ڿ��ţ�����ҿ���Ц����ȥ���Լ����°ɡ�");
	}
	else if ((me->query("combat_exp"))>20000)
	{
		command("say "+RANK_D->query_respect(me)+"���ǽ�������֮ʿ�����������ĸ��������ͣ���������ذɡ�\n");
	}
	else if ((me->query("shen"))<0)
	{
		command("hmm");
		command("say 佻�����аħ���֮�ˣ���������ذɣ��������ûȤ��\n");
	}
	else
	{
		command("say "+RANK_D->query_respect(me)+"��Ȼ���İ�ʦ������������ɡ�\n");
		me->move("/d/huanhua/qianroad1");
		command("enter");
		command("say "+RANK_D->query_respect(me)+"�Լ���ȥ�ɣ���Ҫ��������ѽ��\n");
		command("out");
	}

	return 1;
}