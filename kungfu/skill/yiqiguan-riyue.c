
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
          if ( ((int)me->query("kill") < 200) && (me->query_skill("yiqiguan-riyue",1)>50))
                return notify_fail("Ѫ�����书��Ҫ����һ����ɱ���֣����ɱ��̫���ˡ�\n");

        if ( (int)me->query_skill("force", 1) < 15)
                  return notify_fail("��Ļ����ڹ���򻹲������޷����һ�������¡�\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("һ��������ֻ����ѧ(learn)�������������ȡ�\n");
}

void skill_improved(object me)
{
        switch (me->query_skill("yiqiguan-riyue",1))
        {
                case 50:
                {
                        message_vision(HIY "$N�Ķ�ͷ�ƺ�����ǰ�����˲��١�����������������һ����Ρ�\n" NOR, me);
                        tell_object(me, HIY "���������ѧ����������Է���ָ�������ˣ���\n\n" NOR);
                        break;
                }
                case 100:
                {
                        message_vision(HIC "��ͻȻ����$N��̫��Ѩ���Ե�ͻ���ˡ����$N�Ĺ���������������\n" NOR, me);
                        tell_object(me, HIC "�������һ�������µĽ�һ����������Է������������������ھ��ˣ���\n\n" NOR);
                        me->set("yiqiguan-riyue",1);
                        break;
                }
                case 150:
                {
                        message_vision(HIW "$N��̫��Ѩ��ͻ���״̬�ָֻ�ԭ�����ͳ���һ��������$N�Ĺ����Ѿ���豹����ˡ�\n" NOR, me);
                        tell_object(me, HIW "�������һ�������µĸ���һ����������Է������Ƿ��켫�����ھ��ˣ���\n\n" NOR);
                        me->set("yiqiguan-riyue",2);
                        break;
                }

        }
        return;
}

string exert_function_file(string func)
{
        return __DIR__"yiqiguan-riyue/" + func;
}

