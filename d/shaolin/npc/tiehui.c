// Npc: /kungfu/class/shaolin/xu-ming.c
// Date: YZC 96/01/19

inherit NPC;

int ask_drug1();
int ask_drug2();
int ask_drug3();

void create()
{

	set_name("����", ({"tie hui","tie","hui",}));
	set("long",
		"����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n"
	);

	set("gender", "����");
	set("title", "������ҩƷ�����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 35);
	set("dex", 20);
	set("max_qi", 450);
	set("qi", 450);
	set("max_jingli", 400);
	set("jingli", 400);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 20);
	set("combat_exp", 15000);
	
	set_skill("force", 40);
	set_skill("banruo-changong", 40);
	set_skill("dodge", 40);
	set_skill("shaolin-shenfa", 40);
	set_skill("cuff", 50);
	set_skill("luohan-quan", 50);
	set_skill("parry", 40);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");

	prepare_skill("cuff", "luohan-quan");

	create_family("������", 37, "����");

	set("inquiry", ([
		"drug" : "��������һЩ����������Ѫ���ͼ��Ŵ󻹵���",
		"��Ѫ��" : (: ask_drug1 :),
		"�󻹵�" : (: ask_drug2 :),
		"������" : (: ask_drug3 :),
        ]) );

	setup();

        carry_object(__DIR__"obj/huijiasha")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
}

int ask_drug1()
{
	object me, ob;
	me = this_player();

	if (me->query_condition("ask_drug") > 0)
	{
		message_vision("���Ա�Ǹ��˵����������ҩƷ���ޣ���ĵ���ҲҪ�ã��Ҹո�����һ�Σ����������Ҫ�ɡ���\n", me);
		return 1;
	}

	ob = new(__DIR__"obj/huoxue");
	ob->move(me);
	message_vision("���Ը���$Nһ�Ż�Ѫ����Ȼ����������Ѫ�������ҩ����Ҳ��֮���ף�ǧ��Ҫ�˷ѡ�\n\n", me);

	me->apply_condition("ask_drug", 60);

	return 1;
}

int ask_drug2()
{
	object me, ob, drug;
	me = this_player();
	ob = this_object();

	if (ob->query("no_drug"))
		return notify_fail("���Ա�Ǹ��˵������������ʱû�д󻹵��ˣ�����������ɡ�\n��");

	if (me->query_condition("ask_drug") > 0)
	{
		message_vision("���Ա�Ǹ��˵����������ҩƷ���ޣ���ĵ���ҲҪ�ã��Ҹո�����һ�Σ����������Ҫ�ɡ���\n", me);
		return 1;
	}

	drug = new(__DIR__"obj/dahuan-dan");
	drug->move(me);
	message_vision("���Ը���$Nһ�Ŵ󻹵���Ȼ���������󻹵���֮���ѣ���֮����Ч��ǧ��Ҫ�˷ѡ�\n\n", me);

	me->apply_condition("ask_drug", 120);

	ob->set("no_drug", 1);
	call_out("recover", 3600, ob);

	return 1;
}

int ask_drug3()
{
	object me, ob;
	me = this_player();

	if (me->query_condition("ask_drug") > 0)
	{
		message_vision("���Ա�Ǹ��˵����������ҩƷ���ޣ���ĵ���ҲҪ�ã��Ҹո�����һ�Σ����������Ҫ�ɡ���\n", me);
		return 1;
	}

	ob = new(__DIR__"obj/hugutie");
	ob->move(me);
	message_vision("���Ը���$Nһ����������Ȼ����������������֮���ף�ǧ��Ҫ�˷ѡ�\n\n", me);

	me->apply_condition("ask_drug", 60);

	return 1;
}

void recover(object ob)
{
	ob->delete("no_drug");
	return;
}