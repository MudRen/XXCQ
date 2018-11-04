// NPC: zzold.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit NPC;

void create()
{
        set_name("׳���ϲ�", ({ "old man"}) );
        set("gender", "����" );
        set("age", 50+random(10));
        set("long",
                "����һλ׳���ϲ���ͷ��΢�ף����������Ķ࣬����ܷḻ�����ӡ�\n");
        set("attitude", "friendly");

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 600);
        set("max_jingli", 600);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 15);

        set("combat_exp", 3500);

        setup();
}

int accept_object(object who, object ob)
{
	
        if (ob->query("money_id") && ob->value() >= 100) 
        {
                tell_object(who, "׳���ϲ�Ц��Ц˵����л�ˣ���ʲô�����ܴ����������\n");

                who->set_temp("rent_paid",1);

                return 1;
        }

        return 0;
}
