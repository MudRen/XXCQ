// liuxu-shenfa.c
//by mulan

inherit SKILL;

string *dodge_msg = ({
"$n�ȷ紵���������Զ���ɲ�ǣ���ˮ����������Ƶ�˲�䣬��Ҫ��!\n",
"������ɲ�ǣ�$Nֻ��ͷ������һ����һ���������������ؾ���,ԭ����$n��\n",
"$nٿȻһ����������$N��Ȼ������һ�������һ����һ����һ������һ��һ��������������������������֪ת��\n
 ���ٴΣ��ڶ̶̲���ʮ��֮�����У������ת�ŵ����켲���۽�$N��\n",
"$n���ˣ�Ҳ��������˿������$N���ɣ�$n����ҲƮ��\n",
"$n����������������$n��Ȼճ��$N�������ϡ�����������$W�ϡ�����$W��ȫ��������!\n",
"$n�����ӣ��Ƹ�����һ�㣬����������ǿ���ľ�����ȥ���������𵴵���Ʈ��ȫʧȥ��Ч�á�\n",
"$n����������Ӱ����Τ��������ۻ������������Σ�������������ѧ�����߾��磺\n
 �Ի��ϼ���������죬�Ժ���ȣ��Ծ��ƶ���\n",

});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") ; 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 100 )
                return notify_fail("�������̫���ˣ��������貨΢����\n");
        me->receive_damage("qi", 80);
        return 1;
}

