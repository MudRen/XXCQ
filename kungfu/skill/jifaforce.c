// jifaforce.c �����ڹ�
// By Star

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	return notify_fail("����ʵ��ս���Ĵ��죬�������ۣ���ôѧϰ��\n");
}