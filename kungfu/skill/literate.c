// literate.c

inherit SKILL;
#include <ansi.h>

string type() { return "knowledge"; }

void skill_improved(object me)
{	switch(me->query_skill("literate",1))
	{
		case 30:
		{
			write(HIY"���Ѿ�����ʶ�����ɵĽ׶Σ��Ѿ���һ���Ļ����ˣ�Ҳ��
�Լ�������ߵĻ����һ�㡣\n"NOR);
			break;
		}
		case 110:
		{
			write(HIC"��ϲ�㣬�⺮�������ʱ�ڲ���ȥ�ˣ�Ϊʲô������
�����Ͽ��أ�Ҳ�������״Ԫ�أ�\n"NOR);
			break;
		}
		case 200:
		{
			write(HIW"��������������ѧ�����Ѿ��ﵽ���ڻ��ͨ�Ľ׶Σ���
�˺�����Լ�����ˡ�\n"NOR);
			break;
		}
	}
}

int valid_learn(object me)
{
	return 1;
}