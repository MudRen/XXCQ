// chfn.c

inherit F_CLEAN_UP;
//��Ӧ������ҳ��ַ��ICQ�ȣ�
void create() { seteuid(getuid()); }

int main(object me)
{
	object link;
	if( environment(me)->query_regroom() )
		return notify_fail("������������ע��������ﲻ�����޸ĸ������ϣ�\n");
	if( objectp(link = me->query_temp("link_ob")) ) 
	{
		write("\nΪ��ȷ���㲻�ᶪʧ������룬�������ʵ����������Ϣ��\n"+
			"���ĳ�������[������1976��6��5��] ��");
		input_to("get_birthday", link);
		return 1;
    }
    return 0;
}
void get_birthday(string bir,object link)
{
	object body;
	int year,month,day;
	if(sscanf(bir,"%d��%d��%d��",year,month,day)!=3)
	{
		if(!objectp(body=link->query_temp("body_ob")))
			return;//����������
		write("\n����ĸ�ʽ��\n��������[������1976��6��5��] ��");
		input_to("get_birthday", link );
		return;
	}
	link->set("chfn/year",year);
	link->set("chfn/month",month);
	link->set("chfn/day",day);
	//��ʾ������Ϣ
	if(!objectp(body=link->query_temp("body_ob")))
		return;//���������ߣ�
	//��ʾ��һ������ʾ��Ϣ��
	write("\n���������������ʾ���⣺\n");
	input_to("get_question", link );
}

void get_question(string ques,object link)
{
	object body;
	if(ques!="")
		link->set("chfn/question",ques);
	else
	{
		if(!objectp(body=link->query_temp("body_ob")))
			return;//����������
		write("\n���������������ʾ���⣺\n");
		input_to("get_question", link );
		return;
	}
	if(!objectp(body=link->query_temp("body_ob")))
		return;//����������
	write("\n���������������ʾ����Ĵ𰸣�\n");
	input_to("get_answer", link );
	return;
}

void get_answer(string ans,object link)
{
	object body;
	if(ans!="")
		link->set("chfn/answer",ans);
	else
	{
		if(!objectp(body=link->query_temp("body_ob")))
			return;//����������
		write("\n���������������ʾ����Ĵ𰸣�\n");
		input_to("get_question", link );
		return;
	}
	if(!objectp(body=link->query_temp("body_ob")))
		return;//����������
	write("\n��� Email ��ַ [" + link->query("email") + "]: ");
	input_to("get_email",link);
	return;
}

void get_email(string new_email,object link)
{
	object body;
	if( new_email != "" )
		link->set("email", new_email);
	write("�������ҽ���: (fingerʱ��ʾ)\n");
	if(!objectp(body=link->query_temp("body_ob")))
		return;//���������ߣ�
	body->edit((: call_other, __FILE__, "get_profile", link :));
}

void get_profile(object link, string str)
{
	object body;
	link->set("profile", str);
	write("����ǩ����ʽ: (postʱ��)\n");
	if(!objectp(body=link->query_temp("body_ob")))
		return;//���������ߣ�
	body->edit((: call_other, __FILE__, "get_signature", link :));
}

void get_signature(object link, string str)
{
	mapping tmp;
	if( strlen(str) > 400 )
		write("ǩ����ʽ̫�����������趨��\n");
	else
		link->set("signature", str);
	link->save();
	//����Ӧ����ʾһ��ȫ��������
	tmp=link->query("chfn");
	write("��ĸ����������£�\n"+
	"�������ڣ�"+tmp["year"]+"��"+tmp["month"]+"��"+tmp["day"]+"��\n"+
	"�����ʼ���ַ��"+link->query("email")+"\n"+
	"������ʾ���⣺"+tmp["question"]+"\n"+
	"������ʾ����𰸣�"+tmp["answer"]+"\n"+
	"���˽��ܣ�"+link->query("profile")+"\n"+
	"ǩ������"+link->query("signature")+"\n");
}

int help()
{
write(@HELP
ָ���ʽ : chfn

��; : �����޸� email address , �༭���ҽ���(finger ʱ����)
       ��ǩ��(post ʱ��)��
HELP
     );
     return 1;
}
