// �����г���������г�һ�������һ�������������Ե��õĺ����б�
// Write By JackyBoy@CuteRabbit Studio 1999/5/31

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object target;
    mixed  output;

    if( !arg ) target = me;
    if( arg == "here" ) target = environment(me);
    if( arg == "me" ) target = me;
    if( !target ) target = present(arg, me);
    if( !target ) target = present(arg, environment(me));
    if( !target ) target = load_object(resolve_path(me->query("cwd"), arg));
    
    if( !target ) return notify_fail("û�������Ʒ��\n");

    output = implode(({sprintf("Function list for %s",file_name(target))})+
          sort_array(
            map_array( functions( target ), (: sprintf("%-34s: %-34s",
                  (function_exists($1, $(target)) ?
                    function_exists($1, $(target)) :
                    "*PROTECTED*"), $1 ) :)), 1), "\n");
    me->start_more(output);
    return 1;
}

int help()
{
        write(@HELP
ָ���ʽ: flist [<��Ʒ����>]

�г���Ʒ�ϴ��ڵĺ���

HELP
        );
        return 1;
}
