// checkmoney.c
// by hello, 1996.12.04

#include <net/dns.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me)
{
    
    object *list,g_ob,s_ob,c_ob, * inv;
    string str;
    int tc,gc,sc,cc,j;

    str = "�� " + MUD_NAME + " ��ǰ������Ͻ�Ǯͳ��\n\n";
    str += "�ʺ�            ����        ��Ʊ  ����  ����  ͭ��  ���(����) \n";
    str += "��������������������������������������������������������������\n";
    list = users();
    j=sizeof(list);
    while( j-- ) {
        if( !environment(list[j]) || !me->visible(list[j])) continue;
        inv = all_inventory(list[j]);  
        if (g_ob = present("cash", list[j]))
            tc = g_ob->query_amount();
        else
            tc = 0;
        if (g_ob = present("gold", list[j]))
            gc = g_ob->query_amount();
        else
            gc = 0;
        if (s_ob = present("silver", list[j]))
            sc = s_ob->query_amount();
        else
            sc = 0;
        if (c_ob = present("coin", list[j]))
            cc = c_ob->query_amount();
        else
            cc = 0;    
            
        str = sprintf("%s%-15s %-10s%3d�� %3d�� %3d�� %3d��   %6s\n",
                str,
                list[j]->query("id"),list[j]->name(1),tc, gc,sc,cc,
                MONEY_D->money_str(((int)list[j]->query("balance")/10000)*10000)
            );
    }
        
    str += "����������������������������������������������������������������\n";
    str = sprintf("%s���� %d λʹ���������У�ϵͳ������%s\n", str, sizeof(list),
        query_load_average() + "\n");

    write(str);
    return 1;

}

int sort_user(object ob1, object ob2)
{
    if( wizardp(ob1) && !wizardp(ob2) ) return -1;
    
    if( wizardp(ob2) && !wizardp(ob1) ) return 1;

    if( wizardp(ob1) && wizardp(ob2) )
        return (int)SECURITY_D->get_wiz_level(ob2) 
            - (int)SECURITY_D->get_wiz_level(ob1);
    
    return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help()
{
write(@HELP
ָ���ʽ : checkmoney

���ָ������г����������ϵ���ҵĽ�Ǯ�Լ�������Ʒ��������

���ָ� finger, who
HELP
    );
    return 1;
}

