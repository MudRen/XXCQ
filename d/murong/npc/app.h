void attempt_apprentice(object ob)
{       
	if( ob->query("gender") == "����")
	{
		command("say ���������᲻�в�Ů���ˡ�");
		return;
	}
	if( ob->query("title") == "����Ľ�ݵ���������")
	{
		command("say ���Ȼ�Ѿ����˹���Ϊʦ�α��ְݻ����أ�");
		return;
	}
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
	command("recruit " + ob->query("id"));
	ob->set("title","����Ľ�ݵ��Ĵ�����");          
	return;
}
