// cuihua.c
// By adx @ CuteRabbit 22:21 99-3-19

inherit NPC;

void create()
{
	set_name("��������",({ "peilian" }) );
        set("gender", "����" );
        set("age", 25);
        set("long", "���Ǹ���ݵ��������ӡ�\n");

        set("shen_type", -1);
	set("per", 20);
        set("str", 15);
        set("dex", 18);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 4000);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 10);
        set("attitude", "peaceful");
        setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("coin",80);
}

