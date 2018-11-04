// animal: snake.c
// Jay 3/18/96
inherit NPC;

void create()
{
        set_name("��Ҷ��", ({ "zhuye qing", "zhuye", "snake", "she" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һ�����̵��ߣ�����ϸ���Ὣ�����ܱ߱��̵���Ҷ��Ϊһ�塣\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 6000);
        set_temp("apply/attack", 20);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 1);
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
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 12);
        return 0;
}  