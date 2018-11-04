// rankd.c
// 1996-02-15 dts ranking related to "shen"

#include <ansi.h>

string query_rank(object ob)
{
	mapping fam;

	int shen;
	int budd;
    int swd;

	if( ob->is_ghost() ) 
		return HIB "�� ��  �� ��" NOR;

	shen = ob->query("shen");
	if ( (fam = ob->query("family")) && fam["family_name"] == "������" ) 
		budd = ob->query_skill("buddhism",1);

	switch(ob->query("gender")) {
	case "Ů��":
		//��ֹ��Ҳ鿴��ʦ����
		if(wizardp(ob)&&wiz_level(this_player())<wiz_level("(apprentice)"))
			return HIY "�� ��  Ů ��" NOR;
		switch(wizhood(ob)) {
		case "(admin)":		
			return HIW "�� Ů  �� ��" NOR;
		case "(arch)":		
			return HIR "�� ����Ů ��" NOR;
		case "(hufa)" :
			return WHT "�� Ů���� ��" NOR; 
		case "(wizard)":	
			return HIY "�� ��  Ů ��" NOR;
		case "(angel)":	
			return HIY "�� Ů��ʹ ��" NOR;
		case "(apprentice)":	
			return HIY "�� С��Ů ��" NOR;
		case "(immortal)":	
			return HIC "�� Ů���� ��" NOR;
		default:
			if( ((int)ob->query("PKS") > 100) )
				return "������Ůɱ�˿�";
			if( ((int)ob->query("PKS") > 30) )
				return "��Ůɱ��ħ��";
			else if (shen >= 500000)
				return HIC "������Ů����" NOR;
			else if (shen >= 50000)
				return HIC "�� Ů���� ��" NOR;
			else if (shen >= 5000)
				return HIC "�� Ů  �� ��" NOR;
			else if (shen >= 500)
				return HIC "�� Ů���� ��" NOR;
			else if (shen <= -500000)
				return HIC "�� Ůħ�� ��" NOR;
			else if (shen <= -50000)
				return HIC "�� Ů��ħ ��" NOR;
			else if (shen <= -5000)
				return HIC "�� Ů  ħ ��" NOR;
			else if (shen <= -500)
				return HIC "�� Ů��ħ ��" NOR;
			else if( (int)ob->query("thief") > 10 ) 
				return "��Ů �� �ԡ�";
			else
			switch(ob->query("class")) {
			case "bonze":	
				return "�� ��  �� ��";
			case "taoist":	
				return "�� Ů  �� ��";
			case "bandit":	
				return "�� Ů���� ��";
			case "dancer":	
				return "�� ��  �� ��";
			case "scholar":	
				return "�� ��  Ů ��";
			case "officer":	
				return "�� Ů  �� ��";
			case "fighter":	
				return "�� Ů���� ��";
			case "swordsman":	
				return "�� Ů��ʿ ��";
			case "alchemist":	
				return "�� Ů��ʿ ��";
			case "shaman":		
				return "�� Ů��ҽ ��";
			case "beggar":		
				return "��Ů�л��ӡ�";
        case "tianyumen":
          swd = ob->query_skill("tianyu-qijian",1);
        if (swd >= 200)
                return HIW "��������" NOR;
                  else if (swd >= 150)
        return HIW "������ʥ��" NOR;
      else if (swd >= 100)
        return HIY "����������" NOR;
        else if (swd >= 50)
        return HIY "�����𽣿͡�" NOR;
   else return "������ͯ��";  
			default:			
				return "�� ƽ  �� ��";
			}
		}
	default:
		//��ֹ��Ҳ鿴��ʦ����
		if(wizardp(ob)&&wiz_level(this_player())<wiz_level("(apprentice)"))
			return HIY "�� ��  ʦ ��" NOR;
		switch(wizhood(ob)) {
		case "(admin)":			
			return HIW "�� ��  �� ��" NOR;
		case "(arch)":			
			return HIY "�� ����ʦ ��" NOR;
		case "(hufa)":			
			return WHT "�� ��  �� ��" NOR;
		case "(wizard)":		
			return HIY "�� ��  ʦ ��" NOR;
		case "(angel)":			
			return YEL "�� ��  ʹ ��" NOR;
		case "(apprentice)":		
			return HIG "�� С  �� ��" NOR;
		case "(immortal)":		
			return HIC "�� ��  �� ��" NOR;
		default:
			if( ((int)ob->query("PKS") > 100) )
				return "�� ����ɱ�˿� ��";
			if( ((int)ob->query("PKS") > 30) )
				return "�� ɱ��ħ ��";
			else if (shen >= 500000)
				return HIC "������������" NOR;
			else if (shen >= 50000)
				return HIC "�� ��  �� ��" NOR;
			else if (shen >= 5000)
				return HIC "�� ��  �� ��" NOR;
			else if (shen >= 500)
				return HIC "�� ��  �� ��" NOR;
			else if (shen <= -500000)
				return HIC "�� ħ  �� ��" NOR;
			else if (shen <= -50000)
				return HIC "�� ��  ħ ��" NOR;
			else if (shen <= -5000)
				return HIC "�� ħ  ͷ ��" NOR;
			else if (shen <= -500)
				return HIC "�� ��  ħ ��" NOR;
			else if( (int)ob->query("thief") > 10 ) 
				return "�� ��  �� ��";
			else
				switch(ob->query("class")) {
				case "bonze":		
					if (budd >= 150)
						return HIY "�� ��  �� ��" NOR;
					else if (budd >= 120)
						return HIY "�� ʥ  ɮ ��" NOR;
					else if (budd >= 90)
						return HIY "�� ��  �� ��" NOR;
					else if (budd >= 60)
						return HIY "�� ��  �� ��" NOR;
					else if (budd >= 40)
						return HIY "�� ��  ʦ ��" NOR;
					else if (budd >= 30)
						return HIY "�� ��  �� ��" NOR;
					else
						return "�� ɮ  �� ��";
				case "taoist":		
					return "�� ��  ʿ ��";
				case "bandit":		
					return "�� ��  �� ��";
				case "scholar":		
					return "�� ��  �� ��";
				case "officer":		
					return "�� ��  �� ��";
				case "fighter":		
					return "�� ��  �� ��";
				case "swordsman":	
					return "�� ��  ʿ ��";
				case "alchemist":	
					return "�� ��  ʿ ��";
				case "shaman":		
					return "�� ��  ҽ ��";
				case "beggar":		
					return "�� �л��� ��";
         case "tianyumen":
            swd = ob->query_skill("tianyu-qijian",1);
        if (swd >= 200)
        return HIW "��������" NOR;
     else if (swd >= 150)
             return HIW "������ʥ��" NOR;
     else if (swd >= 100)
             return HIY "����������" NOR;
     else if (swd >= 50)
             return HIY "�����𽣿͡�" NOR;
     else return "������ͯ��"; 
				default:		
					return "�� ƽ  �� ��";
				}
		}
	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "Сʦ̫";
				else return "ʦ̫";
				break;
			case "taoist":
				if( age < 18 ) return "С�ɹ�";
				else return "�ɹ�";
				break;
			default:
				if( age < 18 ) return "С����";
				else if( age < 50 ) return "����";
				else return "����";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "Сʦ��";
				else return "��ʦ";
				break;
			case "taoist":
				if( age < 18 ) return "����";
				else return "����";
				break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "С�ϵ�";
				else if( age < 50 ) return "׳ʿ";
				else return "��ǰ��";
				break;
			default:
				if( age < 20 ) return "С�ֵ�";
				else if( age < 50 ) return "׳ʿ";
				else return "��ү��";
				break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				return "����";
				break;
			case "taoist":
				return "��Ů";
				break;
			default:
				if( age < 30 ) return "С����";
				else return "����̫��";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "��ͺ¿";
				else return "��ͺ¿";
				break;
			case "taoist":
				return "��ţ����";
				break;
			default:
				if( age < 20 ) return "С���˵�";
				if( age < 50 ) return "����";
				else return "��ƥ��";
				break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶ��";
				else return "����";
				break;
			default:
				if( age < 30 ) return "СŮ��";
				else return "���";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶɮ";
				else return "����";
				break;
			case "taoist":
				return "ƶ��";
				break;
			default:
				if( age < 50 ) return "����";
				else return "��ͷ��";
				break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶ��";
				else return "����";
				break;
			default:
				if( age < 30 ) return "������";
				else return "����";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "�������";
				else return "�Ϻ�����";
				break;
			case "taoist":
				return "��ɽ��";
				break;
			default:
				if( age < 50 ) return "��ү��";
				else return "����";
				break;
			}
	}
}
string query_close(object ob, int age, string rgender)
{
	int a1, a2;
	string gender;
	if (objectp(ob) )       {
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}
	
	if( !rgender )
		gender = ob->query("gender");					   
	else    gender = rgender;

	switch ( gender ) {
	case "Ů��" :
		if (a1 > a2)
			return "����";
		else
			return "���";
		break;
	default :
		if (a1 > a2)
			return "�ܵ�";
		else
			return "���";
	}
}

string query_self_close(object ob, int age)
{
	int a1, a2;
	string gender;
	if( objectp(ob) ) {
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}

	if( age )
		gender = ob->query("gender");
	else
		gender = this_player()->query("gender");

	switch (gender) {

	case "Ů��" :
		if (a1 > a2)
			return "�����";
		else
			return "С����";
		break;
	default :
		if (a1 > a2)
			return "������";
		else
			return "С����";
	}
}
