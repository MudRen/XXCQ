// write by jackyboy@cctx 1999/2/8

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	string* channels=({"all","cctx","rumor","chat","es","party","new","wiz","arch","gwiz","gbwiz"});

	if (!arg)
		return notify_fail("�﷨: unchblk <���id> <Ƶ����>\n");
	if (sscanf(arg, "%s %s", who, ch_name) != 2)
		return  notify_fail("�﷨: chblk <���id> <Ƶ����>\n");
	ob = LOGIN_D->find_body(who);
	if (!ob) return notify_fail("����˲��ڣ�\n");
	if (wizardp(ob)) return notify_fail("���ܶ���ʦ����Ƶ��������\n");
	if(member_array(ch_name,channels)!=-1)
	{
		if(ch_name!="all")
		{
			ob->set("chblk_channel/"+ch_name,time());
			tell_object(me,ob->query("name")+"��"+ch_name+"Ƶ�������ˡ�\n");
		}
		else
		{
			ob->delete("chblk_channel");
			tell_object(me,ob->query("name")+"������Ƶ���������ˡ�\n");
		}
	}
	else
		return notify_fail("û�����Ƶ����\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : unchblk <ĳ��> <Ƶ����>

�������ĳ�˵�Ƶ�������û��Ƶ�����ʹ����кϷ�Ƶ����
<ĳ��>��Ҳ������Ƶ������
<Ƶ����> ������rumor��chat��es�ȣ��� all ��ȫ����

HELP
    );
    return 1;
}
