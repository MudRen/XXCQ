inherit NPC;
void create()
{
    set_name("����", ({ "guai she", "snake", "she" }) );
	set("race", "Ұ��");
	set("age", 30);
    set("long", "һ�������������۾����ߡ�\n");
    set("attitude", "aggressive");
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "twist", "bite" }) );
	set("combat_exp", 5500);
	set_temp("apply/attack", 55);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	setup();
}

void init()
{
        object ob = this_player();
        ::init();
        if (interactive(ob) &&
                !ob->query_skill("hamagong", 1)) {
                        this_object()->kill_ob(this_player());
        }
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("bt_poison",
                victim->query_condition("bt_poison") + 20);
        return 0;
}