void check_shou(object me);

void init()
{
	object me;
	me = this_player();

	call_out("check",1,me);
}

void attempt_apprentice(object ob)
{
	object me;
	me = this_object();

	command("say �����ӷ����գ����գ�");

	if ((string)ob->query("gender") != "����" )
	{
		command("say ��λʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}

	if (ob->query("family/family_name") != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		command("say ʩ����Ҫ�������֣������Ȱ�ͭ�ֱ�����Ϊʦ�ĺá�");
		return;
	}

	if ( me->query("family/generation") >= ob->query("family/generation") )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	check_shou(ob);
	return;
}