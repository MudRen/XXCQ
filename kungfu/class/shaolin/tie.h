void init()
{
	object me;
	me = this_player();

	call_out("check",1,me);
}

void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	me = this_player();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	command("say �����ӷ����գ����գ�");

	if( (string)ob->query("gender") != "����" )
	{
		command("say ��λʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}

	if (my_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		command("say ʩ����Ҫ�������֣������Ȱ�ͭ�ֱ�����Ϊʦ�ĺá�");
		return;
	}

	if ( ob_fam["generation"] > my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if (!me->query("bai_tie") && ob_fam["generation"] < my_fam["generation"])
	{
		command("say " + me->query("name") + "���������¹棬δ����ʦ�������Ҳ�������Ϊͽ�����ȥ�ɡ�");
		return;
	}

	command("say " + me->query("name") + "����ʦ��" + my_fam["master_name"] + "�����Ƽ����㡣");
	command("consider");
	tell_object(me,"\n");
	call_out("check_shou",1,me);
	return;
}