// dodge.c

inherit SKILL;

string *dodge_msg = ({
        "������$n���м���Զ��\n",
        "���Ǳ�$n����ض㿪�ˡ�\n",
        "����$n����һ�࣬���˿�ȥ��\n",
        "���Ǳ�$n��ʱ�ܿ���\n",
        "����$n����׼�������Ų�æ�Ķ㿪��\n",
});

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
