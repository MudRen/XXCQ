// function:    display emote
// update by:   ken@mud.szptt.net.cn
// update time: 1998-03-13

#include "/doc/help.h"

inherit F_CLEAN_UP;
inherit EMOTE_D;

int main(object me, string arg)
{
        mapping point;
        string *emotes, msg, str;
        int i;

        if( !arg || lower_case(arg) == "all") {
                emotes = sort_array(query_all_emote(), 1);
                if( !emotes ) {
                        msg = MUD_NAME+"��ǰû���κ� emote��\n";
                        return notify_fail(msg);
                }
        }
        else {
                point = EMOTE_D->query_emote(arg);
                if( !point["updated"] ) {
                        msg = sprintf("%s��ǰû�� %s ��� emote��\n",MUD_NAME,arg);
                        return notify_fail(msg);
                }
        }

        msg = "\n";



        if( ! arg || lower_case(arg) == "all") {
                for(i=0; i<sizeof(emotes); i++) {
                        if(emote[emotes[i]]["others_target"])
                                str = emote[emotes[i]]["others_target"];
                        else {
                                if(emote[emotes[i]]["others"])
                                        str = emote[emotes[i]]["others"];
                                else str = emote[emotes[i]]["others_self"];
                                }

                        if(!str)  continue;

                        str = replace_string(str, "$n", "(�Է�)");
                        str = replace_string(str, "$N", me->name(1));
                        str = replace_string(str, "$P", "��");
                        str = replace_string(str, "$p", "(��/��)");
                        str = replace_string(str, "$S", RANK_D->query_self(me));
                        str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                        str = replace_string(str, "$R", "(�Է������)");
                        str = replace_string(str, "$r", "(�Է������)");
                        str = replace_string(str, "$C", "(�Լ����س�)");
                        str = replace_string(str, "$c", "(�Է����س�)");

                        msg += sprintf("���ƣ�%s\n���ݣ�%s\n", emotes[i],str,);
                }
                msg += sprintf("%s Ŀǰ���� %d �� emote��\n",MUD_NAME,i);
        }
        else {
                str = point["target"];
                str = replace_string(str, "$n", "��");
                str = replace_string(str, "$p", "��");
                str = replace_string(str, "$R", "(������)");
                str = replace_string(str, "$r", "(������)");


                msg += sprintf("\nemote ���ƣ�%s\n\n"
                        "�Լ�������\n%s%s%s\n\n"
                        "�Է�������\n%s\n"
                        "�����˿�����\n%s%s%s\n",
                        arg,
                        point["myself"], point["myself_self"],point["myself_target"],
                        str,
                        point["others_self"],
                        point["others"],
                        point["others_target"] );

                        msg = replace_string(msg, "$n", "(�Է�)");
                        msg = replace_string(msg, "$N", me->name(1));
                        msg = replace_string(msg, "$P", "��");
                        msg = replace_string(msg, "$p", "(��/��)");
                        msg = replace_string(msg, "$S", RANK_D->query_self(me));
                        msg = replace_string(msg, "$s", RANK_D->query_self_rude(me));
                        msg = replace_string(msg, "$R", "(�Է������)");
                        msg = replace_string(msg, "$r", "(�Է������)");
                        msg = replace_string(msg, "$C", "(�Լ����س�)");
                        msg = replace_string(msg, "$c", "(�Է����س�)");

        }
        me->start_more(msg);

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : chkemote, chkemote [emote��]��

���ָ������г�Ŀǰ����ʹ�õ� emote ���ߵ����г�
ĳ�� emote �����ݡ�

HELP
        );


return 1;
}

