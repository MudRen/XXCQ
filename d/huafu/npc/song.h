int ask_rank()
{
      object me;
	mapping myfam,myparty;

	me=this_player();
	myfam=(mapping)me->query("family");
	myparty=(mapping)me->query("party");

	if ( (!myfam || myfam["family_name"]!="���ζ���" ) && ( !myparty || myparty["party_name"]!=HIG "���ζ���" NOR ))
	{
		command("say ���뱾�����޹ϸ𣬴˻��Ӻ�̸��\n");
		return 1;
	}

        if ( myfam && myfam["family_name"]=="���ζ���" )
	{
		command("say ���˱�����ϵ���ӣ�����Ҫ�ƽ�ְλ�ĸߵ͡�\n");
		return 1;
	}
	if ( myparty["tasks"]<100 )
	{
		command("say ��Ա������׻��������������㵣��Ҫְ��\n");
		return 1;
	}
        else if ( (myparty["tasks"]>100) && (myparty["tasks"]<200) && (myparty["rank"]!=HIM "��Ժ" NOR) )
	{
		command("say ��ϲ"+ RANK_D->query_respect(me) +"������ԺҪְ!\n");
		myparty["rank"]=HIM"��Ժ"NOR;
		myparty["level"]=2;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>200) && (myparty["tasks"]<500) && (myparty["rank"]!=HIC "����" NOR) )
	{
		command("say ��ϲ"+ RANK_D->query_respect(me) +"��������Ҫְ!\n");
		myparty["rank"]=HIC "����" NOR;
		myparty["level"]=3;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>500) && (myparty["tasks"]<800) && (myparty["rank"]!=RED "��ͷ" NOR) )
	{
		command("say ��ϲ"+ RANK_D->query_respect(me) +"������ͷҪְ!\n");
		myparty["rank"]=RED "��ͷ" NOR;
		myparty["level"]=4;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>800) && (myparty["tasks"]<1000) && (myparty["rank"]!=HIR "�ܽ�ͷ" NOR) )
	{
		command("say ��ϲ"+ RANK_D->query_respect(me) +"�����ܽ�ͷҪְ!\n");
		myparty["rank"]=HIR "�ܽ�ͷ" NOR;
		myparty["level"]=5;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>1000) && (myparty["tasks"]<1200) && (myparty["rank"]!=YEL "����" NOR) )
	{
		command("say ��ϲ"+ RANK_D->query_respect(me) +"��������Ҫְ!\n");
		myparty["rank"]=YEL "����" NOR;
		myparty["level"]=6;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>1200) && (myparty["tasks"]<1500) && (myparty["rank"]!=HIY "�ܻ���" NOR) )
	{
		command("say ��ϲ"+ RANK_D->query_respect(me) +"�����ܻ���Ҫְ!\n");
		myparty["rank"]=HIY "�ܻ���" NOR;
		myparty["level"]=7;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>1500) && (myparty["tasks"]<1800) && (myparty["rank"]!=HIG "����" NOR) )
	{
		command("say ��ϲ"+ RANK_D->query_respect(me) +"��������Ҫְ!\n");
		myparty["rank"]=HIG "����" NOR;
		myparty["level"]=8;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>1800) && (myparty["tasks"]<2000) && (myparty["rank"]!=CYN "����" NOR) )
	{
		command("say ��ϲ"+ RANK_D->query_respect(me) +"��������Ҫְ!\n");
		myparty["rank"]=CYN "����" NOR;
		myparty["level"]=9;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>2000) && (myparty["rank"]!=HIB "ư����" NOR) )
	{
		command("bow "+me->query("id"));
		command("say ��ϲ"+ RANK_D->query_respect(me) +"����ư����!\n");
		myparty["rank"]=HIB "ư����" NOR;
		myparty["level"]=10;
		me->set("party",myparty);
		return 1;
	}
         command("say "+ RANK_D->query_respect(me) +"���Ѿ���"+myparty["rank"]+"��!\n");
        return 1;
}

int ask_counts()
{
      object me;
	mapping myfam,myparty;
	me=this_player();
	myfam=(mapping)me->query("family");
	myparty=(mapping)me->query("party");
	if ( (!myfam || myfam["family_name"]!="���ζ���" ) && ( !myparty || myparty["party_name"]!=HIG "���ζ���" NOR ))
	{
		command("say ���뱾�����޹ϸ𣬴˻��Ӻ�̸��\n");
		return 1;
	}
        if ( myfam && myfam["family_name"]=="���ζ���")
	{
		command("say ���˱�����ϵ���ӣ�����Ҫ�ƽ�ְλ�ĸߵ͡�\n");
		return 1;
	}
	command("pat "+me->query("id"));
	command("say ���Ѿ�Ϊ��������"+chinese_number(myparty["tasks"])+"������Ҫ����Ŭ��������ͷ�ء�\n");
	return 1;
}


