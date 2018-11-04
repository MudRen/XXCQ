// Npc: /kungfu/class/shaolin/xu-ming.c
// Date: YZC 96/01/19

inherit NPC;


void create()
{

	set_name("��ʯ", ({"tie shi","tie","shi",}));
	set("long",
		"����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n"
	);

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
	set("max_qi", 600);
	set("qi", 600);
	set("max_jingli", 400);
	set("jingli", 400);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 30);
	set("combat_exp", 30000);
	
	set_skill("force", 60);
	set_skill("banruo-changong", 60);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 70);
	set_skill("luohan-quan", 70);
	set_skill("parry", 50);
	set_skill("buddha", 60);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");

	prepare_skill("cuff", "luohan-quan");

	create_family("������", 37, "����");

	setup();

        carry_object(__DIR__"obj/huijiasha")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
}