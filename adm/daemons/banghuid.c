// banghuid.c ���
// By ɽèadx @ CuteRabbit 23:22 99-6-9

#include <ansi.h>

string query_banghui(string banghui, int bhrank)
{
        if ( banghui == "��͢" )
        {
                switch(bhrank)
                {
                        case 1: return "��"+HIC"����һƷ"+HIW"��Ԫ˧��\n"NOR;
                        case 2: return "��"+HIC"������Ʒ"+HIW"�󽫾���\n"NOR;
                        case 3: return "��"+HIC"������Ʒ"+HIW"�Ͻ�����\n"NOR;
                        case 4: return "��"+HIC"���γ�͢��Ʒ"+HIG"������\n"NOR;
                        case 5: return "��"+HIC"���γ�͢��Ʒ"+HIG"ƫ������\n"NOR;
                        case 6: return "��"+HIC"���γ�͢��Ʒ"+HIG"�ܱ���\n"NOR;
                        case 7: return "��"+HIC"���ιٸ���Ʒ"+HIM"�ᶽ��\n"NOR;
                        case 8: return "��"+HIC"���ιٸ���Ʒ"+HIM"������\n"NOR;
                        case 9: return "��"+HIC"���ιٸ���Ʒ"+HIM"��ͷ��\n"NOR;
                }
        }
}

