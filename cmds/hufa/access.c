// ��ȫϵͳv0.1 Write By JackyBoy@CuteRabbit Studio for CCTX & SDXL
// ע�⣺
// �������������ȷ������Ȩ�޵�����²ſ�����ȷʹ�ã�һ��Ȩ�޷������ͻ����ϵͳ�޷�����
// ��ʱ��ֻ���ֶ����Ĵ洢�ļ�������û���ɾ�����ļ��ſ����ٴ�������
// ���ԣ�����ֻ�п��Ե�¼�������û��ſ���ʹ�øð�ȫϵͳ������
// ��Ȼ�������ṩ��������Ȩ�����÷��������ǽ���Ҫ��һ��ԭ����ϵͳ�İ�ȫ����
// ��д�ڣ�1999/7/14
// 7/15�޸ģ���Ȩ�������޸�Ϊ����һ�����ö����Ȩ��
#undef SECURITY_D
#define SECURITY_D "/adm/daemons/securd"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string type,acc,op,user,*tmp;
	
	if( me!=this_player(1) ) return 0;
	if( wiz_level(me)<wiz_level("hufa"))
		return notify_fail("����Ȩʹ�ø����\n");
	if(!arg||arg=="print")
		arg="print all";
	if(arg=="wizlist")
	{
		write(implode(SECURITY_D->get_wizlist(),"\n")+"\n");
		return 1;
	}
	if(sscanf(arg,"set %s %s",user,acc)!=2)
	{
		if(sscanf(arg,"print %s",type)!=1)
		{
			if(sscanf(arg,"add %s %s",type,acc)!=2)
			{
				if(sscanf(arg,"del %s %s",type,acc)!=2)
					return notify_fail("�������\n��ʽΪ��access print|wizlist|modify [����] [��ȡ����]\n");
				else
					op="del";
			}
			else
				op="add";
			//��Ҫ��acc�������file��access_user
			if(sscanf(acc,"%s %s",acc,user)!=2)
				return notify_fail("��ȡ���Ʊ����������\n");
		}
		else
			op="print";
	}
	else
	{
		//������ʦ����ע���������ϸ���ģ����Է�����������ʦ������ǧ������������
		seteuid(geteuid());
		if( !(SECURITY_D->set_status(user, acc)) )
			return notify_fail("�޸�ʧ�ܡ�\n");
		message_vision("$N��"+user+"��Ȩ�޸�Ϊ " + acc + " ��\n", me);
		return 1;
	}
	if(op=="print")
		me->start_more(SECURITY_D->print_access_list(me,type));
	else
	{
		//�ݴ���
		user=replace_string(user,"\"","");
		user=replace_string(user," ","");
		
		tmp=explode(user,",");
		(SECURITY_D->modify_access_list(me,op,type,acc,tmp))?write("�ɹ�!\n"):write("ʧ��!\n");
	}
	return 1;
}

#undef SECURITY_D
#define SECURITY_D "/adm/daemons/securityd"

int help()
{
write(@HELP

Ȩ�޹���ָ�

ָ���ʽ : 
�г�Ȩ�޷��������access print [����] 
�г���Ϸ��ʦ��  ��access wizlist
���û�������ʦ  ��access set �û�ID Ȩ�޼���
����Ȩ�޷����  ��access add ���� �ļ� ��Ȩ��
ɾ��Ȩ�޷�����access del ���� �ļ� ��Ȩ��
��������Ϊtrusted_read,trusted_write,exclude_read,exclude_write�ĸ�֮һ
��Ȩ����һ����ļ��ļ�����߾�ȷ��UID�����飬��ʽ���£�
jackyboy����(admin)����"jackyboy"����jackyboy,(admin)����"(admin)","jackyboy"
���ö��ŷָ�ÿ����Ȩ�ߣ��������ſ��Ժ��Բ��ƣ�����ֱ����Ȩ��ĳ����ʹ�ø��˵�ID
������һ����ʦ�������ƣ�����(admin)��ע�⣬���Ų����٣�

HELP
    );
    return 1;
}
