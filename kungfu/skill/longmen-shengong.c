// made by lks;


inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
         int lvl=(int)me->query_skill("longmen-shengong",1);
        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ����������������������̫���񹦡�\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("�����񹦽���ɱ�����У���Υ���֮�⣬"
                        +RANK_D->query_respect(me)+"���޴˹������������\n");

        if ((int)me->query_skill("force", 1) < 30)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");
         if (me->query_skill("yiqiguan-riyue",1)<120)
                  return notify_fail("��Ա����ڹ�--һ�������»�����Ĳ�����\n");

       return 1;
}

int practice_skill(object me)
{
        return notify_fail("�����񹦲���ͨ����ϰ�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"longmen-shengong/" + func;
}

