void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	me = this_object();
	my_fam = ob->query("family");
	ob_fam = me->query("family");
            if (my_fam) {
	if (my_fam["family_name"] != "���ζ���")
	{
		command("say " + RANK_D->query_respect(ob) +"�����Ƿ��ζ���������������ʦ�ִӺ�˵���أ�");
		return;
	}
       }
        if ( ((int)ob->query("shen") <= (-1000)) && (my_fam) )
	{
		command("say ����Ϊ���ε���ȴ���������壬����ħ��,�Ҳ������㣡");
		command("kaichu "+ob->query("id"));
		return;
	}
        if ( (my_fam) && ( ob_fam["generation"] == my_fam["generation"] ) )
	{
		command("say ������ͬ�����ӣ��д��д赹�ǿ��ԣ���ʦȴ�ǴӺ�˵��");
		return;
	}
	if (ob->query("combat_exp")<200000)
	{
		command("say ѧ��Ӧ������ʵʵ���㹦�򲻹�������Ϊʦ�к����棬�������˰ɡ�");
		return;
	}
	if((int)ob->query_skill("bairen-shengong",1)< 100){
		command("say ��İ�����̫���ˡ�");
		return ;
	}
	if((int)ob->query_skill("cuff",1)< 100){
		command("say ���ȭ������̫���ˡ�");
		return ;
	}
	if((int)ob->query_skill("yiye-zhiqiu",1)< 100){
		command("say һҶ֪���˱��ž�����Ӧ�úú����С�");
		return ;
		}
	if((int)ob->query("max_neili")< 500){
		command("say �������̫���ˡ�");
		return ;
	}
        	command("say �ðɣ��Ҿ��������ˡ�");
        	command("say �Ժ�һ�������������¡�");
		command("recruit " + ob->query("id"));
		return ;
}


