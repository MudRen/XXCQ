#include <mudlib.h>
inherit F_CLEAN_UP;

int level(mixed, mixed);
string wiz_rank(string hood);

string gateway(string pattern)
{
        string *list, hood = "", str;
        int j;
        string  ret = "<HEAD><TITLE>"+MUD_NAME+"Ŀǰ���ߵ����</TITLE></HEAD>";
        ret += sprintf("<h3 align=center><font face='��Բ' color=#ff0000>%s"
                                "<font face='��Բ'color=#000000>��������б�</font>"
                                "</h3><hr>",CHINESE_MUD_NAME);
        j=0;
        list = sort_array(SECURITY_D->query_wizlist(), (: level :) );
        str = ret;
        str += "<blockquote><blockquote>��������������������������������������<br>";
        for(int i=0; i<sizeof(list); i++, j++) {
                if (hood!= wiz_rank(wizhood(list[i]))) {
                        hood = wiz_rank(wizhood(list[i]));
                        if (j%7) str += "<br>";
                        str += hood;
                        str = replace_string(str,"(","<font color=#ff0000>");
                        str = replace_string(str,")",": </font>");
                        j = 0;
                }

                str += sprintf(" %s%s", list[i],
                        ( j%7==6 ) ? "<br>" : ( i<sizeof(list)-1 && hood ==wizhood(list[i+1]) ) ? ", " : ""  );
        }
        str += "<br>��������������������������������������<br>";
        str += sprintf("Ŀǰһ����: %d����ʦ</blockquote></blockquote>",sizeof(list) );
        return str;
}
string wiz_rank(string hood)
{	switch(hood) {
		case "(admin)":			
			return "�� ��  �� ��";
		case "(arch)":			
			return "�� ����ʦ ��";
		case "(hufa)":			
			return "�� ��  �� ��";
		case "(wizard)":		
			return "�� ��  ʦ ��";
		case "(angel)":			
			return "�� ��  ʹ ��";
		case "(apprentice)":		
			return "�� С  �� ��";
		case "(immortal)":		
			return "�� ��  �� ��";
	}
}
int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 < ob2?-1:1;
}
