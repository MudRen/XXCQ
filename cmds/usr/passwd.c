// passwd.c

inherit F_CLEAN_UP;

string temp;
int help();

int main(object me, string arg)
{
	object ob;
	//��ע������Ӧ�ò��������޸�����Ķ�����
	if( environment(me)->query_regroom() )
		return notify_fail("������������ע��������ﲻ�����޸����룡\n");
	if( me != this_player(1) ) return 0;
	if(arg&&arg!="-1"&&arg!="-2")
		return help();
	if(!arg||arg=="-1")
		temp="-1";
	if(arg&&arg=="-2")
		temp="-2";
	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

	write("Ϊ�˰�ȫ���������������ԭ�������룺");
	input_to("get_old_pass", 1, ob);
	return 1;
}

void get_old_pass(string pass, object ob)
{
	string old_pass;

	write("\n");
	old_pass = (temp=="-1")?ob->query("password"):ob->query("temp_password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("�������\n");
		return;
	}
	write("�������µ����룺");
	input_to("get_new_pass", 1, ob );
}

void get_new_pass(string pass, object ob)
{
	write("\n��������һ���µ����룺");
	input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}

void confirm_new_pass(string pass, object ob, string new_pass)
{
	write("\n");
	if( crypt(pass, new_pass)!=new_pass ) {
		write("�Բ�������������벢����ͬ������ʹ��ԭ�������롣\n");
		return;
	}
	seteuid(getuid());
	if(temp=="-1")
	{
		if( !ob->set("password", new_pass) ) 
		{
			write("������ʧ�ܣ�\n");
			return;
		}
	}
	else
	{
		if( !ob->set("temp_password", new_pass) ) 
		{
			write("����������ʧ�ܣ�\n");
			return;
		}
	}	
	ob->save();
	(temp=="-1")?write("�������ɹ�!\n"):write("�����������ɹ�!\n");
}

int help()
{
	write(@HELP
ָ���ʽ : passwd -[1|2]
���ָ������޸�����������롣
������1�򲻴���ʾ�޸ĵ�ǰ����ʽ���룬������2��ʾҪ�޸����ע���û��ı������롣
ʹ�ñ��������¼ע���������»�ȡ��ʽ���룬��������һ��Ҫ���ܱ������롣
HELP
    );
    return 1;
}
 
