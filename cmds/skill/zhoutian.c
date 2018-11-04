// cycle.c

#include <skill.h>

inherit F_CLEAN_UP;

int exercising(object me);
int halt_exercise(object me);
int exercising2(object me);
int halt_exercise2(object me);

int main(object me, string arg)
{
	int neili_gain;
	int exercise_cost = (int)me->query("max_neili");//��ϰ���ѵ�ʱ�����أ�
	seteuid(getuid());
	if (me->is_busy() || me->query_temp("pending/zhoutian"))
		return notify_fail("��������æ���ء�\n");
	if (me->query_temp("mache")) return notify_fail("����������������\n");
	if (me->query_temp("chuan")) return notify_fail("���ڵ�������������\n");
	if (me->is_fighting() )
		return notify_fail("ս���в������ڹ������߻���ħ��\n");
	if (!stringp(me->query_skill_mapped("force")) )
		return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");
	neili_gain = 1 + (((int)me->query_skill("force") / 5)*((int)me->query("qi")/(int)me->query("max_qi")));
	//Ԥ�ȹ���һ�ºķѵ�ʱ�䣬������4�����ڣ�
	if(( exercise_cost / neili_gain) > 2*60)
		return notify_fail("�����ڻ����ڹ�������죬�����Կ�����Ϣ�������߻���ħӴ��\n");
	if ((int)me->query("jingli") * 100 / (int)me->query("max_jingli") < 70 )
		return notify_fail("�����ھ����������޷�������Ϣ��������\n");
	if (!arg)
	{
		write("����ϥ������˫Ŀ΢�ϣ�һ����Ϣ�Ե����ٻᣬ��ʼ�ش�����Ѩ����ʼ������������\n");
		me->set_temp("pending/zhoutian", 1);
		me->set_temp("exercise_cost", exercise_cost);
		message("vision",
			me->query("name")+"��ϥ���£�˫Ŀ΢�ϣ���ʼ��Ϣ������\n",
			environment(me), ({me}) );
		me->start_busy((: exercising :), (:halt_exercise:));
		return 1;
	}
	else if ( arg == "-l")
	{
		write("����ϥ������˫Ŀ΢�ϣ�һ����Ϣ������������ʼ��С����Ѩ����ʼ������������\n");
		me->set_temp("pending/zhoutian", 1);
		me->set_temp("exercise_cost", exercise_cost);
		message("vision",
		me->query("name")+"��ϥ���£�˫Ŀ΢�ϣ���ʼ��Ϣ������\n",
		environment(me), ({me}) );
		me->start_busy((: exercising2 :), (:halt_exercise2:));
		return 1;
	}
	else write("�������������ʽ��zhoutian|cycle [-l]\n");
	return 1;
}
//�������������0��ʱ����ֹæ��
//���������������2�����һ��
int exercising(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 1 + (((int)me->query_skill("force") / 5)*((int)me->query("qi")/(int)me->query("max_qi")));
	int jingli_c;
	//�жϴ�ʱ��Ϣ����
	if(( exercise_cost / neili_gain) > 2*60)
	{
		me->set_temp("pending/zhoutian",0);//��һ�䲻��ȱ�٣��������exercise_cost<1�Ͳ���������
		return notify_fail("����Ϣ���㣬����ֹͣ�������졣\n");
	}
	if ((int)me->query("max_neili")<300)
	{
		jingli_c = 30;
	}
	else
	{
		jingli_c = ((int)me->query("max_neili")/10);
	}
	if (exercise_cost < neili_gain) neili_gain = exercise_cost;
	if (exercise_cost < 1)
	{
		me->set_temp("pending/zhoutian",0);//��һ�䲻��ȱ�٣��������exercise_cost<1�Ͳ���������
		return 0;
	}
	//����ʵ��ÿ������һ���Ѿ�ʹ���˵ľ�����Ӧ���Ǽ�ʱ���ֲŶԣ���
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);
	if (exercise_cost > 0)
		return 1;
	me->set_temp("pending/zhoutian", 0);
	message_vision("$N�˹���ϣ��������˿�����վ��������\n", me);
	if ((int)me->query("max_neili") > (int)me->query_skill("force",1) * (int)me->query("con") + 1) 
	{
		write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
		me->set("neili", (int)me->query("max_neili"));
		me->add("jingli", -jingli_c);
		return 0;
	}
	else
	{
		me->add("max_neili", 1);
		me->add("jingli", -jingli_c);
		write("��һ������������ϣ�����Ϣ�������뵤�\n");
		write("������������ˣ���\n");
		return 0;
	}
}

