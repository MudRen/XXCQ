// fmquest.c

inherit SKILL;
#include <ansi.h>;

mapping *quest = ({
        ([      "quest_num":            "1",
                "opp_name":             "������ʥ",
                "file_env":             "��������",
                "mudi_env":             "���Ŷ�·��",
                "file_name":            "/d/huayang/hyroad2",
                "mudi_name":            "/d/longmen/dexit",
        ]),
        ([      "quest_num":            "2",
                "opp_name":             "Ȩ����",
                "file_env":             "��������",
                "mudi_env":             "������·��",
                "file_name":            "/d/huayang/hyroad6",
                "mudi_name":            "/d/longmen/sexit",
        ]),
        ([      "quest_num":            "3",
                "opp_name":             "�¼�",
                "file_env":             "��������",
                "mudi_env":             "������·��",
                "file_name":            "/d/huayang/hyroad6",
                "mudi_name":            "/d/longmen/sexit",
        ]),
        ([      "quest_num":            "4",
                "opp_name":             "���ְ���",
                "file_env":             "����������",
                "mudi_env":             "���Ŷ�·��",
                "file_name":            "/d/huayang/hycs",
                "mudi_name":            "/d/longmen/dexit",
        ]),
        ([      "quest_num":            "5",
                "opp_name":             "佻�����",
                "file_env":             "����������",
                "mudi_env":             "������·��",
                "file_name":            "/d/huayang/hycs",
                "mudi_name":            "/d/longmen/sexit",
        ]),
        ([      "quest_num":            "6",
                "opp_name":             "�����",
                "file_env":             "��������",
                "mudi_env":             "����������",
                "file_name":            "/d/huayang/hyroad2",
                "mudi_name":            "/d/longmen/sqare",
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

