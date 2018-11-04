// ding.c �Ҷ�

inherit NPC;

int ask_teach();

void create()
{
	set_name("������", ({ "du xiansheng", "du", "xiansheng" }));
	set("age", 25);
	set("title", "��������");
	set("gender", "����");
	set("long", "��������������ˣ������￪���ڿ��Ѿ��ü����ˣ���˵���ǶŸ���\n�����������ʱ������Ц��ҡͷ��\n");
	set("attitude", "friendly");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("strike", 20);
	set_skill("dodge", 30);
	set_skill("parry", 20);
	set_skill("force", 20);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);

        set("inquiry", ([
                "study" : (: ask_teach :),
		"����" : (: ask_teach :),
		"ѧϰ" : (: ask_teach :),
		"literate" : (: ask_teach :),
        ]) );

	setup();

	carry_object("/clone/armor/changpao")->wear();
}

int ask_teach()
{
	object me,ob;
	me = this_player();
	ob = this_object();

	if ( me->query_temp("xuet"))
	{
		tell_object(me,"�㲻������ѧϰ��?\n ");
		return 1;
	}

	message_vision("�������º͵�Ц��Ц����"+RANK_D->query_respect(me)+"��������ѧ�ģ�\n\n", me);
	command("look "+me->query("id"));

	if ((int)me->query_skill("literate", 1) > 31)
	{
		message_vision("\n������ǫѷ��Ц��Ц������λ"+RANK_D->query_respect(me)+"����ѧʶ�����������ҽ̡�\n\n", me);
		return 1;
	}

	else if ((int)me->query("age") > 18)
	{
		message_vision("\n������Ц��ҡ��ҡͷ������ҰС�ã�Ҳ���ǽ̺̽��ӣ��ɲ��ҽ�����\n\n", me);
		return 1;
	}

	else
	{
		message_vision("\n���������˵�˵���úã������á�\n\n", me);
		message_vision("$N�ߵ�һ������ǰ����������\n\n", me);
		me->apply_condition("xuetang", 10);
		me->set_temp("xuet", 1);
		return 1;
	}
}