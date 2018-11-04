// Npc: /kungfu/class/shaolin/xu-ming.c
// Date: YZC 96/01/19

#include "/kungfu/class/shaolin/other.h"
inherit NPC;

void create()
{

	set_name("����", ({"tie wen","tie","wen",}));
	set("long",
		"����һλ���Ҳ�������ĵ�ɮ�ˡ���Ͳ���ȴ�������ϳɣ����ַ���ɭ�ϣ�\n"
		"������ǲ�����\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 27);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 35);
	set("dex", 20);
	set("bac", 23);
	set("max_qi", 800);
	set("qi", 800);
	set("max_jingli", 500);
	set("jingli", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 80000);
	
	set_skill("force", 80);
	set_skill("wuxiang-shengong", 80);
	set_skill("dodge", 80);
	set_skill("shaolin-shenfa", 80);
	set_skill("strike", 90);
	set_skill("huoyan-dao", 90);
	set_skill("blade", 90);
	set_skill("xiuluo-dao", 90);
	set_skill("parry", 80);
	set_skill("buddha", 80);

	map_skill("force", "wuxiang-shengong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "huoyan-dao");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "xiuluo-dao");

	prepare_skill("strike", "huoyan-dao");

	create_family("������", 37, "����");

	setup();

        carry_object("/d/shaolin/npc/obj/huijiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
        carry_object("/d/shaolin/npc/obj/jiedao")->wield();
}

void check(object me)
{
	object ob;
	mapping my_fam;

	ob = this_object();

	my_fam = me->query("family");

	if ( my_fam["master_id"] == ob->query("id")
		&& me->query_skill("wuxiang-shengong",1) > 60
		&& me->query_skill("buddha",1) > 60
		&& (me->query_skill("huoyan-dao",1) > 60 || me->query_skill("xiuluo-dao",1)>60)
		&& !me->query("bai_tian")
		&& environment(me)==environment(ob))
	{
		command("pat " + me->query("id"));
		command("say ���ڷ��ù���ѧ�����ɣ�Ϊʦ�ܽ�����Ѿ������ˡ�");
		command("say ��ȥ���Ű�����ʦ�岮�����߿�����λ���ֱ���ʦ��Ը������ɡ�");
		command("say �Ժ�Ҫ����Ϊʦ�Ľ̻壺�������ƣ�һ�������Ƹ���ȥ�ɡ�");
		me->set("bai_tian", 1);
	}
}

void check_shou(object me)
{
	object ob;
	mapping my_fam, ob_fam;
	string name, new_name;

	ob = this_object();
	name = me->query("name");

	my_fam = me->query("family");
	ob_fam = ob->query("family");

	if ( me->query("bai_tie") && (ob_fam["generation"] + 2 == (my_fam["generation"] )) )
	{
		command("say " + me->query("name") + "����ʦ��" + my_fam["master_name"] + "�����Ƽ����㡣");
		if (me->query_skill("wuxiang-shengong",1)<30)
		{
			command("say �ҵĹ�����Ҫһ��������������������ѧ���˵ġ�");
			command("say �㻹��ȥ�����������ֱ����Ӱɡ�");
			return;
		}
		else 
		{
			me->delete("bai_tie");
			new_name = "ͭ" + name[2..3];
			me->set("name", new_name);
			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ������ͭ�ֱ����� !");
			command("recruit " + me->query("id"));
			return;
		}
	}
	else if (ob_fam["generation"] + 1 == (my_fam["generation"] ))
	{
		if (me->query_skill("wuxiang-shengong",1)<30)
		{
			command("say �ҵĹ�����Ҫһ��������������������ѧ���˵ġ�");
			command("say �㻹��ȥ�����������ֱ����Ӱɡ�");
			return;
		}
		command("recruit " + me->query("id"));
	}
	else
	{
		command("say " + me->query("name") + "��δ����ʦ���Ƽ����Ҳ������㣬���ȥ�ɡ�");
		return;
	}
}	