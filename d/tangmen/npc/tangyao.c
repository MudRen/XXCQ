// tangyao

inherit NPC;

int give_job();
int give_yao();

void create()
{
	set_name("��ҩ", ({ "tang yao", "tang", "yao"}));
//	set("nickname", "Сʦ��");
	set("long", 
"�Ʒ���Ľ�С�����ļ�Ϊ���㣬�ִ�����Ӣ�����徢����������\n"
"�������ų���������Ң˴֮Ů�����ֵ�����̫̫�����²��������ŵ�λ�ĸߡ�\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 24);
	set("dex", 28);

	set("max_qi", 600);
	set("max_jingli", 500);
	set("max_douzhi", 600);
	set("douzhi", 600);
	set("neili", 600);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 30000);
	set("score", 5000);

	set_skill("force", 30);
//	set_skill("zixia-shengong", 30);
	set_skill("dodge", 60);
	set_skill("parry", 40);
	set_skill("sword", 50);
	set_skill("blade", 40);
	set_skill("strike", 50);
/*	set_skill("hunyuan-zhang", 50);
	set_skill("huashan-jianfa", 50);
	set_skill("huashan-shenfa", 50);
	set_skill("fanliangyi-dao", 30);

	map_skill("force", "zixia-shengong");
	map_skill("blade", "fanliangyi-dao");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");
*/
	create_family("�Ĵ�����", 2, "����");

	set("inquiry", ([
		"job" : ( : give_job  : ),
		"����": ( : give_job  : ),
		"yao": ( : give_yao : ),
		"ҩ": ( : give_yao : ),
	]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

int give_job()
{
	object me;

	me = this_player();

	if( !environment() || base_name(environment()) != query("startroom") )
	{
		say("��ҩ˵��:��������û��������ɻ���һ���ҩ����˵�ɣ���\n");
		return 0;
	}

	if ( !(int)me->query_temp("tangmen/yao") )
		command("say ������û�л��ܸ���ɣ�����˭˵�ģ���");
	else
	{
		if ( (int)me->query_temp("yao") )
		{
	                command("say ���㻹û����ɸղŸ���������أ���");
			return 1;
		}
		write("��ҩ˵��:����������ȱһζ��ҩ����ȥҩ�Ը�����(zhao)һ���ҩ(yao)���ɣ���\n");
		me->set_temp("yao",1);
	}
	return 1;
}

int give_yao()
{

}

int accept_object(object who, object ob)
{
	command("say Ҫ���ҵ��ˣ��ͷŵ�������ȥ�ɣ����Ҹ�ʲô?");
	write("��ҩ������ҡ��ҡͷ��Ȼ����С������ķ�Ū��һ�����ɫ��ҩ�ݡ�\n");
	return 0;
}