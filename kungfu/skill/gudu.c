// gudu.c �ƶ�֮��
// By mulan

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("poison", 1) < 100)
                return notify_fail("��Ļ���������򲻹����޷�ѧ�ƶ�֮����\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������̫�����޷�ѧϰ�ƶ�֮����\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("�ƶ�֮��ֻ�ܿ�ѧϰ����ߡ�\n");
}
