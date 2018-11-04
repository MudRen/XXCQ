// verify.c
// Modified by snowman@SJ 16/03/2000

/* �������ģ�д�˸���ѯ�书��������˱Ƚ�ϲ���п�ܵ�ͼ�Σ���λ�������
   PS: ��û���Ż��� ansi ��ʾ��OS�����ɫ�Ŀ�ܻ��������У�ȥ��code��ĸ�ansi color�����ˡ�
   
	�� verify xxx.yyy �� call yyy �ļ���� int help(object me)�����԰�������
	command ��help()��д��
   �����ټӵ��������ܵģ������ù��ڻ����˷������ã��������ɡ�
   ��̫��ȭ��help()�����ο���

int help(object me)
{
	write(WHT"\n̫��ȭ��"NOR"\n");
	write(@HELP
	̫��ȭ��Ϊ��ĩԪ���䵱�����������������ϵ���֮˵��������Ȼ��������
	��죬�Ծ��ƶ����ᷢ���ˣ���Ϊ����֮����ϳ���ѧ��ȭ��ʱ˫��Բת��
	ÿһ�ж�����̫��ʽ�������仯����΢���ʵ�ǿ�������ѧ�д���δ�е�
	����ء�����Ϊ�����鶥�������ذα����������Ρ�����׹�⡹ʮ�����֣�
	�������У���������������һ������·ȭ����Ҫּ��
	̫��ȭ����Ҫ�����ɷ��ɣ���չδչ�������ⲻ�ϣ����������Ϊ����һ����
	
	Ҫ��	�������ȼ� 100 ���ϣ�
		���� 500 ���ϣ�      
		���������״�ȭ�С�
HELP
	);
	return 1;
}

*/

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "����һ��" NOR,BLU "��������" NOR,BLU "����ҳ�" NOR,BLU "��ѧէ��" NOR,BLU "����ǿǿ" NOR,
        HIB "�����ž�" NOR,HIB "����é®" NOR,HIB "��֪һ��" NOR,HIB "����ͨͨ" NOR,HIB "ƽƽ����" NOR,
        CYN "ƽ������" NOR,CYN "��ͨƤë" NOR,CYN "��������" NOR,CYN "������" NOR,CYN "����С��" NOR,
        HIC "����С��" NOR,HIC "������Ⱥ" NOR,HIC "�������" NOR,HIC "�������" NOR,HIC "�ڻ��ͨ" NOR,
        GRN "�������" NOR,GRN "¯����" NOR,GRN "��Ȼ����" NOR,GRN "���д��" NOR,GRN "���д��" NOR,
        YEL "��Ȼ��ͨ" NOR,YEL "�������" NOR,YEL "�޿�ƥ��" NOR,YEL "����Ⱥ��" NOR,YEL "����似" NOR,
        HIY "�����뻯" NOR,HIY "��ͬ����" NOR,HIY "����Ⱥ��" NOR,HIY "�Ƿ��켫" NOR,HIY "�����ױ�" NOR,
        RED "��������" NOR,RED "һ����ʦ" NOR,RED "�������" NOR,RED "�񹦸���" NOR,RED "������˫" NOR,
        WHT "��������" NOR,WHT "���춯��" NOR,WHT "������" NOR,WHT "������ʥ" NOR,WHT "�������" NOR,
        HIW "��ǰ����" NOR,HIW "���˺�һ" NOR,MAG "��ز�¶" NOR,HIM "��ɲ�" NOR,HIR "��豹���" NOR
});

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,BLU "�����ž�" NOR,HIB "��֪һ��" NOR,HIB "��������" NOR,
	CYN "������" NOR,CYN "����С��" NOR,HIC "�ڻ��ͨ" NOR,HIC "�������" NOR,
	GRN "��Ȼ���" NOR,GRN "���д��" NOR,YEL "��ͬ����" NOR,YEL "������˫" NOR,
	HIY "������" NOR,RED "�����ױ�" NOR,WHT "������ʥ" NOR,HIW "��ǰ����" NOR,
});


