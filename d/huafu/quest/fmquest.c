// fmquest.c

inherit SKILL;
#include <ansi.h>;

mapping *quest = ({
/*
        ([      "quest_num":		"1",
		"opp_name":             "������ʥ",
		"quest_env":            "������ջ",
                "quest_thing":		"���ܿ���",
                "file_name":            "/d/bianliang/guangming",
        ]),
*/
        ([      "quest_num":		"2",
		"opp_name":             "���ϸ��¥",
		"quest_env":            "�����ǻش���",
                "quest_thing":		"���ܿ���",
                "file_name":            "/d/yaowang/huichun",
        ]),
/*
        ([      "quest_num":		"3",
		"opp_name":             "������ʥ",
		"quest_env":            "����ɽ��",
                "quest_thing":		"Ѱ������",
                "file_name":            "/d/shaolin/guangchang1",
        ]),
*/
        ([      "quest_num":		"4",
		"opp_name":             "Ȩ����",
		"quest_env":            "����¥",
                "quest_thing":		"������ı",
               "file_name":            "/d/bianliang/jiulou/sanhelou",
        ]),
        ([      "quest_num":		"5",
		"opp_name":             "�׳������",
                "quest_env":            "��Ӫ",
                "quest_thing":		"�ͳ�͢���ܹ���",
                "file_name":            "/d/bianliang/bingying1",
        ]),
/*
        ([      "quest_num":		"6",
		"opp_name":             "Ȩ����",
		"quest_env":            "佻���®����",
                "quest_thing":		"����",
                "file_name":            "/d/huanhua/gate",
        ]),
*/
        ([      "quest_num":		"7",
		"opp_name":             "���ְ���",
                "quest_env":            "��Ӫ",
                "quest_thing":		"�ͳ�͢������̸",
                "file_name":            "/d/bianliang/bingying2",
        ]),
        ([      "quest_num":		"8",
		"opp_name":             "���ְ���",
                "quest_env":            "����¥��¥",
                "quest_thing":		"�ͽ��ϸ��¥̸��",
               "file_name":            "/d/bianliang/jiulou/sanhelou2",
        ]),
        ([      "quest_num":		"9",
		"opp_name":             "�¼�",
		"quest_env":            "�����ǻش���",
                "quest_thing":		"�ͽ��ϸ��¥��Ǣ",
                "file_name":            "/d/yaowang/huichun",
        ]),
/*
        ([      "quest_num":		"10",
		"opp_name":             "�¼�",
		"quest_env":            "������ϷԺ",
                "quest_thing":		"��������̸",
                "file_name":            "/d/bianliang/xiyuan",
        ]),
*/
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
