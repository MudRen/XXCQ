// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_enter();
void check(object me,object ob);

void create()
{
	set_name("���", ({
		"tian kong",
		"tian",
		"kong",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);

	set("nickname", HIB"�����޺�"NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);
/*
	set_skill("force", 110);
	set_skill("hunyuan-yiqi", 110);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 110);
	set_skill("finger", 110);
	set_skill("strike", 110);
	set_skill("hand", 110);
	set_skill("claw", 110);
	set_skill("parry", 110);
	set_skill("nianhua-zhi", 110);
	set_skill("sanhua-zhang", 110);
	set_skill("fengyun-shou", 110);
	set_skill("longzhua-gong", 110);
	set_skill("buddhism", 110);
	set_skill("literate", 110);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
*/
	create_family("������", 36, "����");

        set("inquiry", ([
                "enter" : (: ask_enter :),
		"����" : (: ask_enter :),
        ]) );

	setup();

        carry_object("/d/shaolin/npc/obj/heijiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
}

int ask_enter()
{
	object me,ob;
	me = this_player();
	ob = this_object();

	if ( me->query_temp("kfroom_2"))
	{
		command("?");
		command("say �Ѿ��������ȥ�˻���ʲô��");
		return 1;
	}
	else if ( !me->query("family") || me->query("family/family_name") != "������")
	{
		command("shake");
		command("say �㲻�����ֵ��ӣ����ܽ�����䷿��");
		return 1;
	}
	else if ( me->query_condition("kf_job") )
	{
		command("say ��մӹ��򷿳�������ʱ���ܽ�ȥ������");
		return 1;
	}
	else if ( environment(ob)->query_temp("kfroom_2") )
	{
		command("say �����е��������棬���һ��ɡ�");
		return 1;
	}

	else if ( me->query("combat_exp") < 15000 )
	{
		command("say ��Ĺ�������,������ȥʼ�䷿��û����ɡ�");
		return 1;
	}
	else if ( me->query("combat_exp") > 50000 )
	{
		command("say ��Ĺ�����һ�����ף�ȥ���䷿��һ�������ɡ�");
		return 1;
	}
	else
	{
		command("say �ðɣ����ȥ�ɣ�ǧ��С�ģ��Ų�ס�˾ͳ�����");
		message_vision(HIW"\n$N�������������������������·����˿��һ�����졣\n"NOR,ob);
		message_vision(HIW"\nͻȻ$N�������������ľ�ˣ���$N�ܽ��˽��䷿��\n"NOR,me);
		me->set_temp("kfroom_2",1);
		environment(me)->set_temp("kfroom_2",1);
		me->move("/d/shaolin/kfroom_2");
		call_out("check",100,me,ob);
		return 1;
	}
}

void check(object me,object ob)
{
	if (environment(ob)->query_temp("kfroom_2"))
	{
		command("?");
		command("say ��ô���������أ�");
		command("say ���ˣ��������ˡ�");
		environment(ob)->delete_temp("kfroom_2");
	}
}