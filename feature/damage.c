// damage.c
// 98-9-11 netplay@CCTX
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

int ghost = 0;

int is_ghost() { return ghost; }

varargs int receive_damage(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	if( type!="jingli" && type!="qi" && type!="douzhi" && type!="shenzhi")
		error("F_DAMAGE: �˺��������( ֻ���� jingli,qi,douzhi,shenzhi ����֮һ )��\n");

	if( objectp(who) ) set_temp("last_damage_from", who);
	val = (int)query(type) - damage;

	if( val >= 0 ) set(type, val);
	else set( type, -1 );

	set_heart_beat(1);

	return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	if( type!="jingli" && type!="qi" )
		error("F_DAMAGE: �˺��������( ֻ���� jingli, qi ����֮һ )��\n");

	if( objectp(who) ) set_temp("last_damage_from", who);
	val = (int)query("eff_" + type) - damage;

	if( val >= 0 ) set("eff_" + type, val);
	else {
		set( "eff_" + type, -1 );
		val = -1;
	}

	if( (int)query(type) > val ) set(type, val);

	set_heart_beat(1);

	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
	if( type!="jingli" && type!="qi" )
		error("F_DAMAGE: �ָ��������( ֻ���� jingli, qi ����֮һ )��\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
	else set( type, val );

	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
	if( type!="jingli" && type!="qi" )
		error("F_DAMAGE: �ָ��������( ֻ���� jingli, qi ����֮һ )��\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max ) {
		set("eff_" + type, max);
		return max - val;
	} else {
		set( "eff_" + type, val + heal);
		return heal;
	}
}

void unconcious()
{
	object defeater;
	if( !living(this_object()) ) return;
	if( wizardp(this_object()) && query("env/immortal") ) return;

	if( objectp(defeater = query_temp("last_damage_from")) )
		COMBAT_D->winner_reward(defeater, this_object());

	this_object()->remove_all_enemy();
	set("hunmi",1);
	this_object()->clear_written();
	message("system", HIR "\n�����ǰһ�ڣ�����ʲôҲ��֪����....\n\n" NOR,
		this_object());
	this_object()->disable_player("");
	set("jingli", 0);
	set("qi", 0);
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
}

void revive(int quiet)
{
	remove_call_out("revive");
	while( environment()->is_character() )
		this_object()->move(environment(environment()));
		this_object()->enable_player();
	if( !quiet ) {
		COMBAT_D->announce(this_object(), "revive");
		set_temp("block_msg/all", 0);
		set("hunmi",0);
		this_object()->write_prompt();
		message("system", HIY "\n������������������֪��....\n\n" NOR,
			this_object());
	} else
		{set_temp("block_msg/all", 0);set("hunmi",0);}
}

void die()
{
	object corpse, killer;
	mixed diemsg;
	if( !living(this_object()) ) revive(1);
	if( query_temp("sleeped"))
		log_file("sleepdead",CHINESE_D->chinese_time(6,ctime(time()))+"��"+query("id")+"����!"+
			"��Ϣ��"+query("qi")+"������"+query("jingli")+"\n");
	if( wizardp(this_object()) && query("env/immortal") ) return;

	// Clear all the conditions by death.
	// this_object()->clear_condition();
	// ��Ϊ��COMBAT_D->killer_reward����Ҫ��condition�ж��Ƿ�ñ�ͨ�������������ﲻӦ�����
	// ����ƶ�������ȥ

	COMBAT_D->announce(this_object(), "dead");
	
	if ( diemsg=this_object()->query_temp("diemsg") )
	{
	if ( objectp(diemsg) )
	set_temp("my_killer",diemsg->query("id"));
	COMBAT_D->killer_reward(diemsg, this_object());
	}else 
	
	if( objectp(killer = query_temp("last_damage_from")) ) {
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
	}else
		{ diemsg="Ī�����������";
		COMBAT_D->killer_reward(diemsg, this_object());
	     }

	
	this_object()->delete_temp("diemsg");
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
		corpse->move(environment());

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

	this_object()->dismiss_team();
	this_object()->delete_temp("last_damage_from");
	this_object()->clear_condition();//��ǰ����ƶ���������
	if( userp(this_object()) ) {
		if (this_object()->is_busy())
			this_object()->interrupt_me();
		set("jingli", 1);	set("eff_jingli", 1);
		set("qi", 1);	set("eff_qi", 1);
		ghost = 1;
		this_object()->move(DEATH_ROOM);
		DEATH_ROOM->start_death(this_object());
	} else
		destruct(this_object());
}

void reincarnate()
{
	ghost = 0;
	set("eff_jingli", query("max_jingli"));
	set("eff_qi", query("max_qi"));
	set("jingli", query("max_jingli"));
	set("qi", query("max_qi"));
	set("douzhi", query("eff_douzhi"));
	set("shenzhi", query("max_shenzhi"));
	set("neili", query("max_neili"));
}

int max_food_capacity() { return query_weight() / 200; }

int max_water_capacity() { return query_weight() / 200; }

int heal_up()
{
	int update_flag;
	mapping my;
	update_flag = 0;
	my = query_entire_dbase();
	if( my["water"] > 0 ) { my["water"] -= 1; update_flag++; }
	if( my["food"] > 0 ) { my["food"] -= 1; update_flag++; }
	if( my["water"] < 1 && userp(this_object()) ) return update_flag;
	if( my["food"] < 1 && userp(this_object()) ) return update_flag;
	if( my["jingli"] < my["eff_jingli"] ) 
	{
		if ((my["eff_jingli"] - my["jingli"])< (my["con"] / 3 + my["max_jingli"] / 10))
			my["jingli"] += (my["eff_jingli"] - my["jingli"]);
		else my["jingli"] += my["con"] / 3 + my["max_jingli"] / 10;
	}
	else update_flag++;
	if( my["eff_jingli"] < my["max_jingli"] ) 
	{
		 my["eff_jingli"] ++; update_flag++; 
	}
	else update_flag++;
	if( my["douzhi"] < my["eff_douzhi"] ) 
	{
		 my["douzhi"] ++; update_flag++; 
	}
	else update_flag++;
	if ( my["kill"] > (my["combat_exp"] * my["bac"] / 50))
	{
		my["kill"] --; update_flag++;
	}
	else update_flag++;
	if ((my["qi"]/my["max_qi"])*100<50 || (my["eff_qi"]/my["max_qi"])*100<75 || (my["eff_jingli"]/my["max_jingli"])*100<75)
	{
		my["shenzhi"] --;update_flag++;
	}
	else if ((my["qi"]/my["max_qi"])*100<25 || (my["eff_qi"]/my["max_qi"])*100<50 || (my["eff_jingli"]/my["max_jingli"])*100<50)
	{
		my["shenzhi"] -= 2;update_flag++;
	}
	else if ((my["eff_qi"]/my["max_qi"])*100<25 || (my["eff_jingli"]/my["max_jingli"])*100<25)
	{
		my["shenzhi"] -= 5;update_flag++;
	}
	else
	{
		my["shenzhi"] ++;update_flag++;
	}
	if (my["shenzhi"]>my["max_shenzhi"]) my["shenzhi"] = my["max_shenzhi"];
	my["qi"] += my["con"] / 3 + my["max_neili"] / 10;
	if( my["qi"] >= my["eff_qi"] ) {
		my["qi"] = my["eff_qi"];
		if( my["eff_qi"] < my["max_qi"] ) { my["eff_qi"] ++; update_flag++; }
	} else update_flag++;
	if( my["neili"] < my["max_neili"] ) {
		my["neili"] += (int)this_object()->query_skill("force", 1) / 2;
		if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];
		update_flag++;
	}
	return update_flag;
}

