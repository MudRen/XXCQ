// combatd.c
//#pragma optimize all
//Change by Netplay@CctxII (7/99)
//�޸�do_attack() ȡ��Ǳ�ܣ���Ϊ����skill��ʵս�������
//�޸�skill_power() �����㹫ʽ��Ϊ skillռ60% expռ%40

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

//int dpadd;
//����do_attack�ﶨ�岻�£�ֻ�з��������ˣ���֪����ͬ����Դ˱������޸��Ƿ���໥Ӱ�죿
//��ע��Ϊ�˱���������⣬���������temp��Ϊ��ʱ�ı�����
inherit F_DBASE;

string *guard_msg = ({
		CYN "$N��������������Ķ���$n�����$n�����С�\n" NOR,
        CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR,
        CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR,
        CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR,
        CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
        CYN "$N�������ƶ����Ų����Ż����֡�\n" NOR,
});

string *catch_hunt_msg = ({
        HIW "$N��$n������������ۺ죬���̴���������\n" NOR,
        HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR,
        HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR,
        HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR,
        HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR,
        HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR,
        HIW "$N�ȵ�����$n�����У���\n" NOR,});

string *winner_msg = ({
        CYN "\n$N������Ц������˵���������ˣ�\n\n" NOR,
        CYN "\n$N˫��һ����Ц��˵����֪���ҵ������˰ɣ�\n\n" NOR,
        CYN "\n$Nʤ�����У�Ц����ʤ���˱��ҳ��£��������⡣\n\n" NOR,
        CYN "\n$n������˼�����˵�����������շ�����\n\n" NOR,
		//CYN "\n$n���һ�ݣ��޺޵�˵�������ӱ���ʮ�겻��\n\n" NOR,
		CYN "\n$N������Ц��˵���������ˣ�\n\n" NOR,
        CYN "\n$N˫��һ����Ц��˵�������ã�\n\n" NOR,
        CYN "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
        CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
        CYN "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
        CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});

void create()
{
        seteuid(getuid());
        set("name", "ս������");
        set("id", "combatd");
}

