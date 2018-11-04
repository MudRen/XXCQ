// Npc: /kungfu/class/shaolin/qing-guan.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit NPC;

int ask_job();

void create()
{
	set_name("����", ({	"tian xiang", "tian", "xiang",}));
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

        set("inquiry", ([
                "job" : (: ask_job :),
        ]) );

	setup();

        carry_object(__DIR__"obj/heijiasha")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
}

int ask_job()
{
	object ob, me;
	mapping myfam, quest;

	me = this_player();
	ob = this_object();
	myfam = (mapping)me->query("family");
	quest = "/d/shaolin/quest/txquest"->query_quest();

	if (me->query_temp("where") == "fail")
	{
		command("sigh");
		command("disapp " + me->query("id"));
		command("say ������ȥ�ɣ����ʱ�䲻�����ְ�ְ���ˡ�");
		me->delete_temp("where");
		return 1;
	}

	if (me->query_condition("txjob_fail") > 0)
	{
		command("say ���ڲ���Ҫ��ȥְ��,�㻹�ǳ����ʱ����������ɡ�");
		return 1;
	}

        if(me->query("qi") < me->query("max_qi")/2 || me->query("jingli") < me->query("max_jingli")/2)
        {
          command("say ��ľ�������Ѫ�Ѿ�������,ȥ��Ϣ��Ϣ��!\n");
          return 1;
        }
        if(me->query("combat_exp")<10000)
        {
          command("say ����书̫����,����ʤ���������!\n");
         return 1;
        }
        if(me->query("combat_exp")>300000)
        {
          command("say �㲻��ȥ����ЩС����,ȥ������!\n");
          return 1;
        }
	if (me->query_temp("where") == "over")
	{
		command("say �úã��ɵĺã�����ȥЪЪ�ɡ�");
		me->add("potential", 50+random(50));
		me->add("combat_exp", 100+random(100));
		me->delete_temp("where");
		return 1;
	}

	if (me->query_temp("where"))
	{
		command("say ����ȥְ�أ�����ô�ֻ����ˣ��������ȥ��");
		return 1;
	}

	if (myfam["family_name"] != "������")
	{
		command("say ʩ�������ǲ��ҵ��������ӷ�");
		return 1;
	}

	command("say ���������ã���������������ô�" + quest["quest"] + "������" + quest["quest_object"] + "������������Щ���㡣");
	command("say ����������ȥ" + quest["quest_place"] + "ְ��һ��ڣ�ǧ�����û������ȥ��");
	command("say ְ���ڼ���Բ���ɾ�룬�������������롣");

	me->set_temp("where", quest["file_name"]);

	call_out("check_guard", 60, me);

	return 1;
}

void check_guard(object me)
{
	object where;

	where = environment(me);

	if (file_name(where)==me->query_temp("where"))
	{
          message_vision(HIC"$N���Ӿ�����סҪ����ֵ��վ�ڡ�\n"NOR, me);
          message_vision(HIC"$N������ɹ����,��ȥ��Ҫ�����ɡ�\n"NOR, me);
		//me->apply_condition("txquest", 20);
	       me->set_temp("where","over");
           me -> receive_damage ("jingli", me->query("jingli")/4);
           me -> receive_damage ("qi", me->query("qi")/4);
	}
	else
	{
		message_vision("\nͻȻ�Ա�������һ��ɮ��������Ķ�$N˵������ȥְ�أ���ȴ�ٳٲ����ڣ�����ȥ��������ʦ�֡�\n", me);
		message_vision("��һ˵�꣬ɮ���ͼ���ææ�򾫽����ķ����뿪�ˡ�\n\n", me);
		me->set_temp("where", "fail");
		me->apply_condition("txjob_fail",50);
	}
	return;
}