//��˯���Ĺ����ƶ���������ͳһ
int sleep()
{
	int rnd;
	int old_no_fight;
	mapping fam;
	object me,where;
	
	me=this_object();
	where=environment(me);
	if ( (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")
		&& !(where->query("sleep_room"))
		|| (where->query("no_sleep_room")) )
	{
		tell_object(me,"���ﲻ������˯�ĵط���\n");
		return 0;
	}
	old_no_fight=where->query("no_fight");//����ɵ�no_fight���ԣ�
	if (me->is_busy())
	{
		tell_object(me,"����æ���أ�\n");
		return 0;
	}
	if( me->is_fighting() )
	{
		tell_object(me,"ս���в���˯����\n");
		return 0;
	}
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("��С���������$N���: �����ﵱ��������! �ȸ�Ǯ������˯!\n",me);
		return 0;
	}

	if (where->query("sleep_room"))
	{
		tell_object(me,"��������һ�ɣ���ʼ˯����\n��һ�������ͽ��������硣\n");
		me->set_temp("block_msg/all",1);
		message_vision("$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);
		rnd = random((60 - me->query_con()) / 3);
	}
	else
	{ 
		tell_object(me,"�������½���һ�ɣ���ʼ˯����\n��һ�������ͽ��������硣\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N�����½�������һ�ɣ���һ�����������������������\n",me);
		rnd = 10 + random((100 - me->query_con()) / 3);
	}
	where->set("no_fight", 1);
	where->add_temp("sleeping_person", 1);
	me->set("no_get", 1);	
	me->set("no_get_from", 1);	
    me->set("no_eat", 1);
	me->set("no_chi", 1);
	if (where->query("hotel"))
	me->delete_temp("rent_paid");
	me->set("sleeps",1);
	me->disable_player("<˯����>");
	if ( rnd < 1 ) rnd = 0;
	call_out("wakeup", rnd + 10, me, where,old_no_fight);
	return 1;
}

void wakeup(object me,object where,int oldnofight)
{
	
	if (!(int)me->query_temp("sleeped"))//������Ǹ�˯��������Ӧ�����Ч��
	{
		me->enable_player();
		if (!(where->query("hotel")))//���ù����������˯��
			me->set_temp("sleeped",1);
		me->set("qi",    me->query("eff_qi"));
		me->set("jingli",  me->query("eff_jingli"));
		me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
		me->set("douzhi", me->query("eff_douzhi"));
	  	call_out("del_sleeped", 179, me);
	  	//�������ڲ����˯�����ı�־����Ȼ�������hotel��û�����������־��
		message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
		me->set_temp("block_msg/all", 0);
		tell_object(me,"��һ��������ֻ���������档�ûһ���ˡ�\n");
	}
	else
	{
		me->enable_player();
		message_vision("$N�������۾����������������������\n",me);
		me->set_temp("block_msg/all", 0);
		tell_object(me,"��һ������������������˯���������Ǻܺá�\n");
		me->add("qi",    (me->query("eff_qi")-me->query("qi"))/2);
		me->add("jingli",  (me->query("eff_jingli")-me->query("jingli"))/2);
		me->add("neili", (me->query("max_neili")/2 - me->query("neili")/2)/2);
	}
	me->delete("sleeps");
	if (!where->query("sleep_room") && !where->query("hotel"))
		where->set("no_fight",oldnofight);
	where->add_temp("sleeping_person", -1);
	me->delete("no_get");	
	me->delete("no_get_from");	
 
}

void del_sleeped(object me)
{
	if (objectp(me) &&  me->query_temp("sleeped"))
		me->delete_temp("sleeped");	
}

