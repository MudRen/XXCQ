void attempt_apprentice(object ob)
{
        object me,obb;
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
        if ( (int)ob->query("kill") <= 2000)
	{
                command("say Ѫ���ɵ��书����һ����ɱ���֣����ɱ��̫���ˣ��Ҳ������㣡");
		return;
	}
        if (ob->query("combat_exp")<80000)
	{
		command("say ѧ��Ӧ������ʵʵ���㹦�򲻹�������Ϊʦ�к����棬�������˰ɡ�");
		return;
	}
        if((int)ob->query_skill("yiqiguan-riyue",1)< 50){
                command("say ��Ա����ڹ��ķ�����Ĳ�����");
		return ;
	}
        if((int)ob->query("max_neili")< 300){
		command("say �������̫���ˡ�");
		return ;
	}
        	command("say �ðɣ��Ҿ��������ˡ�");
             if ((my_fam && my_fam["generation"]>14) || (me->query("cloth")=="/d/longmen/xuehepai/obj/cloth1")){
                command("say ���һ�����Ѫ�����պã����������ڱ��ɵĵ�λ��");
                obb=new("/d/longmen/xuehepai/obj/cloth2");
                obb->move(ob);
       ob->set("cloth","/d/longmen/xuehepai/obj/cloth2");
                 }
               command("recruit " + ob->query("id"));
		return ;
}


