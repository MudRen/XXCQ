// to.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

int main(object me, string arg)
{
	me->edit( (: call_other, this_object(), ({ "do_to", me, arg }) :) );
	return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help()
{
write(@HELP
ָ���ʽ : to <ָ��>

����һ������������ϵ�����, <ָ��>ͨ�������ѶϢ��ָ����
say��tell��describe��chat�������ȡ�
���磺 
>to say
�����뿪�� '.'��ȡ�������� '~q'��ʹ���ڽ��б༭���� '~e'��
����������������������������������������������������������

          ����
	   ����
	   ����

�����ӫĻ�ϵĽ������ :

��˵����
          ����
	   ����
	   ����


HELP
    );
    return 1;
}

