// skill.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// change by Netplay@CCTX2 (7/99)
//���Ӻ��� active_skill() ���skill�����ȼ�
//�޸ĺ��� query_skill() ʹ���ķ��ؽ��Ϊ�����ȼ���ѧϰ�ȼ�֮�����Ч�ȼ�
//�޸ĺ���set_skill()��������������1��skill name 2��ѧϰ�ȼ� 3��ʵս�ȼ�
//�޸���Ӧdelete_skill()
#include <ansi.h>
#include <dbase.h>

mapping acv_lear;
mapping actives;
mapping skills;
mapping learned;
mapping skill_map;
mapping skill_prepare;

mapping query_skills() { return skills; }
mapping query_learned() { return learned; }
mapping query_actives() { return actives; }
mapping query_acv_lear() { return acv_lear; }
//�����˵������������������ӿɱ��������˵��
varargs void set_skill(string skill, int val, int val1)
{
	if( !intp(val1) )
		val1=0;
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");
	//����Ѿ�ѧ�����skills��ֱ���޸ļ��𣬷��򴴽�skill���mapping
	if( !mapp(skills) ) skills = ([ skill: val ]);
	else skills[skill] = val;
	//���ʵսֵ����������Ϊ��ѧϰֵһ��
	if ( (val1 > val ))
	val1=val;
	//�����û��actives�򴴽����actives
	if( !mapp(actives)) actives = ([skill: val1]);
	else
	{
		//���val1Ϊ0������
		if(val1)
			 actives[skill] = val1;
	}
}

int delete_skill(string skill)
{
	if( mapp(skills) ) {
		map_delete(skills, skill);
		if( mapp(learned) ) {
			map_delete(learned, skill);
			if( mapp(actives) ) {
				map_delete(actives, skill);
				if( mapp(acv_lear) ) {
				map_delete(acv_lear, skill);
				return undefinedp(acv_lear[skill]);
				}	
			return undefinedp(actives[skill]);
			}
		return undefinedp(learned[skill]);
		}
	return undefinedp(skills[skill]);
	}
	return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_map) ) {
		map_delete(skill_map, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;
		
	if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
	else skill_map[skill] = mapped_to;
}

// This function 'prepare' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the prepared skill <skill>.
varargs void prepare_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_prepare) ) {
		map_delete(skill_prepare, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;
		
	if( !mapp(skill_prepare) ) skill_prepare = ([ skill: mapped_to ]);
	else skill_prepare[skill] = mapped_to;
}

string query_skill_mapped(string skill)
{
	if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
		return skill_map[skill];
	return 0;
}

string query_skill_prepared(string skill)
{
	if( mapp(skill_prepare) && !undefinedp(skill_prepare[skill]) )
		return skill_prepare[skill];
	return 0;
}

varargs int query_skill(string skill, int raw)
{
	if( !raw ) {
		int s,i=0;
		s = query_temp("apply/" + skill);
		if( mapp(skills) ) {
			s += skills[skill] / 2;
			if( mapp(skill_map) )
			{
				//��Ϊʵս������û����ȫOK�����Խ���������Ϊ���ڵı�׼
				//����ʹʵս��Ӱ���С
				i += skills[skill_map[skill]]*80/100;
				//�������������Ҫ�ȹ��������ⲿ��Ӧ�����ݴ���
				if( !mapp(actives))
					actives = ([skill: 0]);
				else
					actives[skill] = 0;
				i += skills[actives[skill]]*20/100;
			}
			s+=i;
		}
		return s;
	}
	if(raw=1) 
	if( mapp(skills) && !undefinedp(skills[skill]) ) return skills[skill];
	if(raw=2)
	if( mapp(actives) && !undefinedp(actives[skill]) ) return actives[skill];
	return 0;
}

mapping query_skill_map()
{
	return skill_map;
}

mapping query_skill_prepare()
{
	return skill_prepare;
}

int skill_death_penalty()
{
	string *sk;
	int i;

	if( wizardp(this_object()) || !mapp(skills) ) return 0;

	sk = keys(skills);
	if( !mapp(learned) )
		for(i = 0; i<sizeof(sk); i++) {
			skills[sk[i]]--;
			if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
		}
	else
		for(i = 0; i<sizeof(sk); i++) {
			if( (int)learned[sk[i]] > (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2 )
				map_delete(learned, sk[i]);
			else {
				skills[sk[i]]--;
				if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
			}
		}
	skill_map = 0;
	return 1;
}

varargs void improve_skill(string skill, int amount, int weak_mode)
{
	int spi;

	if (!userp(this_object()))
		return;
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");
	if( !weak_mode || !userp(this_object()) ) {
		if( !mapp(skills) ) skills = ([]);
		if( undefinedp(skills[skill]) ) skills[skill] = 0;
	}

	// Give learning penalty to those learning too much skills.
//	spi = query("spi");
	spi = 30; // set the default maximum to be 30 (CLEANSWORD CHANGED AT 5/27/96)
	if( sizeof(learned) > spi )
		amount /= sizeof(learned) - spi;

	if( !amount ) amount = 1;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;

//debug 
//printf("%d -> %d",learned[skill],(skills[skill] + 1) * (skills[skill] + 1));

	if( (!weak_mode || !userp(this_object()))
	&&	learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
		skills[skill]++;
		learned[skill] = 0;
		tell_object(this_object(), HIC "��ġ�" + to_chinese(skill) + "�������ˣ�\n" NOR);
		SKILL_D(skill)->skill_improved(this_object());
	}
}

varargs void active_skill(string skill, int amount, int weak_mode)
{
	int spi;
	

	if (!userp(this_object()))
		return;
	//debug
	tell_object(this_object(), sprintf("active���ã�skill: %s,����ֵ��%d\n",skill,amount));

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");
	
	if( !weak_mode || !userp(this_object()) ) {
		if( !mapp(actives) ) actives = ([]);
		if( undefinedp(actives[skill]) ) actives[skill] = 0;
	}

	spi = 30; // set the default maximum to be 30 (CLEANSWORD CHANGED AT 5/27/96)
	if( sizeof(acv_lear) > spi )
		amount /= sizeof(acv_lear) - spi;

	if( !amount ) amount = 1;

	if(mapp(skills) && actives[skill] < skills[skill])
	if( !mapp(acv_lear) ) acv_lear = ([ skill : amount ]);
	else (int)acv_lear[skill] += amount;

	if( (!weak_mode || !userp(this_object()))
	&&	acv_lear[skill] > (actives[skill] + 1) * (actives[skill] + 1) ) 
	{
		actives[skill]++;
		acv_lear[skill] = 0;
		tell_object(this_object(), HIC "�㡸" + to_chinese(skill) + "����ʵս��������ˣ�\n" NOR);
		SKILL_D(skill)->skill_improved(this_object());
	}

}