// literate.c

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
	if(me->query("shen")<0) {
		tell_object(me,HIR"����ĵ�ð��һ�ɶ����������������Ҫ�����������е��ˣ�\n"NOR);
		me->add("shen", -(me->query_skill("healing",1)));
	} else {
       tell_object(me,HIM"����ĵ�����һ�����ѧ��ѧ��ѧ����Ҫѧ���β����ˣ�\n"NOR);
		me->add("shen", (me->query_skill("healing",1)));
	}
}

int valid_learn(object me)
{ return 1; }
