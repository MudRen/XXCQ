// ghost.c

inherit NPC;

int ask_fight();

void create()
{
	set_name("��Ӱ", ({ "ghost shadow", "shadow" }) );
	set("age", 40);
	set("long", "һ����������ĺ����ˡ�\n");
	set("attitude", "friendly");
	
	set("str", 26);
	set("cor", 30);
	set("combat_exp", 100000);
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	set("rank_info/respect", "����");
	set("inquiry", ([
		"bishi": (: ask_fight :),
	]) );
	setup();
}

void my_turn(object ob)
{
	int temp_qi;
	int qi;

	if (ob->query_temp("buster_temp") != 2) {
		call_out("my_turn", 3, ob);
		return;
	}                

	qi = ob->query("max_qi");
	ob->set("eff_qi",qi);
	ob->set("qi",qi);
	this_object()->set("max_qi",qi);
	this_object()->set("eff_qi",qi);
	this_object()->set("qi",qi);
	COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 0);
	temp_qi = ob->query_temp("blood") - (qi - ob->query("qi"));
	ob->set_temp("blood",temp_qi);
	ob->set_temp("buster_temp", 1);
	if (temp_qi < 1) {
		ob->delete_temp("buster_temp");
	}
	say("��Ӱվ�����ﲻ���������ڵȴ�����Ľ���(attack)��\n");
	call_out("my_turn", 3, ob);
	return;
}

int ask_fight()
{
	object ob=this_player();
	object me=this_object();
	int qi;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	if (ob->query_temp("buster_temp")) {
		write("�Ѿ��Ȼ����ˣ�������ʲô��\n");
		return 1; /*"������";*/
	}
	ob->set_temp("buster_temp", 1);
	qi = ob->query("max_qi");
	ob->set("eff_qi",qi);
	ob->set("qi",qi);
	me->set("max_qi",qi);
	me->set("eff_qi",qi);
	me->set("qi",qi);
	me->set("combat_exp",ob->query("combat_exp"));
/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);
	set_temp("max_blood", qi);
	set_temp("blood", qi);
	ob->set_temp("max_blood", qi);
	ob->set_temp("blood", qi);
	say("\n�����ѡ��\n����(attack)\n");
	call_out("my_turn", 3, ob);
	write("������\n");
	return 1;
}

void init()
{
	object ob = this_object();
	::init();
	call_out("dest", 20, ob);
}

void dest(object ob)
{       
	object me = this_player();
	remove_call_out("my_turn");
	if( present(me, environment(ob)))
	write("��Ӱ¶���������Ц�ݣ�ͻȻ��Ӱһ������ӰԽ(yue)�Ϸ��������ˡ�\n");
	destruct(ob);
}