// qhlist1000.c

inherit SKILL;
#include <ansi.h>;

mapping *quest = ({
        ([	"quest_1":		"ºÚÀÏºº",
		"quest_2":		10,
                "quest_3":      "laohan",
        ]),
        ([	"quest_1":		"°¢Íú",
		"quest_2":		20,
                "quest_3":      "awang",
        ]),
        ([	"quest_1":		"´ä»¨",
		"quest_2":		15,
                "quest_3":      "cuihua",
        ]),
        ([	"quest_1":		"ÀîÀÏÌ«Ì«",
		"quest_2":		5,
                "quest_3":      "laotai",
        ]),
        ([	"quest_1":		"Ãí×£",
		"quest_2":		30,
                "quest_3":      "miaozhu",
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
