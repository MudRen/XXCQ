// abandon.c
// write by jackyboy for CCTX

inherit F_CLEAN_UP;
mapping valid_types = ([
	"unarmed":	"ȭ��",
	"sword":	"����",
	"blade":	"����",
	"stick":	"����",
	"staff":	"�ȷ�",
	"club" :        "����",
	"throwing":	"����",
	"force":	"�ڹ�",
	"parry":	"�м�",
	"dodge":	"�Ṧ",
	"magic":	"����",
	"whip":     "�޷�",
	"lingfa":  "�",

//	shaolin skills
	"finger":   "ָ��",
	"hand":     "�ַ�",
	"cuff":     "ȭ��",
	"claw":     "צ��",
	"strike":   "�Ʒ�",
]);
int main(object me, string arg)
{
	mapping smap;
	string *skill;
	int level,old,i;
	if( !arg || arg=="" ) 
		return notify_fail("��Ҫ������һ��ܣ�\n");
	if( sscanf(arg,"%s %d",arg,level)==2)
	{
		if(level<0)
		{
			log_file("cmds/fangqi",me->name(1)+me->query("id")+"�Ƿ�����"+level+
				"��"+arg+"��\n");
			return notify_fail("����BUGҪ���棬��Ҳ��֪��������Ȼ������ֻ��һ��·���˼�������\n");
		}
		if((old=me->query_skill(arg,1))>level)
		{
			me->set_skill(arg,old-level);
			write("�������"+level+"��"+to_chinese(arg)+"��\n");
			return 1;
		}
	}
	//����ȥ��map_skill����Ȼս����ʱ����Ҫ����
	//�����Ƿ�Ҫȥ��skill_pre�Ͳ�������Ժ����skill�������⣬�ɿ����������
	smap = me->query_skill_map();
	if( !(!mapp(smap) || sizeof(smap)==0 ))
	{
		skill = keys(valid_types);
		for (i=0; i<sizeof(skill); i++) 
		{
			if( undefinedp(valid_types[skill[i]]) ) 
			{
				map_delete(smap, skill[i]);
				continue;
			}
			if( !me->query_skill(skill[i]) ) continue;
			if(smap[skill[i]]==arg)
			{
				write("ȥ��������"+skill[i]+" => "+smap[skill[i]]+"��\n");
				me->map_skill(skill[i]);
			}
		}
	}
	if( !me->delete_skill(arg) )
		return notify_fail("�㲢û��ѧ������ܡ�\n");
	write("�������������ѧϰ" + to_chinese(arg) + "��\n");
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��abandon|fangqi <��������>

����һ������ѧ���ļ��ܣ����Խ�����ܴ��������������ɾ��������ѡ��
��Ҫ�����ļ�������

���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�����ÿ��
�����Ų�ͬ���츳������ϰ���书Ҳ������ͬ�����������ѧ����ͷ��ֻ����
��������
TEXT
	);
	return 1;
}
