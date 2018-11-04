// set.c
 
#define MAX_ENV_VARS	20

#include <ansi.h>

inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
	int i;
	string term, *terms, *wiz_only,*allow;
	mixed data;
	string data0;
	mapping env;
 	int as_str=0;
 	//ʹ�������������ֹ���ʹ�����BUG
	wiz_only = ({"invisibility", "immortal"});
	allow = ({ "wimpy","no_prompt","prompt","msg_mout","msg_min","brief","time_format",
		"invisibility","immortal","���ǻ�����","logchat","block_tell",
		"no_teach","no_accept","msg_home"});
	if( me != this_player(1) ) return 0;
 
	env = me->query("env");
 
	if( !arg || arg=="" ) {
		write("��Ŀǰ�趨�Ļ��������У�\n");
		if( !mapp(env) || !sizeof(env) )
			write("\tû���趨�κλ���������\n");
		else {
			terms = keys(env);
			for(i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}
 
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	//��Сѩ������������ʱ�������ĵ��ַ���ʱ���������⣨����������Ϊ������ʱ����
	//By JackyBoy @ Snow 1999/11/10 ������v22pre11����v22.1b22������ˣ�
	if(sscanf(arg,"-s %s",arg)||sscanf(arg,"%s -s",arg))
		as_str=1;
	if( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
	}
	if(sscanf(term,"%*s//%*s"))
		term="���ǻ�����"; 	
	if( term && term!="" ) {
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");
		if(!wizardp(me)&&member_array(term,allow)==-1)
			return notify_fail("ϵͳ��û���Ŷ� "+HIY+term+NOR+" ���趨�أ�\n");
		data0 = data;	/* save string* data */
		sscanf(data, "%d", data);
		if((wiz_level(me) == 0) && (member_array(term, wiz_only) != -1))
			return notify_fail("ֻ����ʦ��������趨��\n");
		if(as_str || data == data0) 		/* if data is �ַ��� */
		{
			me->set("env/" + term, data0);
			printf("�趨��������(string)��%s = %s\n", term, data0+ NOR);
		}
		else
		{
			me->set("env/" + term, data);		/* is ���� */
			printf("�趨��������(data)��%s = %O%s\n", term, data,NOR);
		}
		return 1;
	}
	write("ϵͳû�п��� "+term+" ���趨��\n");
	return help();
}
 
int help()
{
	write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"������ֵ��Ϊ�ַ������ɲ��� nick �仯��ɫ.
for example : set msg_min, msg_mout, msg_home , etc.
���������ȷ�����ַ�������ʹ��-sѡ��ǿ������Ϊstring!
ȡ�������趨���� unset ָ�
 
�������Щ�������������趨����� help settings��
TEXT
	);
	return 1;
}
