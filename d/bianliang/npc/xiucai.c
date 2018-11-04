// xian. ���ϰ�

inherit F_DEALER;
int ask_book();

void create()
{
	set_name("�����", ({ "liu xiucai", "liu", "xiucai" }));
	set("title", "������ׯ");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 45);
	set("long", "һ�����ų����������ӣ���˵ѧ�ʲ�С����֪������ʲô�������������\n");
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
		__DIR__"obj/sanzijing",
		__DIR__"obj/sanguo",
		__DIR__"obj/daxue",
		__DIR__"obj/sanwen",
		__DIR__"obj/shijing",
		__DIR__"obj/libai",
        __DIR__"obj/zhuxi",
	}));

        set("inquiry", ([
                "book" : (: ask_book :),
        ]) );

	setup();
        add_money("silver", 20);
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int ask_book()
{
	int lv = this_player()->query_skill("literate",1);

	if (lv < 31)
		command("say �ҿ���λ"+RANK_D->query_respect(this_player())+"ѧ����ǳ�����¶�����������飬����ȥѧ����ѧΪ�á�");
	else if (lv < 50)
		command("say ��λ"+RANK_D->query_respect(this_player())+"�����Ȿ����־��Σ�");
	else if (lv < 70)
		command("say ��λ"+RANK_D->query_respect(this_player())+"����ѧʶ���Ȿ���ȫ��Ӧ�������ʺ�����");
	else if (lv < 90)
		command("say ��λ"+RANK_D->query_respect(this_player())+"̸�²�����Ӧ�ÿ��Զ��Ȿʫ���ˡ�");
	else if (lv < 110)
		command("say �������Ȿ��ѧ�¾�þ�û�����ˣ���λ"+RANK_D->query_respect(this_player())+"Ӧ��������顣");
	else if (lv < 120)
		command("say ��������Ȿ��ɢ�ļ�������û�б������λ"+RANK_D->query_respect(this_player())+"�ķ����ˡ�");
    else if (lv < 180)
        command("say �ðɣ���ֻ�а����ղصġ������ļ������ó�������λ"+RANK_D->query_respect(this_player()));
	else
		command("say ����С��С��������ԣ���С��ʵ��û���ʺ��������飬�汧Ǹ��");

	return 1;
}
