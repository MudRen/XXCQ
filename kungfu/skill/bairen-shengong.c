// bairen-shengong.c ���̲���һŭ��


inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
          int lvl;
          int t;
          int j;
         mapping myfam;
         myfam=(mapping)me->query("family");
               lvl=(int)me->query_skill("bairen-shengong",1);
               t=1;

          if ( (myfam) && (myfam["family_name"]!="���ζ���") )
                    return notify_fail("�Բ��𣬴����ѧ���⴫�ġ�\n");
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ����������������������̫���񹦡�\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("�����񹦽����������ϣ���Υ��������徻֮�⣬"
			+RANK_D->query_respect(me)+"���޴˹������������\n");

	if ((int)me->query_skill("force", 1) < 15)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100) 
			return notify_fail("�����������̫���ˡ�\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
			return notify_fail("�����������̫���ˡ�\n");
	}

/*
	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beimin-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
//	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
//	|| me->query_skill("jiuyang-shengong",1)
//	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");
*/

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"bairen-shengong/" + func;
}

