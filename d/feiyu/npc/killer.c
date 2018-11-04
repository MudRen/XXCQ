inherit NPC;
void create()
{
        set_name("������", ({ "killer"}));
        set("long",
                "����һ�������ߡ�\n");
        set("gender", "����");
        set("age", 18+random(20));
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 15);
        set("int", 15);
        set("con", 20);
        set("dex", 20);
        set("per", 15);
        set("max_qi", 350);
        set("max_jing", 600);
        set("neili", 500);
        set("max_neili", 500);
        set("shen", -500);
        set("combat_exp", 5000);
        set("score", 2000);
        setup();
        carry_object("/d/feiyu/obj/changjian")->wield();
}

void die()
{
        object corpse, killer;
        if( !living(this_object()) ) revive(1);
        // Clear all the conditions by death.
        this_object()->clear_condition();
        COMBAT_D->announce(this_object(), "dead");
        if( objectp(killer = query_temp("last_damage_from")) ) {
            set_temp("my_killer", killer->query("id"));
            COMBAT_D->killer_reward(killer, this_object());
        }
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        if (userp(killer))
        {
		killer->set_temp("killed_killer");
        }
        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());
        this_object()->dismiss_team();
        destruct(this_object());
}
