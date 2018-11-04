// Npc: /d/shaolin/npc/saodi-seng.c
// Date: YZC 96/01/19

inherit NPC;

void my_move();


void create()
{
	set_name("ɨ��ɮ", ({"saodi seng","saodi","seng",}));
	set("long",
		"����һλרְ������¥��ܣ��������������ɮ�ˡ�\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 35);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 300);
	set("max_jingli", 150);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 25);
	set_skill("dodge", 25);
	set_skill("strike", 25);
	set_skill("cuff", 25);
	set_skill("parry", 25);

	create_family("������", 39, "����");

	setup();
}

void my_move()
{
	int value;
	
	value = random(10);
	
	if (value > 6)
	{
		command("say ��һ��ѻ�û�����أ��ҵøϽ��ˡ�\n");
		command("sigh");
		command("up");
	}
	else if (value < 4)
	{
		command("say ��һ��ѻ�û�����أ��ҵøϽ��ˡ�\n");
		command("sigh");
		command("down");
	}
}

