//Rewritten by JackyBoy@cctx&snow 1999/11/4
//�����˶��°�ȫϵͳ��֧�ֺ���ʦ����˵����֧��

#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int level(mixed, mixed);

mapping wiz_rank=([
	"(admin)":HIW"�� ��  �� ��"NOR,
	"(arch)":HIC"�� ����ʦ ��"NOR,
	"(hufa)":HIY"�� ��  �� ��"NOR,
	"(wizard)":CYN"�� ��  ʦ ��"NOR,
	"(angel)":YEL"�� ��  ʹ ��"NOR,
	"(apprentice)":HIG"�� С  �� ��"NOR,
	"(immortal)":HIB"�� ��  �� ��"NOR
	]);
string *mission=({});
string get_mission( string );
int main(object me)
{
	string *list, hood = "", str;
	int j = 0;
	str=read_file("/adm/etc/wizmission");
	if(str)
		mission = explode(str,"\n");
	list = sort_array(SECURITY_D->query_wizlist(), (: level :) );
	str = BLINK+HIC+CHINESE_MUD_NAME+NOR+HIW+sprintf("Ŀǰһ����: %d����ʦ\n",sizeof(list) );
	str += HIW"��"+HIC"������������������������������������������������������������������"+
		HIW"��\n"NOR;
	for(int i=0; i<sizeof(list); i++, j++)
	{
		if (hood!= wiz_rank[wizhood(list[i])])
		{
			hood = wiz_rank[wizhood(list[i])];
			if (j%3) str += "\n";
				str += hood+"\n";
			str = replace_string(str,"(",HIG);
			str = replace_string(str,")",": "NOR);
			j = 0;
		}
		str += sprintf(HIW"��%s%s", list[i]+"��"NOR+get_mission(list[i]),
			( j%3==2 ) ? "\n" : " ");
	}
	str += HIW"\n\n��"+HIC"������������������������������������������������"+HIY"Сѩ����"+
		HIC"����������"+HIW"��\n"NOR;
	me->start_more(str);
	return 1;
}

string get_mission( string wiz)
{
	int i;
	string wname,wmin;
	for(i=0; i<sizeof(mission); i++)
	{
		if( mission[i][0]=='#' || sscanf(mission[i], "%s %s",wname, wmin)!=2 )
			continue;
		if(wname==wiz) return wmin;
	}
	return "����δ��";
}

int level(mixed ob1, mixed ob2)
{
	if (wiz_level(ob1) != wiz_level(ob2))
		return wiz_level(ob2) - wiz_level(ob1);
	return ob1 < ob2?-1:1;
}

int help(object nouse)
{
	write("\nָ���ʽ : wizlist\n"
		"��; : �г�Ŀǰ���е���ʦ������\n"
	);
	return 1;
}
