// qhlist1000.c

inherit SKILL;
#include <ansi.h>;

mapping *quest = ({
        ([	"quest_1":		"�����ӻ���",
		"quest_2":		"ǰ���춨�Ķ���",
                "quest_3":		"����",
                "quest_4":		"���ƹ�",
        ]),
        ([	"quest_1":		"�����Ǻ���Ⱦ��",
		"quest_2":		"ǰ������Ⱦ�Ĳ�",
                "quest_3":		"����",
                "quest_4":		"Ƚ��Ȼ",
        ]),
        ([	"quest_1":		"�����ǵ���",
		"quest_2":		"�������Ѻ�Ķ���",
                "quest_3":		"��Ѻ��",
                "quest_4":		"���Ǹ�",
        ]),
        ([	"quest_1":		"�����ǻش���",
		"quest_2":		"ǰ���춨��ҩ��",
                "quest_3":		"����",
                "quest_4":		"��̫ʦ",
        ]),
        ([	"quest_1":		"�������ӻ���",
		"quest_2":		"ǰ���춨�Ķ���",
                "quest_3":		"����",
                "quest_4":		"ΤѼë",
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