int halt_exercise(object me)
{
	if (random(100)>50) 
	{
		message_vision("$N��ͷ�󺹣����ڽ���Ϣ����˵������һ����վ��������\n", me);
		me->add("qi", -(int)me->query("qi")/2);
		me->add("neili", -(int)me->query("neili")/2);
	}
	else
	{
		message_vision("$NͻȻ����Ѫ���������ۡ���һ��ͻ����һ����Ѫ���������˺��ص����ˡ�\n", me);
		me->add("qi", -(int)me->query("qi")/2);
		me->set("neili", 0);
		me->add("eff_qi", -(int)me->query("eff_qi")/2);
	}
	me->set_temp("pending/zhoutian", 0);
	return 1;
}

int exercising2(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 1 + (((int)me->query_skill("force") / 2)*((int)me->query("qi")/(int)me->query("max_qi")));
	int jingli_c, zht_l;
	//�жϴ�ʱ��Ϣ����
	 if(( exercise_cost / neili_gain) > 2*60)
	{
		me->set_temp("pending/zhoutian",0);//��һ�䲻��ȱ�٣��������exercise_cost<1�Ͳ���������
		return notify_fail("����Ϣ���㣬����ֹͣ�������졣\n");
	}
	if ((int)me->query("max_neili")<300)
	{
		jingli_c = 15;
	}
	else
	{
		jingli_c = ((int)me->query("max_neili")/20);
	}
	if (exercise_cost < neili_gain) neili_gain = exercise_cost;
	if (exercise_cost < 1)
		return 0;
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);
    if (exercise_cost > 0)
		return 1;
	me->set_temp("pending/zhoutian", 0);
	message_vision("$N�˹���ϣ��������˿�����վ��������\n", me);
	zht_l = (int)me->query_temp("zht_l");
	zht_l++;
	if (zht_l < 3)
	{
		me->add("jingli", -jingli_c);
		write("��һ��С����������ϣ�����Ϣ�������뵤�\n");
		me->set_temp("zht_l", zht_l);
		return 0;
	}
	else
	{
		if ((int)me->query("max_neili") > (int)me->query_skill("force",1) * (int)me->query("con") + 1)
		{
			write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
			me->set("neili", (int)me->query("max_neili"));
			me->add("jingli", -jingli_c);
			me->set_temp("zht_l", 0);
			return 0;
		}
		else 
		{
			me->add("max_neili", 1);
			me->add("jingli", -jingli_c);
			write("��һ������������ϣ�����Ϣ�������뵤�\n");
			write("������������ˣ���\n");
			me->set_temp("zht_l", 0);
			return 0;
		}
	}
}

int halt_exercise2(object me)
{
	if (random(100)>50)
	{
		message_vision("$N��ͷ�󺹣����ڽ���Ϣ����˵������һ����վ��������\n", me);
		me->add("qi", -(int)me->query("qi")/4);
		me->add("neili", -(int)me->query("neili")/4);
	}
	else 
	{
		message_vision("$NͻȻ����Ѫ���������ۡ���һ��ͻ����һ����Ѫ���������˺��ص����ˡ�\n", me);
		me->add("qi", -(int)me->query("qi")/4);
		me->set("neili", 0);
		me->add("eff_qi", -(int)me->query("eff_qi")/4);
	}
	me->set_temp("pending/zhoutian", 0);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : exercise|dazuo [<�ķѡ���������> ������� 10]

�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������

HELP
        );
        return 1;
}
