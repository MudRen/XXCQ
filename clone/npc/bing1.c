// bing.c �ٱ�

inherit F_BUKUAI;

void create()
{
	set_name("�ٱ�", ({ "guan bing", "bing" }));
	set("title", "�������� Ѳ��");
	set("age", 22);
	set("gender", "����");
	set("long", "��Ȼ�ٱ������ղ��ܺ�������ʿ��ȣ��������ǽ��������˶�������\n");
	set("attitude", "heroism");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"�ٱ��ȵ����󵨵��񣬾����췴���ɣ�\n",
		"�ٱ��ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n",
	}));

        set("chat_chance",2);
        set("chat_msg",({
	"�ٱ�����һ���������ҵã����۾�����Щ������ҵ��ֵú��ס���\n",
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: random_move :),
        }));

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/armor/junfu")->wear();
	carry_object("/clone/food/jitui")->wear();
	add_money("silver",2);
}
