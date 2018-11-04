// Npc: /kungfu/class/shaolin/qing-guan.c
// Date: YZC 96/01/19

inherit NPC;


void create()
{
	set_name("�춷", ({	"tian dou", "tian", "dou",}));
	set("long",
		"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺�\n"
		"�������������һϮ�ײ��ڱ����ģ��ƺ������ա�\n"
	);
	set("title", "��������ɽ����");
	set("nickname", "������ɮ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("qi", 1000);
	set("max_jingli", 600);
	set("jingli", 600);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("score", 100);

	set_skill("force", 90);
	set_skill("banruo-changong", 90);
	set_skill("dodge", 90);
	set_skill("shaolin-shenfa", 90);
	set_skill("strike", 100);
	set_skill("banruo-zhang", 100);
	set_skill("parry", 100);
	set_skill("buddha", 80);
	set_skill("literate", 80);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "banruo-zhang");

	prepare_skill("strike", "banruo-zhang");

	create_family("������", 36, "����");

	setup();

        carry_object(__DIR__"obj/heijiasha")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("yingxiong ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "������" ) )
	{
		if( !ob->query_temp("warned") ) {
			command("hmm");
			command("say ��!!��");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say �󵨿�ͽ�����Ҵ���������������Ұ������\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}
