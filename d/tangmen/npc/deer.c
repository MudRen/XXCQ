// yelu.c Ұ¹

inherit NPC;

void create()
{
        set_name( "Ұ¹", ({ "ye lu", "lu", "deer"}) );
	set("race", "Ұ��");
	set("age", 2 + random(3));
        set("long", "һֻ����ߵ��СҰ¹����ͣ�ıı�������\n");
	set("attitude", "peaceful");
        set("str",30);
        set("max_qi",500);
        set("qi",500);
        set("max_jingli",800);
        set("jingli",800);
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "knock", "hoof" }) );

        set("combat_exp", 30000);

        set_temp("apply/attack", 90);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 70);

	setup();
}