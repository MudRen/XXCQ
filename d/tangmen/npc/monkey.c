// monkey.c

inherit NPC;

void create()
{
	set_name("ɽ��",({"monkey", "houzi", "hou"}) );
	set("race", "Ұ��");
        set("gender", "����" );
        set("age", 15);
        set("long", "����һֻ�׺���ɽ�\n");
        set("combat_exp", 20000);
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
        set("attitude", "heroism");

        set("max_qi",800);
        set("qi",800);
        set("max_jingli",800);
        set("jingli",800);
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "knock", "hoof" }) );

        set_temp("apply/damage", 20);
        set_temp("apply/armor", 20);

        setup();
}