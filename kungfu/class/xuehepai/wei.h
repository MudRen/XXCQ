void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	me = this_object();
	my_fam = ob->query("family");
	ob_fam = me->query("family");
            if (my_fam) {
        if (my_fam["family_name"] != "Ѫ����")
	{
                command("say " + RANK_D->query_respect(ob) +"������Ѫ����������������ʦ�ִӺ�˵���أ�");
		return;
	}
       }
        if ( (int)ob->query("kill") <= 5000)
	{
                command("say Ѫ���ɵ��书����һ����ɱ���֣����ɱ��̫���ˣ��Ҳ������㣡");
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
        if((int)ob->query_skill("yiqiguan-riyue",1)< 100){
                command("say ��Ա����ڹ��ķ�����Ĳ�����");
		return ;
	}
	if((int)ob->query("max_neili")< 500){
		command("say �������̫���ˡ�");
		return ;
	}
        	command("say �ðɣ��Ҿ��������ˡ�");
		command("recruit " + ob->query("id"));
		return ;
}


