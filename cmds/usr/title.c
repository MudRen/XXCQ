// title.c (Mon  09-04-95)
 
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me)
{
    printf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(me), me->short(1));
    return 1;
}
 
int help()
{
    write(@HELP
ָ���ʽ: title
 
��ʾ��Ŀǰ�Ľ׼���ͷ�Ρ�
 
HELP
    );
}
 
