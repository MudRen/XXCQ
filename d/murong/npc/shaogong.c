// shaogong.c

inherit NPC;

int ask_location();

void create()
{
	set_name("����", ({ "gong", "shaogong" }) );
	set("gender", "����" );
	set("age", 50);
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϴ���");
	set("inquiry", ([
		"λ��": (: ask_location :),
		"location": (: ask_location :),
		"��": "���ø��������ı߿�ѽ(turn n|w|s|e)��",
		"����": "���ø��������ı߿�ѽ(turn n|w|s|e)��",
		"����": "���ø��������ı߿�ѽ(turn n|w|s|e)��",
		"��": "���ø��������ı߿�ѽ(turn n|w|s|e)��",
		"����": "���ø��������ı߿�ѽ(turn n|w|s|e)��",
	]) );
	setup();
}

int ask_location()
{
	object ob=this_player();

	say("�������˿��ɻ�����˵�����������ڵ�λ����(" + ob->query_temp("mr_locx") + ","
	+ ob->query_temp("mr_locy") + ")��\n");
	return 1;
}
