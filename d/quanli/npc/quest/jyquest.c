// qhlist1000.c

inherit SKILL;
#include <ansi.h>;

mapping *quest = ({
        ([	"quest_1":		"���Ϻ�",
		"quest_2":		10,
                "quest_3":      "laohan",
        ]),
        ([	"quest_1":		"����",
		"quest_2":		20,
                "quest_3":      "awang",
        ]),
      ([  "quest_1":      "��С��",
        "quest_2":   15,
                "quest_3":      "wang",
        ]),
        ([  "quest_1":      "�仨",
        "quest_2":      20,
                "quest_3":      "cuihua",
        ]),
        ([  "quest_1":      "����̫̫",
        "quest_2":      "30",
                "quest_3":      "laotai",
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
