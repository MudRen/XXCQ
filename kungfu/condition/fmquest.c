// fmquest.c

#include <ansi.h>
#include <login.h>


mapping skills= 
        ([      "jifaforce":            "tianyu-xinfa",
                "jifadodge":            "tianyu-shenfa",
                "attack":               "finger",
                "jifaattack":           "changkong-zhi",
                "attack2":              "sword",
                "jifaattack2":          "tianyu-qijian",
                "weapon":               "/clone/weapon/changjian",
                "armor":                "/clone/misc/cloth",
        ]);

int consider_lv(object ob,int a);

int update_condition(object me, int duration)
{
                 object *obb;
                 int i;
        object ob,where;

        where=environment(me);

	me->apply_condition("fmquest", duration - 1);

        if (file_name(environment(me))!=me->query_temp("where")) {
         message("channel:chat",HIY"�����ܡ�"NOR" ĳ�����ƹ��¸���:�ҿ���"+me->query("name")+"����ִ�������ڼ䣬��Ȼ����ְ�أ�\n"NOR,users());
        me->set_temp("job_huaxin",1);
        me->apply_condition("fmquest",0);
        return 0;
        }
        message_vision("$Nװ��"+me->query("duishou")+"���ӣ�ע����ÿһ���˵ľ�ֹ���С�\n", me);
            if (random(15)<6 && duration >0)
	{
             message_vision(HIG"ͻȻ"+me->query("duishou")+"���ӿ첽����$N����ǰ�������ȵ�������\n�󵨣�������װ���ŵ��ӣ���������\n"NOR, me);
                ob = new("/d/chengdu/npc/tufei");
                ob->set_name(me->query("duishou")+"����",({"dizi"}));
		ob->set("combat_exp",me->query("combat_exp"));
		ob->set("max_qi",me->query("max_qi")*80/100);
		ob->set("eff_qi",me->query("max_qi")*80/100);
		ob->set("qi",me->query("max_qi")*80/100);
		ob->set("max_jingli",me->query("max_jingli")*80/100);
		ob->set("eff_jingli",me->query("max_jingli")*80/100);
		ob->set("jingli",me->query("max_jingli")*80/100);
		ob->set("max_neili",me->query("max_neili")*80/100);
		ob->set("neili",me->query("max_neili")*80/100);
                ob->set_skill("force",consider_lv(ob, 8));
                ob->set_skill("dodge",consider_lv(ob, 8));
                ob->set_skill("parry",consider_lv(ob, 8));
                ob->set_skill("sword",consider_lv(ob, 8));
                ob->set_skill("blade",consider_lv(ob, 8));
                ob->set_skill("hammer",consider_lv(ob, 8));
                ob->set_skill("whip",consider_lv(ob, 8));
                ob->set_skill("staff",consider_lv(ob, 8));
                 if (me->query("combat_exp")>100000)
                {
                ob->set_skill("force",consider_lv(ob, 5));
                ob->set_skill("literate",consider_lv(ob, 5));
                ob->set_skill("dodge",consider_lv(ob, 5));
                ob->set_skill("parry",consider_lv(ob, 5));
                ob->set_skill(skills["jifaforce"],consider_lv(ob, 5));
                ob->set_skill(skills["jifadodge"],consider_lv(ob, 5));
                ob->set_skill(skills["attack"],consider_lv(ob, 5));
                ob->set_skill(skills["attack2"],consider_lv(ob, 5));
                ob->set_skill(skills["jifaattack"],consider_lv(ob, 5));
                ob->set_skill(skills["jifaattack2"],consider_lv(ob, 5));
                ob->map_skill("force",skills["jifaforce"]);
                ob->map_skill("dodge",skills["jifadodge"]);
                ob->map_skill("parry",skills["jifaattack2"]);
                ob->map_skill(skills["attack"],skills["jifaattack"]);
                ob->map_skill(skills["attack2"],skills["jifaattack2"]);
                ob->prepare_skill(skills["attack"],skills["jifaattack"]);
                ob->carry_object(skills["weapon"])->wield();
                ob->carry_object(skills["armor"])->wear();
                }


		ob->move(environment(me));
		ob->kill_ob(me);
                me->kill_ob(ob);
        }

	if ( duration < 1 )
	{
		message_vision(HIC"\n$N�����Լ��Ѿ�̽��������Ҫ�鱨�����Ҿô���������ȥ��\n\n"NOR, me);
		me->set_temp("job_ok",1);
obb=all_inventory(environment(me));
                        for(i=0; i<sizeof(obb); i++) {
                                if (obb[i]->is_character() )
                                {
                                        if (interactive(obb[i])) continue;
                                        if (obb[i]->query("id")!="dizi") continue;
                                        destruct(obb[i]);
                                        
                                }
                        }
		return 0;
	}

	return 1;
}

int consider_lv(object ob,int a)
{
	int level; 
	float exper;

	exper = to_float(ob->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333) );

	level = level * a / 10;

	return level;
}
