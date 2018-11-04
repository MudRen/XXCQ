// tonghui.c ͭ��
// by Load

#include "/kungfu/class/shaolin/tong.h"
inherit NPC;

void create()
{

	set_name("ͭ��", ({"tong hui","tong","hui",}));
	set("long",
		"����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n"
	);

	set("nickname", "����ɮ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 35);
	set("dex", 20);
	set("bac", 22);
	set("max_qi", 400);
	set("qi", 400);
	set("max_jingli", 300);
	set("jingli", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 10);
	set("combat_exp", 20000);
	
	set_skill("force", 40);
    set_skill("banruo-changong", 40);
	set_skill("dodge", 40);
	set_skill("shaolin-shenfa", 40);
	set_skill("cuff", 40);
	set_skill("shaolin-quan", 40);
	set_skill("club", 40);
    set_skill("weituo-gun", 40);
	set_skill("parry", 40);
	set_skill("buddha", 40);

    map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "shaolin-quan");
    map_skill("parry", "weituo-gun");
	map_skill("club", "zui-gun");

	prepare_skill("cuff", "shaolin-quan");

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/npc/obj/huangjiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
        carry_object("/d/shaolin/npc/obj/qimeigun")->wield();
}

void check(object me)
{
	object ob;
	mapping my_fam;

	ob = this_object();

	my_fam = me->query("family");

	if ( my_fam && my_fam["master_id"] == ob->query("id")
        && me->query_skill("banruo-changong",1) > 30
		&& me->query_skill("buddha",1) > 30
		&& !me->query("bai_tie")
		&& environment(me)==environment(ob))
	{
		command("pat " + me->query("id"));
		command("say ���ڷ��ù���ѧ�����ɣ�Ϊʦ�ܽ�����Ѿ������ˡ�");
		command("say ��ȥ���Ű�����ʦ�岮�����߿�����λ���ֱ���ʦ��Ը������ɡ�");
		command("say �Ժ�Ҫ����Ϊʦ�Ľ̻壺�ռ���ɫ��ɫ���ǿա�ȥ�ɡ�");
		me->set("bai_tie", 1);
	}
}
