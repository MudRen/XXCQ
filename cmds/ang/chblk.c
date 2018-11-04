// channel block command..
// Write by JackyBoy@cctx 1999/2/8
// ������������/adm/daemons/channeld.cҲ����CHANNEL_D����д��
#include <globals.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name,str;
	string* channels=({"all","cctx","rumor","chat","es","party","new","wiz","arch","gwiz","gbwiz"});

	if (!arg)
		return notify_fail("�﷨: chblk <���id> <Ƶ����>\n");
	if (sscanf(arg, "%s %s", who, ch_name) != 2)
	{
		ch_name = "";
		if (sscanf(arg, "%s", who) != 1)
			return  notify_fail("�﷨: chblk <���id> <Ƶ����>\n");
	}
	ob = LOGIN_D->find_body(who);
	if (!ob) return notify_fail("����˲��ڣ�\n");
	if (wizardp(ob)) return notify_fail("���ܹر���ʦ��Ƶ����\n");
	if (ch_name == "" || ch_name == " ") 
	{
		str=ob->query("name")+"("+ob->query("id")+")��Ƶ���ر�������£�\n";
		if ( (time() - (int)ob->query("chblk_channel/all")) < 3600)
			str+=(string)ob->query("name")+"������Ƶ�������ر��ˡ�\n";
		if ( time() - (int)ob->query("chblk_channel/rumor") < 3600)
			str+=(string)ob->query("name")+"��ҥ��Ƶ�����ر��ˡ�\n";
		if ( time() - (int)ob->query("chblk_channel/chat") < 3600)
			str+=(string)ob->query("name")+"������Ƶ�����ر��ˡ�\n";
		if ( time() - (int)ob->query("chblk_channel/new") < 3600)
			str+=(string)ob->query("name")+"������Ƶ�����ر��ˡ�\n";
		if ( time() - (int)ob->query("chblk_channel/party") < 3600)
			str+=(string)ob->query("name")+"������Ƶ�����ر��ˡ�\n";
		if ( time() - (int)ob->query("chblk_channel/es") < 3600)
			str+=(string)ob->query("name")+"������Ƶ�����ر��ˡ�\n";
		if ( time() - (int)ob->query("chblk_channel/cctx") < 3600)
			str+=(string)ob->query("name")+"��Сѩ����Ƶ�����ر��ˡ�\n";
		if(str==(ob->query("name")+"("+ob->query("id")+")��Ƶ���ر�������£�\n"))
			str+=ob->query("name")+"û�б��رյ�Ƶ����\n";
		tell_object(me,str);
	}
	else
	if(member_array(ch_name,channels)!=-1)
	{
		ob->set("chblk_channel/"+ch_name,time());
		if(ch_name!="all")
			tell_object(me,ob->query("name")+"��"+ch_name+"Ƶ�����ر��ˡ�\n");
		else
			tell_object(me,ob->query("name")+"������Ƶ�������ر��ˡ�\n");

	}
	else
		return notify_fail("û�����Ƶ����\n");
	return 1;
}

int help()
{
write(@HELP
ָ���ʽ : chblk <ĳ��> <Ƶ����>

������ر�ĳ�˵�ĳ��Ƶ����
<Ƶ����>��������rumor��chat�Ȼ�all�������Ƶ����
������ṩƵ����������ʾĳ�˵�ǰ��Ƶ��״̬�� 

HELP
    );
    return 1;
}
