// ding.c �Ҷ�

inherit NPC;

int ask_baishi();

void create()
{
	set_name("�Ҷ�", ({ "jia ding", "ding" }));
	set("age", 25);
	set("gender", "����");
	set("long", "����һ����׳���������ӣ�ÿ�������һЩ�˲赹ˮ����ɨͥ���Ĺ�����\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("strike", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	setup();

	carry_object(__DIR__"obj/liangongfu")->wear();
}