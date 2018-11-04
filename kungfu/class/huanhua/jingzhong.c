// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void heal_ob();
void recover_ob();
int ask_money();
#include <ansi.h>

void create()
{
	set_name("����", ({"ma jingzhong", "ma", "jingzhong"}));
	set("gender", "����");
	set("title", "佻���®�ܹ�");
	set("nickname", YEL"�����ܹܡ��������"NOR);
	set("age", 30);
	set("long", 
"����һ�����꺺�ӣ���Ķ�С�����Ե���Ϊ���ɡ�\n"
"�����ǵ��������ǣ�����һ����ŭ�����ڹ���佻����ɵ����ա�\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 15);
	set("bac", 20);

	set("qi", 2600);
	set("max_qi", 2600);
	set("jingli", 1800);
	set("max_jingli", 1800);
	set("neili", 2100);
	set("max_neili", 2100);
	set("jiali", 50);
	
	set("combat_exp", 800000);
	set("score", 20000);
	
	set_skill("force", 150);
	set_skill("jiuqu-xinfa", 150); 
	set_skill("dodge", 120); 
	set_skill("huanhua-shenfa", 120); 
	set_skill("cuff", 170); 
	set_skill("tiexian-quan", 170); 
	set_skill("parry", 150); 
	set_skill("literate", 90); 
	set_skill("confu", 90); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("cuff", "tiexian-quan");
	map_skill("parry", "feixu-zhang");

	prepare_skill("cuff", "tiexian-quan");
	
	create_family("佻�����", 3, "����");

	setup();

	carry_object("/d/huanhua/npc/obj/changshan")->wear();

	set("chat_chance", 3);
	set("chat_msg", ({
		(: heal_ob :),
	}));

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "cuff.chong" :),
		(: recover_ob :)
	}) );

        set("inquiry", ([
                "money" : (: ask_money :),
                "��Ǯ" : (: ask_money :),
                "gongqian" : (: ask_money :),
        ]) );
}

void heal_ob()
{
	command("yun heal");
	command("yun heal");
	command("yun heal");
	command("yun recover");
	return;
}

void recover_ob()
{
	command("yun recover");
	return;
}

void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����")
	{
		command("say ����佻����ɵ��ˣ�ֻ��ָ��佻����ӵ��书���汧Ǹ��");
		return;
	}

	if ((int)ob->query("shen") <= (-100))
	{
		command("say ����Ϊ佻�����ȴ���������壬����ħ������佻��ݲ����㣡");
		command("kaichu "+ob->query("id"));
		return;
	}

	if (ob->query("shen")<20000)
	{
		command("say ��ά�����������������ò������һ��������㡣");
		command("addoil " + ob->query("id"));
		return;
	}

	if (ob->query_skill("force",1)< 90 || ob->query_skill("jiuqu-xinfa",1)<90)
	{
		command("say �ҵĹ����������ʵ���ڹ�����Ϊ�����������ڿ��»�ѧ���ˡ�");
		command("sorry " + ob->query("id"));
		return;
	}

	if (ob->query_str()<32)
	{
		command("shake " + ob->query("id"));
		command("say �ҿ����������������д�ɣ��Ҳ������㡣");
		return;
	}

	command("say �ðɣ����������޷������ܷ�ɲŻ�Ҫ�����Լ���Ŭ����");
	command("recruit " + ob->query("id"));

	return;
}

int ask_money()
{
	object me, ob, to_ob;
	mapping myfam;
	me = this_player();
	ob = this_object();
	to_ob = present("silver_money", this_player());

	myfam = me->query("family");

	if ( !(myfam = me->query("family")) || myfam["family_name"] != "佻�����" )
	{
		command("hmm " + me->query("id"));
		command("say �㲻����佻��ĵ��ӣ���ôҲ��Ҫ��Ǯ��");
		return 1;
	}

	else if (me->query("pay_money") - me->query("age") == 0)
	{
		command("angry " + me->query("id"));
		command("say ������Ҫ��Ǯ����û��Ϣ��");
		return 1;
	}

	else if ((me->query("succeed") < 10))
	{
		command("shake");
		command("say ��������ô�㹤��������Ҫ��Ǯ�����������õ��ˣ�");
		return 1;
	}

	else
	{
		command("nod");
		command("say ���һ�£�������һ��Ĺ�Ǯ���㣬�úø�ѽ��");
		if( !to_ob ) {
			to_ob = new("/clone/money/silver");
			to_ob->move(this_player());
			to_ob->set_amount(me->query("succeed")*2);
		} else
			to_ob->add_amount(me->query("succeed"));
		me->set("succeed", 0);
		me->set("pay_money", me->query("age"));
	        message_vision("$n����$N���������һЩ�����ӡ�\n", me, ob);
		return 1;
	}
}