string damage_msg(int damage, string type)
{
        string str;

        if( damage == 0 ) return "���û������κ��˺���\n";

        switch( type ) {
        case "����":
		if( damage < 10) return "���ֻ������$p���½š�\n";
		else if ( damage < 20) return "���ֻ�����������$p��Ƥ�⡣\n";
		else if ( damage < 40) return "������͡���һ��ն��һ�����ӡ�\n";
		else if ( damage < 80) return "���ֻ�����꡹��һ������ն��$pƤ�����֡�\n";
		else if ( damage < 160) return " ������꡹��һ������ն����$p�Ĺ�ͷ����Ѫֱ����\n";
		else return "���ֻ����$nһ���Һ���$w����$p$lն��һ��Ѫ��ģ���������˿ڣ���\n";
        case "����":
                if( damage < 10 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
                else if( damage < 20 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
                else if( damage < 40 ) return "������͡���һ������һ���˿ڣ�\n";
                else if( damage < 80 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
                else if( damage < 160 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
                else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
                break;
        case "����":
                if( damage < 10 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
                else if( damage < 20 ) return "�����$p$l�̳�һ�����ڡ�\n";
                else if( damage < 40 ) return "������ۡ���һ��������$n$l����\n";
                else if( damage < 80 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
                else if( damage < 160 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
                else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
                break;
        case "����":
                if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
                else if( damage < 20 ) return "�����$p��$l���һ�����ࡣ\n";
                else if( damage < 40 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
                else if( damage < 80 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
                else if( damage < 120 ) return "������项��һ����$n����������\n";
                else if( damage < 160 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
                else if( damage < 240 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
                break;
        case "����":
                if( damage < 10 ) return "���ֻ�ǰ�$n������˰벽����������\n";
                else if( damage < 20 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
                else if( damage < 40 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
                else if( damage < 80 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
                else if( damage < 120 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
                else if( damage < 160 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                else if( damage < 240 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
                else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
                break;
        default:
                if( !type ) type = "�˺�";
                if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
                else if( damage < 20 ) str = "��������΢��";
                else if( damage < 30 ) str = "������һ��";
                else if( damage < 50 ) str = "������һ������";
                else if( damage < 80 ) str = "��������Ϊ���ص�";
                else if( damage < 120 ) str = "�������൱���ص�";
                else if( damage < 170 ) str = "������ʮ�����ص�";
                else if( damage < 230 ) str = "�����ɼ������ص�";
                else str =  "�����ɷǳ����µ�����";
                return str + type + "��\n";
        }
}

string eff_status_msg(int ratio)
{
        if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
        if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
        if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
        if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
        if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
        if( ratio > 40 ) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
        if( ratio > 30 ) return HIR "�Ѿ��˺����ۣ���������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
        if( ratio > 10 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        if( ratio > 5  ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
        return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string status_msg(int ratio)
{
        if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
        if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
        if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
        if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
        if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
        if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
        if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
        if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}


varargs void report_status(object ob, int effective)
{
	if( effective ) 
		message_vision( "( $N" + eff_status_msg(
			(int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi") ) 
			+ " )\n", ob);
	else
		message_vision( "( $N" + status_msg(
			(int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
			+ " )\n", ob);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
// �����������ĳ�ְ󶨵�skills�Ĺ����ͷ�����
varargs int skill_power(object ob, string skill, int usage)
{
	int level, power;

	if( !living(ob) ) return 0;

	level = ob->query_skill(skill);
	

	switch(usage) {
		case SKILL_USAGE_ATTACK:
			level += ob->query_temp("apply/attack");
			break;
		case SKILL_USAGE_DEFENSE:
			level += ob->query_temp("apply/defense");
			if (ob->is_fighting())
				level = level * (100 + ob->query_temp("fight/dodge")) / 100;
			break;
	}

	if( !level ) return (int)ob->query("combat_exp") / 2;

	power = level*level*level/10 * 60/100; //�ȼ���ռ����60%

	//exp��ռ����40%
	if (usage == SKILL_USAGE_ATTACK)
		return (power + (ob->query("combat_exp")) / 30 * ob->query_str()) * 40/100;
	else
		return (power + (ob->query("combat_exp")) / 30 * ob->query_dex()) * 40/100;
	//return 1; ok?
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
	mapping my, your, prepare, action;
	string limb, *limbs, result;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo;
	int ap, dp, pp;
	int damage, damage_bonus, temp = 0;
	//����maxvar ������tempȡ��temp��wounded������
	//ͬʱҲ��Ϊdpadd�����ã�����־�Թ�����Ӱ�졣for snow mud . jackyboy 1999/11/7
	int award_me,award_you;
	award_me=random(me->query_skill("feat"));
	award_me=award_me*30/me->query("int");
	
	award_you=random(victim->query_skill("feat"));
	award_you=award_you*30/victim->query("int");

	if (environment(me)->query("no_fight")||environment(victim)->query("no_fight"))
		return notify_fail("�����ֹս����Ӵ��\n");
	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();
	//�ҳ�������׼��Ҫ���õĹ���
	prepare = me->query_skill_prepare();
	
	if (!prepare) prepare = ([]);

	if( objectp(weapon) )	attack_skill = weapon->query("skill_type");
	else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
	else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[me->query_temp("action_flag")];

	martial_skill=me->query_skill_mapped(attack_skill);//�����������õ�����skill

	// (1) Find out what action the offenser will take.
	// �ҳ������߲���ʲôaction
	me->reset_action();
	action = me->query("actions");
	if( !mapp(action) ) {
		me->reset_action();//Ϊʲô�ٴε��ã�
		action = me->query("actions");//Ϊ�˱����������actionsΪaction???
		if( !mapp(action) ) {//���Ҳ������Բ��õ�action����sysƵ����ʾ����
			CHANNEL_D->do_channel( this_object(), "sys",
				sprintf("COMBAT_D(do_attack) >> %s(%s): bad action = %O",
					me->name(1), me->query("id"), me->query("actions", 1)));
			return 0;
		}
	}

	if (me->query_temp("action_flag") == 0)//�˱�־Ϊ1��ʾ�ո�����һ��action������
		result = "\n" + action["action"] + "��\n";
	else
		result = "\n" + "������"+action["action"] + "��\n"; 

	//
	// (2) Prepare AP, DP for checking if hit.
	// 
	limbs = victim->query("limbs");
	//��ѯ�������߿ɱ�������Щ��λ����chard.c���ж��壬Ҳ�����ڳ��������¶���
	limb = limbs[random(sizeof(limbs))];//ѡ��һ����λ����
	//��־��dp��Ӱ�� for snow mud
	temp = my["douzhi"] - 100;
	if (temp < 0) temp = - temp;
	
	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);//���㹥������ap��
	
	if( ap < 1) ap = 1;
	if (userp(me) && intp(action["dodge"]))
		me->set_temp("fight/dodge", action["dodge"]);

	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);//����Է��ķ�������dp
	//��־�Զ�ܵ�Ӱ��
	dp = dp * my["eff_douzhi"] / (temp + my["eff_douzhi"]);
	if( dp < 1 ) dp = 1;
	if( victim->is_busy() ) dp /= 3;//�����������æ����������������

	//
	// (3) Fight!
	//     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
	//     AP and DP are greater than zero, so we always have chance to hit
	//     or be hit.
	//
	if( random(ap + dp) < dp ) { 		// Does the victim dodge this hit?
		//���ap���ߣ��ͺܿ���ִ����γ��򣬱�ʾ����ʧ�󣬱������߶㿪��
		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

		if( dp < ap && (!userp(victim) || !userp(me)) 
		&&	random(your["jingli"]*100/your["max_jingli"] + your["int"]) > 50 ) {
			//���ϴ�������ʱ�򱻹������Ṧ�����̶ȼ�һ
			your["combat_exp"] += 1;
			victim->improve_skill("dodge", random(your["int"]));
			//��������������Ṧ���ü������
			if(dodge_skill != "dodge")
			victim->active_skill(dodge_skill, award_you);
		}

		// This is for NPC only. NPC have chance to get exp when fail to hit.
		if( (ap < dp) && !userp(me) ) {
			//�����������npc�����ʱnpc��ս�������һ���������ʹ�õļ���
			if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
			me->improve_skill(attack_skill, random(my["int"]));
			if(martial_skill)
			me->active_skill(martial_skill, award_me);
		
		}
		damage = RESULT_DODGE;
	}
	else //������ܶ㿪�Ļ�,���Ƿ����м�
	{
		//	(4) Check if the victim can parry this attack.
		//�����У���鱻�������Ƿ��ܹ��мܴ˴ι���
		if( victim->query_temp("weapon") ) 
		{
			//����������߳��б���
			pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
			if( !weapon ) pp *= 2;//���������û�гֱ������м�������������
		}
		else
		{
			pp=( weapon )? 0 : skill_power(victim, "unarmed", SKILL_USAGE_DEFENSE);
		}
		//��־���мܵ�Ӱ��
		pp = pp * my["eff_douzhi"] / (temp + my["eff_douzhi"]);
		if( victim->is_busy() ) pp /= 3;//�����������æ���м���������3��
		if( pp < 1 ) pp = 1;

		if( random(ap + pp)< pp ) 
		{
			//�������������ܿ���ִ����γ��򣬼��ܿ��ܱ��м�ס
			parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill ) parry_skill = "parry";
			// change to SKILL_D(parry_skill) after added parry msg to those
			// martial arts that can parry.
			result += SKILL_D(parry_skill)->query_parry_msg(weapon);
			//�����ǲ���Ӧ����parry_skill�أ�
			
			if( dp < ap && (!userp(victim) || !userp(me)) 
			&&	random(your["jingli"]*100/your["max_jingli"] + your["int"]) > 50 )
			{
				//�����һ��������ң��򱻹����߾����һ��parry���һ��
				your["combat_exp"] += 1;
				victim->improve_skill( "parry", random(your["int"]) );
				if(parry_skill != "parry")
				victim->active_skill(parry_skill, award_you);
		
			}
			damage = RESULT_PARRY;

		} else {

			//
			//	(5) We hit the victim and the victim failed to parry
			//������������޷��мܾ�������
			damage = me->query_temp("apply/damage");
			damage = (damage + random(damage)) / 2;
			if( action["damage"] )
				damage += action["damage"] * damage / 100;

			damage_bonus = me->query_str();//����Խ�󣬹�����Խǿ

			// Let force skill take effect.
			if( my["jiali"] && (my["neili"] > my["jiali"]) ) {
				if( force_skill = me->query_skill_mapped("force") ) 
				{
					//�����������Ĺ������ǲ���ÿ��force�ļ���Ҫ��hit_ob��������һ��������
					foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
					if( stringp(foo) ) result += foo;
					else if( intp(foo) ) damage_bonus += foo;
				}
			}

			if( action["force"] )
				damage_bonus += action["force"] * damage_bonus / 100;

			if( martial_skill ) 
			{
				//���ù���ʹ�ù����hit_ob�������õ��ַ����ؽ�������͵����˳̶�
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			// Let weapon or monster have their special damage.
			if( weapon ) 
			{
				//�����������������⹥����Ϣ�򹥻���
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
			else 
			{
				//�������ֻ����me��npc��ʱ������ã�
				foo = me->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if( damage_bonus > 0 )
				damage += (damage_bonus + random(damage_bonus))/2;
			if( damage < 0 ) damage = 0;

			// Let combat exp take effect
			// ����������ߵľ���ȹ����߸ߺܶ࣬��ô�˺���Ϊ����֮һ
			temp = your["combat_exp"];
			while( random(temp) > my["combat_exp"] ) {
				damage -= damage / 3;
				temp /= 2;
			}
			temp = 0; 	
			//
			//	(6) Inflict the damage.
			//ʹ������������
			
			//��־�Թ�������Ӱ��
			damage = (int)( ( damage * my["douzhi"]) / my["eff_douzhi"] );	
			//��־�ļӼ�
			if (( (damage *100 / your["max_qi"]) >= 1 )
				&& ( (damage *100 / your["max_qi"]) < ((60 - your["bac"]) / 10 )))
				victim->add("douzhi", -1);
			else if (( (damage *100 / your["max_qi"]) >= ((60 - your["bac"]) / 10 ))
				&& ( (damage *100 / your["max_qi"]) < your["bac"] / 2 ))
				victim->add("douzhi", 2);
			else if (( (damage *100 / your["max_qi"]) >= your["bac"] / 2 )
				&& ((damage *100 / your["max_qi"]) < your["bac"] ))
				victim->add("douzhi", -5);
			else if ((damage *100 / your["max_qi"]) >= your["bac"] )
				victim->add("douzhi", -20);
			if (your["douzhi"] < 0) your["douzhi"] = 0;
			if (your["douzhi"] >your["max_douzhi"]) your["douzhi"] = your["max_douzhi"];
			if ( wizardp(me))
				tell_object(me, YEL"\n" + victim->query("name") + "�Ķ�־��"+your["douzhi"]+"   �㹥����������"+damage+"   " + victim->query("name") + "��������"+your["bac"]+NOR);
			if ( wizardp(victim))
				tell_object(victim, "\n��Ķ�־��"+your["douzhi"]+"   " + me->query("name") + "������������"+damage + "   ���������"+your["bac"]);

			damage = victim->receive_damage("qi", damage, me );
			if( random(damage) > (int)victim->query_temp("apply/armor")
			&& ( (me->is_killing(victim->query("id"))) 
				&& ((!weapon) && !random(4) || weapon && !random(2) )
			    || ( (!weapon) && !random(7) || weapon && !random(4) ) )  )
			{
				// We are sure that damage is greater than victim's armor here.
				//���˳̶�Ӧ�ñȹ����ߵ�apply/armor��
				victim->receive_wound("qi",
					damage - (int)victim->query_temp("apply/armor"), me);
				temp = 1;
			}

			result += damage_msg(damage, action["damage_type"]);
			//�������˳̶ȣ����õ�������ʾ����Ϣ
			//
			//	(7) Give experience
			//����Ľ�������
			if( !userp(me) || !userp(victim) ) //��Ҵ����û�н���
			{
				//���������skill��˵��ֻҪ�����˶Է������п��ܻ�����
				if(martial_skill && random(my["int"]) > 15
					&& your["combat_exp"] > my["combat_exp"]*2/3)
				me->active_skill(martial_skill, award_me);
				
				if( (ap < dp)
				&&	(random(my["jingli"]*100/my["max_jingli"] + my["int"]) > 30) ) {
					my["combat_exp"] += 1;
					me->improve_skill(attack_skill, award_me);
				}
				if( random(your["max_qi"] + your["qi"]) < damage ) {
					your["combat_exp"] += 1;
				}
			}
		}
	} 
	//���漸��ȡ��һЩ��Ϣ�еĴ���
	result = replace_string( result, "$l", limb );
	if( objectp(weapon) )
		result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
		result = replace_string( result, "$w", action["weapon"] );
	else if( attack_skill == "finger" ) 
		result = replace_string( result, "$w", "��ָ" );

	message_vision(result, me, victim );

	if( wizardp(me) && (string)me->query("env/combat") )
	{
		//֪ͨ��ʦ�˴ι������˺��̶�
		if( damage > 0 )
			CHANNEL_D->do_channel( this_object(), "debug", sprintf("AP��%d��DP��%d��PP��%d���˺�����%d\n" ,
				ap/100, dp/100, pp/100, damage));
		else
			CHANNEL_D->do_channel( this_object(), "debug", sprintf("AP��%d��DP��%d��PP��%d\n" ,
				ap/100, dp/100, pp/100));
	}

	if( damage > 0 ) 
	{
		report_status(victim, temp);//��ʾ�������ߵ�״̬
		if( victim->is_busy() ) victim->interrupt_me(me);
		if( (!me->is_killing(your["id"])) && 
		(!victim->is_killing(my["id"])) &&
		victim->query("qi")*2 <= victim->query("max_qi")) 
		{
			//����kill��ʱ��Ĵ���
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			if(me->query_temp("biwu"))
				me->fight_winner(victim);
			message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
		}
	}

	if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);

	// See if the victim can make a riposte.
	//�жϱ��������Ƿ��ܷ���
	if( attack_type==TYPE_REGULAR
	&&	damage < 1
	&&	victim->query_temp("guarding") )
	{
		victim->set_temp("guarding", 0);
		if( random(my["dex"]) < 5 )
		{
			message_vision("$Nһ�����У�¶����������\n", me);
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
		} else {
			message_vision("$N��$n����ʧ�󣬳û�����������\n", victim, me);
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
		}
	}
}

//	fight()
//
//	This is called in the attack() defined in F_ATTACK, which handles fighting
//	in the heart_beat() of all livings. Be sure to optimize it carefully.
//  �������������һЩ������F_ATTACK(ͨ����/feature/attack.c)���һЩ��������fight_ob
void fight(object me, object victim)
{
	
	if( !living(me) ) return;
	//���me�������������fight���ã�
	
	// If victim is busy or unconcious, always take the chance to make an attack.
	//�����fight�Ķ���æ����ԣ���ô�����ܷ�������
	if( victim->is_busy() || !living(victim) ) {
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

		if( me->is_fighting(victim) && victim->is_fighting(me)) 
			if( (!objectp(me->query_temp("weapon")) && sizeof(me->query_skill_prepare()) > 1))
			{
			   me->set_temp("action_flag",1);
			   do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
			   me->set_temp("action_flag",0);
		    }
	// Else, see if we are brave enough to make an aggressive action.
	} 
	else 
	if( random( (int)victim->query_dex() * 3 ) > (int)me->query_str()) 
	{//�������������*3������Ч������ִ������ĳ���
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);  
		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
		if( me->is_fighting(victim) && victim->is_fighting(me)) 
			if( (!objectp(me->query_temp("weapon")) && sizeof(me->query_skill_prepare()) > 1))
			{
			   me->set_temp("action_flag",1);
			   do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
			   me->set_temp("action_flag",0);
			}
	// Else, we just start guarding.
	} else 
	if( !me->query_temp("guarding") ) 
	{
		//��ʼ����
		me->set_temp("guarding", 1);
		message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
		return;
	} 
	else 
		return;
}

//	auto_fight()
//
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
//������������Զ�����fight״̬��
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	//����Ǳ���npc�Զ�ͬnpcս���ģ�
	if( !userp(me) && !userp(obj) ) return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int shen;

	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	shen = 0 - (int)me->query("shen");
	message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

	if( !userp(me) || (int)me->query("neili") > (random(shen) + shen)/10 ) return;
	//�����npc������������shen��һ������仯��Χ����10��Ҳ����˵shen��Ƚ���������̫����
	//����ѹ��סɱ����
	if( shen > (int)me->query("score") //score����һ��ʲô�����أ�
	&&	!wizardp(obj) ) {
		message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
			+ "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
		me->kill_ob(obj);
	} else {
		message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
			+ "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n",
			me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our hatred! Charge!
	message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
	switch(event) {
		case "dead":
			message_vision("\n$N���ˡ�\n\n", ob);
			break;
		case "unconcious":
			message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
			break;
		case "revive":
			message_vision("\n$N���������۾��������˹�����\n\n", ob);
			break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);//û�з�����������Ķ��壡
}

void killer_reward(mixed killer, object victim)
{
	int bls;
	string vmark,diemessage="";

	//netplay add
	if(stringp(killer)) diemessage=killer;
	if(objectp(killer)) 

	// Call the mudlib killer apply.
	//???�������������ϵͳ����İɣ�Ҳ�Ҳ���ѽ��
	killer->killed_enemy(victim);
	
	if( userp(victim) ) {
		if(objectp(killer)) 
		killer->add("PKS", 1);
		//victim->clear_condition(); Ϊ��ʵ�־͵ش������ƶ��������ˣ���ο�ע�ͣ�
		// Give the death penalty to the dying user.
		victim->add("shen", -(int)victim->query("shen") / 10);
		victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);
		victim->delete("vendetta");
		if( victim->query("thief") )
			victim->set("thief", (int)victim->query("thief") / 2);
		if( (int)victim->query("potential") > (int)victim->query("learned_points"))
			victim->add("potential",
				((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
		victim->skill_death_penalty();
		// Add by jungu             
		if (objectp(killer))  if (userp(killer))
		write_file("/log/static/KILL_PLAYER",sprintf("%s(%s) killed by %s(%s) on %s\n",
		victim->name(1), victim->query("id"),
		killer->name(1),killer->query("id"),ctime(time()) ));
		
		// Look for PKS 
		bls = 10;
		
		if (objectp(killer))
		{
			if ( interactive(killer))
			{ 
				if(victim->query_condition("killer"))
				{
					CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s��%s�͵ش����ˡ�", victim->name(1), killer->name(1)));
				}
				else
				{
					CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s��%sɱ���ˡ�", victim->name(1), killer->name(1)));
					CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s���ٸ�ͨ���ˡ�", killer->name(1)));
				}
			}
			else {
				if(victim->query_condition("killer"))
					CHANNEL_D->do_channel(this_object(),"rumor",
					sprintf("%s��%s�͵ش����ˣ�",victim->name(1),killer->name(1)));
				else
					CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s��%sɱ���ˡ�", victim->name(1), killer->name(1)));
			}
			if(!victim->query_condition("killer"))
				killer->apply_condition("killer", 500);
		}else 
		if (stringp(killer)){
			CHANNEL_D->do_channel(this_object(), "rumor",
				sprintf("%s%s��", victim->name(1), diemessage));
			return;
		}
		victim->clear_condition();//��ʵ���˴������жϺ������ɱ�ߵ�״̬��
	} else {
		if (objectp(killer))
		{
		killer->add("MKS", 1);
		bls = 1;		}
	}

	if (objectp(killer) && userp(killer) && killer->query("combat_exp") < victim->query("combat_exp")) 
		killer->add("shen", -(int)victim->query("shen") / 10);
	//vendetta -> �����
	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);
}
