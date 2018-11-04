// wolf.c

inherit NPC;

void create()
{
	set_name("Ұ��", ({ "wolf","lang" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ�ݹ����Ļ�ɫ���ǡ�\n");
	set("attitude", "heroism");

        set("str",35);
	set("dex", 35);
        set("max_qi",600);
        set("qi",600);
        set("max_jingli",900);
        set("jingli",900);
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"Ұ������Ѫ��������������\n",
		"Ұ�Ƕ���������������\n",
	}) );		

        set("combat_exp", 50000);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 10);

	setup();
}

void init()
{
        object ob;
        ::init();

        if (living(this_object()) && interactive(ob = this_player()) && random(ob->query_kar() + ob->query_per()) < 30)
	{
 	       remove_call_out("kill_ob");
	        call_out("kill_ob", 2, ob); 
        }
}