// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/shaolin/other.h"

void create()
{
    set_name("���", ({"tian heng","tian","heng",}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n");

    set("nickname", HIY"�����޺�"NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 18);
	set("con", 20);
	set("dex", 22);
	set("bac", 20);
	set("max_qi", 2500);
	set("eff_qi", 2500);
	set("qi", 2500);
	set("max_jingli", 2000);
	set("eff_jingli", 2000);
	set("jingli", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 400000);
	set("score", 5000);

	set_skill("force", 140);
	set_skill("banruo-changong", 140);
	set_skill("dodge", 130);
	set_skill("shaolin-shenfa", 130);
    set_skill("claw", 150);
    set_skill("fozhao-gong", 150);
    set_skill("sword", 150);
    set_skill("damo-jian", 150);
	set_skill("parry", 140);
    set_skill("buddha", 140);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
     map_skill("claw", "fozhao-gong");
     map_skill("parry", "fozhao-gong");
     map_skill("sword", "damo-jian");

     prepare_skill("claw", "fozhao-gong");

	create_family("������", 36, "����");

	setup();

        carry_object("/d/shaolin/npc/obj/heijiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
         carry_object("/d/shaolin/npc/obj/changjian")->wield();
}

void check(object me)
{
	object ob;
	mapping my_fam;

	ob = this_object();

	my_fam = me->query("family");

	if ( my_fam && my_fam["master_id"] == ob->query("id")
		&& me->query_skill("banruo-changong",1) > 120
		&& me->query_skill("buddha",1) > 120
        && (me->query_skill("damo-jian",1) > 120 || me->query_skill("fozhao-gong",1)> 120)
		&& !me->query("bai_mu")
		&& environment(me)==environment(ob))
	{
		command("pat " + me->query("id"));
		command("say ���ڷ��ù���ѧ�����ɣ�Ϊʦ�ܽ�����Ѿ������ˡ�");
		command("say ��ȥ���Ű�����ʦ�岮�����߿�����λľ�ֱ���ʦ��Ը������ɡ�");
		command("say �Ժ�Ҫ����Ϊʦ�Ľ̻壺�˳���Ⱦ�����⿪�������ޡ�ȥ�ɡ�");
		me->set("bai_mu", 1);
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

	if (my_fam){
	if ( me->query("bai_tian") && (ob_fam["generation"] + 2 == (my_fam["generation"] )) )
	{
		command("say " + me->query("name") + "����ʦ��" + my_fam["master_name"] + "�����Ƽ����㡣");
		if (me->query_skill("banruo-changong",1)<60)
		{
			command("say �ҵĹ�����Ҫһ���İ�����������������ѧ���˵ġ�");
			command("say �㻹��ȥ�����������ֱ����Ӱɡ�");
			return;
		}
		else 
		{
			me->delete("bai_tian");
			new_name = "��" + name[2..3];
			me->set("name", new_name);
			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ���������ֱ����� !");
			command("recruit " + me->query("id"));
			return;
		}
	}
	else if (ob_fam["generation"] + 1 == (my_fam["generation"] ))
	{
		if (me->query_skill("banruo-changong",1)<60)
		{
			command("say �ҵĹ�����Ҫһ���İ�����������������ѧ���˵ġ�");
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
}
