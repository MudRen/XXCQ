void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

                if ((my_fam) && (my_fam["family_name"] != "���ζ���") )
	{
		command("say " + RANK_D->query_respect(ob) +"�����Ƿ��ε���������������ʦȥ������ϼʦ����\n");
		return;
	}
        if ( ((int)ob->query("shen") <= (-1000)) && (my_fam) )
	{
		command("say ����Ϊ���ε���ȴ���������壬����ħ��,�Ҳ���Ҫ�㣡");
		command("kaichu "+ob->query("id"));
		return;
	}
        if (my_fam) {
	if ( ob_fam["generation"] == my_fam["generation"] )
	{
		command("say ������ͬ�����ӣ��д��д赹�ǿ��ԣ���ʦȴ�ǴӺ�˵��");
		return;
	}
      }
	if (ob->query("combat_exp")<50000)
	{
		command("say ѧ��Ӧ������ʵʵ���㹦�򲻹�������Ϊʦ�к����棬�������˰ɡ�");
		return;
	}
	command("say �ðɣ�" + RANK_D->query_respect(ob) +"��Ȼ����Ϊʦ������Ŭ��������������Ϊ���������һ��������");
	command("recruit " + ob->query("id"));
	return;
}


