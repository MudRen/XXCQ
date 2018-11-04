// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void recover_ob();

void create()
{
	set_name("�컪", ({"tian hua", "tian", "hua",}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);

	set("nickname", HIW"�����޺�"NOR);
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
	set("combat_exp", 800000);
	set("score", 500000);

	set_skill("force", 130);
	set_skill("banruo-changong", 130);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 110);
	set_skill("strike", 130);
	set_skill("parry", 110);
	set_skill("banruo-zhang", 130);
	set_skill("buddha", 110);
	set_skill("literate", 110);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "banruo-zhang");

	prepare_skill("strike", "banruo-zhang");

	create_family("������", 36, "����");

	setup();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "strike.banruo" :),
		(: recover_ob :)
	}) );

        carry_object("/d/shaolin/npc/obj/heijiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
}

void recover_ob()
{
	command("yun recover");
	return;
}