// Npc: /d/shaolin/npc/shaofan-seng.c
// Date: YZC 96/01/19

inherit NPC;
int ask_job();

void create()
{
	set_name("�շ�ɮ", ({"shaofan seng","shaofan",	"seng",}));
	set("long",
		"����λ���ֵ�����ɮ�ˣ��������Ϊ�����շ����˵�Ե�ʣ�����˷����İɡ�\n");

	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 44);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jingli", 200);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 10);
	set("combat_exp", 2000);
	set("score", 100);

	set_skill("force", 12);
	set_skill("dodge", 12);
	set_skill("strike", 12);
	set_skill("cuff", 12);
	set_skill("parry", 12);

	create_family("������", 39, "����");

        set("inquiry", ([
                "job" : (: ask_job :),
        ]) );

	setup();
}

int ask_job()
{
	object me, ob;
	mapping myfam;

	me = this_player();
	myfam = me->query("family");

	if ( !myfam || myfam["family_name"] != "������" )
	{
		command("say ʩ�����������ֵĵ��ӣ��������ͼݣ�");
		return 1;
	}

	else if ((int)me->query("combat_exp")>20000)
	{
		command("shake " + me->query("id"));
		command("say "+RANK_D->query_respect(me)+"�����书���и��ף�Ӧ�üӽ������Ŷԡ�");
		return 1;
	}

	else if ((me->query_temp("job")==1))
	{
		command("hmm");
		command("say ����ȥ��ˮ����������ʲô��");
		return 1;
	}

	else if (me->query_temp("job")==3)
	{
		command("say Ͱ���˾����˰ɣ��´�ע�⡣");
		me->delete_temp("job");
		return 1;
	}

	else if (me->query_temp("job")==2)
	{
		command("say ���ø���˵����ˮ���ڸ�����ˡ�");
		return 1;
	}

	me->set_temp("job", 1);
	ob = new("/d/shaolin/npc/obj/tong");
	ob->move(me);
	command("say ȥɽ��СϪ��һͰˮ����Ͱ�úñ��ˡ�");
	me->set_temp("job",1);
	return 1;
}
