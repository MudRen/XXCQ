// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem

inherit F_BANKER;

void create()
{
	set_name("�߼�Ѫ", ({"gao jixue", "gao", "jixue"}));
	set("title", "Ǯׯ�ϰ�");
	set("nickname", "������");
	set("gender", "����");
	set("long",
		"��������ΤѼë�ϳơ���ѪѼë���ĸ߼�Ѫ�����Ǿ�������������\n"
		"�����Ǯׯ�����ھ��ǵ�����֮һ����Ȼ�Ǹ����ˣ����ƺ�Ҳ��Щ\n"
		"��������ӡ�\n");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
	"�߼�Ѫ������˵�����������Ѿ����ϰ������ʷ���ھ��ǿ���˵�ǵ�һ�ҡ�\n",
	}));

	set_skill("strike", 100);
	set_skill("dodge", 100);
	set_skill("parry",100);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