mapping valid_type = ([
"unarmed":      "ȭ��",
"claw":         "צ��","cuff":         "ȭ��",
"finger":       "ָ��","strike":       "�ƹ�",
"hand":         "�ֹ�","leg":          "�ȹ�",
"sword":        "����","blade":        "����",	
"dagger":       "ذ��","brush":        "�ʷ�",		
"spear":        "ǹ��","hook":         "����",		
"stick":        "����","staff":        "�ȷ�",		
"club" :        "����","throwing":     "����",		
"whip":         "�޷�","axe":          "����",
"hammer":       "����","force":        "�ڹ�",	
"dodge":        "�Ṧ","parry":        "�м�",	
]);

string skill_level(string, int);
string skill_enables(object sk);

int sort_skill(string file)
{
	int i;
	if ( !sscanf(file, "%*s.c") )  return 0;
	i = strlen(file);
	while(i--){
		if( file[i] == '.' ) continue;
		if( file[i] < 'a' || file[i] > 'z' )
			return 0;
	}

	return 1;
}

int main(object me, string arg)
{
        mapping lrn;
        string exert, str, *file;
        object sk;
        int i, j = 0;

        seteuid(getuid());

        if(!arg) return notify_fail("ָ���ʽ : verify [�书����].[?|���⼼��]\n");
	
	sscanf(arg, "%s.%s", arg, str);
		
	if(!me->query_skill(arg, 1)) 
		return notify_fail("��Ҫ���ʲô���ܣ�\n");
	
	if(file_size(SKILL_D(arg)+".c") < 1)
		return notify_fail("������Ҫ��Լ����ļ��Ѿ���ʧ����֪ͨ��ʦ��\n");
	
	if( stringp(str) ){
		// ��ʽ verify xxx.? �ǲ�ѯ��skill�İ�����
		// verify xxx.yyy �ǲ�ѯ yyy �İ�����
		if( str == "?" ){
			notify_fail("�Բ��𣬡�"+to_chinese(arg)+"��Ŀǰ��û����ϸ�İ���˵����\n");
			return SKILL_D(arg)->help(me);
		}
		else if( stringp(exert = SKILL_D(arg)->exert_function_file("")) && file_size(exert + str +".c") > 0){
			notify_fail("�Բ���"+to_chinese(arg)+"�ڹ�����ġ�"+str+"������û����ϸ��˵����\n");
			return (exert + str)->help(me);
		}
		else if( stringp(exert = SKILL_D(arg)->perform_action_file("")) && file_size(exert + str +".c") > 0){
			notify_fail("�Բ���"+to_chinese(arg)+"�⹦����ġ�"+str+"������û����ϸ��˵����\n");
			return (exert + str)->help(me);
		}
		return notify_fail("�Բ���"+to_chinese(arg)+"û�С�"+str+"������ܡ�\n");
	}
	
	lrn = me->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
	str = sprintf("\n��%-24s��������������������������������������������\n", HIW"��"+to_chinese(arg)+"���ܱ�"NOR);
	
	str = replace_string(str, "  ", "��");
	str += sprintf("��"HIY"�ȼ�"NOR"��  %s %3d/%6d\t      "HIY"���"NOR"��  %-15s%9s  \n",skill_level(SKILL_D(arg)->type(), 
			me->query_skill(arg, 1)), me->query_skill(arg, 1), 
			(int)lrn[arg], SKILL_D(arg)->type(), "��");	
	
	if(SKILL_D(arg)->type() != "martial"
	|| member_array(arg, keys(valid_type))!=-1) 
		return notify_fail(str+"����������������������������������������������������������������������\n");
		
	str += "��\t\t\t\t\t\t\t\t    ��\n";
	sk = load_object(SKILL_D(arg));
	
	exert = skill_enables(sk);
	if(exert != ""){
		str += exert;
		i++;
	}
	
	if( stringp(exert = SKILL_D(arg)->exert_function_file("")) ){
		file = get_dir(exert);
		if( sizeof(file) > 0){
			file  = filter_array(file, (: sort_skill :) );
			j = sizeof(file);
		}
	}
	
	if(j && j > 0){
		if( i )
			str = str + "����������������������������������������������������������������������\n";
		str += "��"HIY"�ڹ�����(exert + )"NOR"��\t\t\t\t\t\t    ";
		for(i=0; i < j; i++){
			if (i % 4 == 0) str += "��\n��\t";
			str += sprintf("%-14s ",YEL+replace_string(file[i], ".c", "")+NOR);
			if ( i > j-2 ){
				switch(i%4){
					case 0: str +="\t\t\t\t\t            "; break;
					case 1: str +="\t\t\t            "; break;
					case 2: str +="\t\t    "; break;
					default: break;
				}
                        }
		}
		str += "��\n";
		j = 0;
	}
	
	if( stringp(exert = SKILL_D(arg)->perform_action_file(""))){
		file = get_dir(exert);
		if( sizeof(file) > 0){
			file  = filter_array(file, (: sort_skill :) );
			j = sizeof(file);
		}
	}
	
	if(j && j > 0){
		if( i )
			str = str + "����������������������������������������������������������������������\n";
		str += "��"HIY"�⹦����(perform + )"NOR"��\t\t\t\t\t    ";
		for(i=0; i < j; i++){
			if (i % 4 == 0) str += "��\n��\t";
			str += sprintf("%-14s ",WHT+replace_string(file[i], ".c", "")+NOR);
			if ( i > j-2 ){
				switch(i%4){
					case 0: str +="\t\t\t\t\t            "; break;
					case 1: str +="\t\t\t            "; break;
					case 2: str +="\t\t    "; break;
					default: break;
				}
                        }
		}
		str += "��\n";
	}
	str += "����������������������������������������������������������������������\n";
        write(str);
        return 1;
}

