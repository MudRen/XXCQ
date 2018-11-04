// mudage.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int sec, min, hrs, day, mon, age;
	string out_str;
	
	age = (int)me->query("mud_age");		
	sec = age % 60;
	age /= 60;
	min = age % 60;
	age /= 60;
	hrs = age % 24;
	age /= 24;
	day = age % 30;
	mon = age / 30;
	
	out_str = (mon? chinese_number(mon)+"��":"")
		+ (day? chinese_number(day)+"��":"")
		+ (hrs? chinese_number(hrs)+"Сʱ":"");
	
	write("���Ѿ��ڡ�Сѩ���硷��������������" + out_str + "�ˡ�\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : mudage
 
����֪���Լ���Сѩ��������ʵ�������˶�á� 
HELP
    );
    return 1;
}
