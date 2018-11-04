// ding.c �Ҷ�

inherit NPC;

void create()
{
	set_name("�Ҷ�", ({ "jia ding", "ding" }));
	set("age", 25);
	set("gender", "����");
	set("long", "����һ����׳���������ӣ�ÿ����͸����ڷ���Ϊ���Է���佻����ӷ���\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 5000);
	set("shen_type", 1);

	set_skill("strike", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_serve","serve");
}

int do_serve()
{
	object me,ob1,ob2;
	me = this_player();

	if ( present("tang", me) && ((me->query("water"))>(me->query("max_water"))))
	{
		message_vision("�Ҷ�ǫ�����������ǰ����е�����������Ҫ�ɡ�\n",me);
	}
	else
	{
		tell_object(me,"����һʾ�⣬�Ҷ��ͽ�������������\n");
		ob1 = new("/d/huanhua/npc/obj/tang");
		ob1->move(me);
	}

	if ( present("chao fan", me) && ((me->query("food"))>(me->query("max_food"))))
	{
		message_vision("�Ҷ�ǫ�����������ǰ����еķ���������Ҫ�ɡ�\n",me);
	}
	else
	{
		tell_object(me,"����һʾ�⣬�Ҷ��ͽ�������������\n");
		ob2 = new("/d/huanhua/npc/obj/chaofan");
		ob2->move(this_player());
	}

	return 1;
}
