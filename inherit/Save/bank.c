#define MAX 100000000
#define CMAX "�����ƽ�"
//��������Ҫ�����仯�ˣ���balance�޸�Ϊmapping
//balance["part1"]��¼�ж��ٴ�������ֲ��ᳬ��һ�����ƽ𣬼�100000000 CMAX�������ֵ
//balance["part2"]��¼�ж��ٸ�һ�����ƽ�

inherit BID_ROOM;

//���º�����δ���Ǵ��������������������Ҫ��һ��Ҫ��ȷ���ƿ��ܴ���Ĳ���
mapping query_max_balance(object me)
{
	mapping tmp;
	//����me�ĸ������Կ������Ŀɴ���Ŀ����������ʱ�䣬�����ȣ�
	//��ʱ��ʱ����һ�������ֵ
	tmp=([]);
	tmp["part1"]=MAX;
	tmp["part2"]=0;
	
	if(tmp["part1"]>MAX||tmp["part1"]<0)
		tmp["part1"]=MAX;
	return tmp;
}

string write_balance(mapping tmp)
{
	if(!tmp)
		return "�����ƽ�";
	if(tmp["part2"]==0&&tmp["part1"]==0)
		return "�����ƽ�";
	if(tmp["part2"]!=0)
		return " "+chinese_number(tmp["part2"])+" "+CMAX+" �� "+MONEY_D->money_str(tmp["part1"])+"\n";
	else
		return MONEY_D->money_str(tmp["part1"]);
}

int max_balance(mapping tmp1,mapping tmp2)
{
	if(!tmp1)
		return 0;
	if(!tmp2)
		return 1;
	if(tmp1["part2"]>=tmp2["part2"])//�������Ŀ��ͬ�����������ж�
	{
		if(tmp1["part1"]>tmp2["part1"])
			return 1;//���1��2�󷵻�1
	}
	return 0;//���2��1�󷵻�0
}

//����������tmp���޸��ܱ��֣����û���⣡��INT�����ǿ϶������ֵģ�����mapping��array��������
mixed add_balance(mapping tmp,int value)
{
	if(!tmp)
		tmp=([]);
	tmp["part1"]+=value;
	if(tmp["part2"]>0)
	{
		if(tmp["part1"]<0)
		{
			tmp["part2"]--;
			tmp["part1"]+=MAX;
		}
	}
	else
	{
		if(tmp["part1"]<0)
		{
			tmp["part1"]-=value;
			return 0;
		}
	}
	return tmp;
}

void init()
{
	::init();
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
}
	
int do_deposit(string arg)
{
	int amount;
	string what;
	mapping tmp1,tmp2;
	object ob;
	object me = this_player();
	tmp2=query_max_balance(me);
	write("��Ĵ����ǣ�"+write_balance(tmp2)+"\n");
	
	if(query_temp("busy"))
	{
		me->receive_damage("qi",10);//����ˢ��Ļ
		return notify_fail("�Բ�������æ���أ����Ժ�\n");
	}
	remove_call_out("enough_rest");
	call_out("enough_rest",1);
	set_temp("busy",1);
	
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
		return notify_fail("�����ʽ��deposit:cun <����> <���ҵ�λ>\n");
	ob=present(what,me);
	if(!objectp(ob))
		return notify_fail("��Ҫ��ʲô��\n");
	if(!ob->query("money_id"))
		return notify_fail(ob->name(1)+"("+ob->query("id")+")����Ǯ��Ҳ�����棿\n");
	if (amount < 1)
		return notify_fail("��������" + ob->query("name") + "��\n");
	if ((int)ob->query_amount() < amount)
		return notify_fail("�����" + ob->query("name") + "������\n");
	tmp1=me->query("balance");//����õ���Ӧ����һ��mapping����������������
	if(max_balance(tmp1,tmp2))
	{
		tmp1=tmp2;
		me->set("balance",tmp1);
		return notify_fail("����������Ѿ���������ֵ������Ĵ�û���ˣ�\n");
	}
	
	tmp1=add_balance(tmp1,(int)ob->query("base_value")*amount);
		
	if(max_balance(tmp1,tmp2))
	{
		//��Ϊ��tmp1�Ĳ���ֱ��Ӱ�쵽��������ݣ��������Ӵ˾�ָ�������ݡ�
		tmp1=add_balance(tmp1,-(int)ob->query("base_value")*amount);
		return notify_fail(	"�����ô��Ǯ�Ѿ����������ˡ�\n");
	}
	me->set("balance",tmp1);
	message_vision(sprintf("$N�ó�%s%s%s����������š�\n", 
		chinese_number(amount), ob->query("base_unit"), 
		ob->query("name")), me);
	ob->add_amount(-amount);
	return 1;
}

int do_check()
{
	mapping tmp;
	object me=this_player();
	tmp=me->query("balance");
	write("��Ĵ�������ǣ�"+write_balance(query_max_balance(me))+"��\n");
	write("��Ĵ���ǣ�"+write_balance(tmp)+"��\n");
	return 1;
}

