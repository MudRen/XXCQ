void init()
{
	object me;
	me = this_player();

	call_out("check",1,me);

	add_action("do_kneel", "kneel");
}

void attempt_apprentice(object ob)
{
	object me;
	me = this_object();

	if( (string)ob->query("gender") != "����" )
	{
		command("say �����ӷ���λʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}

	command("say �����ӷ����գ����գ�");

	if ( ob->query("combat_exp") > 10000 && ob->query("family/family_name") != "������")
	{
		command("say ��λʩ�����ǽ���������ʿ��С�²������ݣ�ʩ����������������з�Ҳ�����ˡ�");
		return;
	}

	if ((int)ob->query("shen") < -1000)
	{
		command("say ��λʩ����ħ��������������ƣ�����Щ������������ҷ𲻳١�");
		return;
	}

	if( (string)ob->query("class")!="bonze" )
	{
		ob->set_temp("pending/join_bonze", 1);
		command("say ʩ������������ҷ������(kneel)�ܽ䡣");
		return;
	}

	if ( me->query("family/generation") >= ob->query("family/generation") && ob->query("family/family_name") == "������")
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	command("recruit " + ob->query("id"));
}

int do_kneel()
{
	object me = this_player();

	string *prename =
	 ({ "ʯ", "��" });
	string name, new_name;

	if( !me->query_temp("pending/join_bonze") )
		return 0;

	message_vision(
		"$N˫�ֺ�ʮ�����������ع���������\n\n"
		"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n",
		me, this_object() );
	name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");
	command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
	me->set_temp("pending/apprentice", this_object());
	command("recruit " + me->query("id"));

	return 1;
}