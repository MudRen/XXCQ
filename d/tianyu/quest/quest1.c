// Obj quest1.c

inherit SKILL;
#include <ansi.h>;

mapping *quest = ({
        ([      "name":                 "ͭ��",
		"party":		"������",
                "where_place":          "/d/shaolin/guangchang1",
        ]),
        ([      "name":                 "ͭ��",
		"party":		"������",
                "where_place":          "/d/shaolin/guangchang1",
        ]),
        ([      "name":                 "ͭ��",
		"party":		"������",
                "where_place":          "/d/shaolin/shanmen",
        ]),
        ([      "name":                 "��ʯ",
		"party":		"������",
                "where_place":          "/d/shaolin/guangchang2",
        ]),
        ([      "name":                 "����",
		"party":		"������",
                "where_place":          "/d/shaolin/guangchang2",
        ]),
        
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
