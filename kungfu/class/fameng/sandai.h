void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	string title;

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	title = ob->query("title");

        if ((int)ob->query("shen") <= (-1000))
{
                if ((my_fam) && (my_fam["family_name"] != "���ζ���") )
		{
			command("hmm");
			command("say ���ζ�����������ʿ�İ�ᣬ��������аħ������㻹�������ȥ������");
			return;
		}
		else
		{
			command("say ����Ϊ���ΰ���ȴ���������壬����ħ���������ݲ����㣡");
			command("kaichu "+ob->query("id"));
			return;
		}
	}
	if ( my_fam )
	{
		if ( my_fam["family_name"] == "���ζ���" )
		{
			if ( ob_fam["generation"] == my_fam["generation"] )
			{
				command("say ������ͬ�����ӣ��д��д赹�ǿ��ԣ���ʦȴ�ǴӺ�˵��");
				return;
			}
			if ( ob_fam["generation"] > my_fam["generation"] )
			{
				message_vision("$Nһ���ĳϻ̳Ͽֵ����������ӷ���ʲô����Ҫ�͵��ӿ���������Ц��\n", me);
				return;
			}
		}
	}
	command("say �ðɣ�" + RANK_D->query_respect(ob) +"��Ȼ����Ϊʦ������Ŭ��������������Ϊ���������һ��������");
	command("recruit " + ob->query("id"));
	return;
}

