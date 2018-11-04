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
        object ob,where;

        where=environment(me);

          me->apply_condition("xhquest", duration - 1);

          message_vision("$N������������һ�����Ľ������̲顣\n", me);
           if (random(15) < 5 && duration >2)
	{
               message_vision(HIG"ͻȻһ���������Ϳ첽�ߵ�$N����ǰ��\n�����ȵ�:������ģ��������ӹ�ȥ�������㣡\n"NOR, me);
                ob = new("/kungfu/class/xuehepai/dizi1");
                  ob->set_name("�������",({"eba","ba"}));
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
                ob->set_skill("force",consider_lv(ob, 5),0);
                ob->set_skill("literate",consider_lv(ob, 5));
                ob->set_skill("dodge",consider_lv(ob, 5),0);
                ob->set_skill("parry",consider_lv(ob, 5),0);
                ob->set_skill(skills["jifaforce"],consider_lv(ob, 5),consider_lv(ob, 5)/4);
                ob->set_skill(skills["jifadodge"],consider_lv(ob, 5),consider_lv(ob, 5)/4);
                ob->set_skill(skills["attack"],consider_lv(ob, 5),consider_lv(ob, 5)/4);
                ob->set_skill(skills["attack2"],consider_lv(ob, 5),consider_lv(ob, 5)/4);
                ob->set_skill(skills["jifaattack"],consider_lv(ob, 5),consider_lv(ob, 5)/4);
                ob->set_skill(skills["jifaattack2"],consider_lv(ob, 5),consider_lv(ob, 5)/4);
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
                 if (!(present("eba",environment(me))))  {
                  message_vision(HIC"\n��������$N΢Ц��:������Ϣ���ˣ���������ˡ���\n\n"NOR, me);
                  me->set_temp("xhjob_ok",1);
                   me->delete_temp("shouwei");
                   me->delete_temp("xhjob_start");
                     return 0;
                   }
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
