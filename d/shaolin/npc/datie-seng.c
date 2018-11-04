// datie-seng.c

inherit NPC;

void create()
{
	set_name("����ɮ", ({ "datie seng", "datie", "seng" }) );
	set("gender", "����" );
	set("age", 38);
	set("long", "���Ǹ���ǿ��׳��Ƥ���ֺڵĴ���ɮ�ˡ�\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 15);
	set("shen_type", 1);

	set_skill("strike", 50);
	set_skill("dodge", 35);
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set("combat_exp", 7500);

	set("attitude", "peaceful");

	create_family("������", 39, "����");

	setup();
}