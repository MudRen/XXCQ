// lmonkey.c

inherit NPC;

void create()
{
	set_name("С����",({"monkey", "hou", "houzi"}) );
	set("race", "Ұ��");
        set("gender", "����" );
        set("age", 7);
        set("long", "����һֻ��Ƥ��С���ӡ�\n");
        set("combat_exp", 100);
	set("str", 15);
	set("dex", 15);
	set("con", 15);
	set("int", 15);
        set("attitude", "peaceful");

        set("max_qi",100);
        set("qi",100);
        set("max_jingli",100);
        set("jingli",100);
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "knock", "hoof" }) );

        set_temp("apply/damage", 10);
        set_temp("apply/armor", 10);

        setup();
}