int do_withdraw(string  arg)
{
	int num,v;
	mapping tmp1,tmp2;
	object obj,me;
	if(!arg)
		return notify_fail("��Ҫȡʲô��\n");
	me=this_player();
	if(query_temp("busy"))
	{
		me->receive_damage("qi",10);//����ˢ��Ļ
		return notify_fail("�Բ�������æ���أ����Ժ�\n");
	}
	remove_call_out("enough_rest");
	call_out("enough_rest",1);
	set_temp("busy",1);
	if(sscanf(arg,"%d %s",num,arg)!=2)
		num=1;
	tmp2=query_max_balance(me);
	tmp1=me->query("balance");
	if(max_balance(tmp1,tmp2))
	{
		tmp1=tmp2;
		me->set("balance",tmp1);
		return notify_fail("����������Ѿ���������ֵ������Ĵ�û���ˣ�\n");
	}
	arg=lower_case(arg);
	if(arg=="cash")
		arg="thousand-cash";
	if (file_size("/clone/money/" + arg + ".c") < 0)
	{
		return notify_fail("����ȡ��ʲôǮ��\n");
	}
	arg = "/clone/money/" + arg;
	v=num*arg->query("base_value");
	//Ӧ�����������������
	if(v<0||v>MAX)
		return notify_fail("��һ�β�����ȡ��ô��Ǯ��\n");
	if(v>=tmp1["part1"])
	{
		if(tmp1["part2"]!=0)
		{
			tmp1["part1"]+=MAX;
			tmp1["part2"]-=1;
		}
		else
		{
			if(v!=tmp1["part1"])
				return notify_fail("�Բ��������û����ô��Ǯѽ��\n"+v+" "+tmp1["part1"]);
		}
	}
	
	//��ʼ��ȡ���
	//����MONEY_D->pay_player����Ϊ��ʱ����Ŀ����
	obj=new(arg);
	obj->set_amount(num);
	if(obj->move(me))//move���Ѿ���ԭ���ĸ�������Щ�ϲ��ˣ������һЩ�������ԭ����
	{
		//�ƶ�OK
		if(tmp1=add_balance(tmp1,- v))//���ﲻ����obj->value()�ˣ���Ϊobj->move()�ϲ���money!
		{
			message_vision("$Nȡ��"+chinese_number(num)+obj->query("base_unit")+
				obj->query("name")+"��\n",me);
			me->set("balance",tmp1);
		}
		else
		{
			tmp1=add_balance(tmp1, v);//��Ϊ����Ӱ��������ݣ���дһ��ָ���
			destruct(obj);//����ݻ�
			return notify_fail("��û�д���ô��Ǯ�ɣ�\n");
		}
	}
	else
	{
		//���ع��ء�
		obj->move(environment(me));
		if(tmp1=add_balance(tmp1,- obj->value()))
		{
			message_vision("$Nȡ��"+chinese_number(num)+obj->query("base_unit")+
				obj->query("name")+"����ϧ̫���ˣ�һ���ֵ���������\n",me);
			me->set("balance",tmp1);
		}
		else
		{
			destruct(obj);//����ݻ�
			return notify_fail("��û�д���ô��Ǯ�ɣ�\n");
		}
	}
	return 1;
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
	object me;
	
	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	{
		return notify_fail("�����ʽ��convert|duihuan <����> <���ҵ�λ> to <�»��ҵ�λ>\n");
	}
	if(query_temp("busy"))
	{
		me->receive_damage("qi",10);//����ˢ��Ļ
		return notify_fail("�Բ�������æ���أ����Ժ�\n");
	}
	remove_call_out("enough_rest");
	call_out("enough_rest",1);
	set_temp("busy",1);
	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
	{
		return notify_fail("����һ���ʲô��\n");
	}
	if (!from_ob)
	{
		return notify_fail("������û�д�����Ǯ��\n");
	}
	if (amount < 1)
	{
		return notify_fail("�����׬����\n");
	}
	if ((int)from_ob->query_amount() < amount)
	{
		return notify_fail("�����" + from_ob->query("name") + "������\n");
	}
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
	{
		return notify_fail("����������ֵǮ��\n");
	}

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	

	if (amount == 0)
	{
		return notify_fail("��Щ" + from_ob->query("name") + "��������\n");
	}

	// allowed to convert now
	set_temp("busy", 1);	

	from_ob->add_amount(-amount);

	if (!to_ob) {
		to_ob = new("/clone/money/" + to);
		to_ob->set_amount(amount * bv1 * 10/ (bv2 * 10));
		to_ob->move(me);
	}
	else
		to_ob->add_amount(amount * bv1 * 10 / (bv2 * 10));
	
	message_vision(sprintf("$N������ȡ��%s%s%s��������%s%s%s��\n",
	chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
	chinese_number(amount * bv1 * 10 / (bv2 * 10)), to_ob->query("base_unit"), 
	to_ob->query("name")), me);

//	from_ob->add_amount(-amount);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

	return 1;
}