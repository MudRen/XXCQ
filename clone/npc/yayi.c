// yayi.c  �ٸ�����
inherit F_BUKUAI;

void create()
{
	set_name("����", ({ "ya yi", "ya" }));
	set("gender", "����");
	set("age", 25);

	set("long", "һ���ߴ����͵ĺ��ӣ���Ϊ���ڹٸ����£������Ѿ�ĥ���ú��ޱ��顣\n");
	set("combat_exp", 7500);
	set("attitude", "heroism");
	set("shen_type", 1);

        set_skill("unarmed", 30);
        set_skill("dodge", 30);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		"����˵�����㵱������ʲô�ط�����������ɧ�ţ�\n",
		"����˵������Ҫ��������ȡ�֣����Ĳ�ͷ����ץȥ����!\n",
		"�������еĵ�Խ��Խ�죬����Ӧ�Ӳ�Ͼ��\n",
		"����˵������������������ĵط�����\n"
	}) );

	setup();
	carry_object("/clone/armor/yayifu")->wear();
}
