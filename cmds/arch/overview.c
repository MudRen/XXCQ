// overview.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *ob;
        int i, m;

        switch(arg) {
                case "user":
                        ob = users();
                        printf("���� %d ��ʹ���������\n", sizeof(ob));
                        break;
                case "living":
                        ob = livings();
                        printf("���� %d ������(��ʹ����)�����\n", sizeof(ob));
                        break;
                case "char":
                        ob = objects( (: $1->is_character() && !clonep($1) :) );
                        printf("���� %d ��������� master copy �����롡\n", sizeof(ob));
                        break;
                case "npc":
                        ob = filter_array( livings(),
                                (: $1->is_character() && !userp($1) && clonep($1) :) );
                        printf("���� %d �� NPC �����\n", sizeof(ob));
                        break;
                case "combat":
                        ob = objects( (: $1->is_fighting() :) );
                        printf("���� %d ����������ս��״̬��\n", sizeof(ob));
                        break;
                case "kill":
                        ob = objects( (: $1->is_killing() && $1->is_fighting() :) );
                        printf("���� %d ���������������ಫ��ս��״̬��\n", sizeof(ob));
                        break;
                case "hunt":
                        ob = objects( (: $1->is_killing() :) );
                        printf("���� %d �����������������ﻥ���ޡ�\n", sizeof(ob));
                        break;
                case "heart beat":
                        ob = objects( (: query_heart_beat :) );
                        printf("���� %d ������� heart beat Ϊ��Ч״̬��\n", sizeof(ob));
                        break;
                case "virtual":
                        ob = objects( (: virtualp :) );
                        printf("���� %d �����������\n", sizeof(ob));
                        break;
                case "room":
                        ob = objects( (: function_exists("create_door", $1) :) );
                        printf("���� %d �����䡡\n", sizeof(ob));
                        break;
                case "special room":
                        // inherits won't work if master copy got cleaned up.
                        if( !find_object(ROOM) ) ROOM->foo();
                        ob = objects( (: inherits(ROOM, $1) :) );
                        printf("���� %d ������̳б�׼���䡡\n", sizeof(ob));
                        break;
                case "equip":
                        // inherits won't work if master copy got cleaned up.
                        if( !find_object(F_EQUIP) ) F_EQUIP->foo();
                        ob = objects( (: inherits(F_EQUIP, $1) :) );
                        printf("���� %d ������̳б�׼װ����\n", sizeof(ob));
                        break;
                case "object":
                        ob = objects();
                        printf("���� %d ����������롡\n", sizeof(ob));
                        break;
                default:
                        return notify_fail("ָ���ʽ��overview <topic>\n");
        }
        m = 0;
        i = sizeof(ob);
        while(i--)
                m += memory_info(ob[i]);
        printf("�ܹ�ʹ�� %d bytes �����塡\n", m);
        if( sizeof(ob) )
                printf("ƽ��ÿ�����ʹ�� %d bytes �����塡\n", m / sizeof(ob));
        return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��overview <����>

user:           userp()
living:         living()
room:           function_exists("create_door", ob);
TEXT
        );
        return 1;
}