string skill_enables(object sk)
{
	int i, j;
	string str, *skills;
	skills = keys(valid_type);
	
	for(i=0; i < sizeof(skills); i++) {
		if (sk->valid_enable(skills[i])) continue;
		skills[i] = 0;
	}
	
	skills -= ({ 0 });
	j = sizeof(skills);
	if( !j || j < 1)
		return "";
	str = "��"HIY"���⼼��"NOR"��\t\t\t\t\t\t\t    ";
		
	for(i=0; i < j; i++) {
		if (i % 4 == 0) str += "��\n��\t";
		str += sprintf("%-14s ", HIC+valid_type[skills[i]]+"("+skills[i]+")"NOR);
		if ( i > j-2 ){
			switch(i%4){
				case 0: str +="\t\t\t\t\t            "; break;
				case 1: str +="\t\t\t            "; break;
				case 2: str +="\t\t    "; break;
				default: break;
			}
                }
	}
	str += "��\n";
	return str;
}

string skill_level(string type, int level)
{
        int grade;
        
        switch(type) {
                case "knowledge":
                	grade = level / 20;
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                	grade = level / 8;
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
	write("\nָ���ʽ : verify [�书����].[�������� | ?]\n");
	write(@HELP
���ָ����������ѯ����ܵĹ��ܺ����ݡ�

���⼼�ܱ�ʾ���� enable �ļ��ܣ��磺
	(�Ṧ���мܡ��������ȷ�) ��ʾ�����书���������Ṧ���мܣ��������ȷ��ȡ�

�ڹ�������ʾ������(exert)���ڹ���

�⹦������ʾ��ʹ��(perform)���⹦�����еȡ�

����ڹ����⹦�ľ����а������ܣ����� verify skill.pfm ����ʽ���鿴��
�磺 	verify taiji-quan.dongjing  �鿴������
	verify yinyun-ziqi.yinyun   �鿴���ھ�
	verify taiji-quan.?	    �鿴̫��ȭ


Snowman@SJ 06/04/1999
Copyright 1997-2000 ShuJian MUD Wizard Group.
All rights reserved.
	
Visit our Homepage at - www.mymud.com 
	
HELP);

    return 1;
}
