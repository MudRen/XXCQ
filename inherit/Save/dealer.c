//���̵İ����ļ�
/*����˵����
void init()
	����sell,list,buy,value��������
	ע�⣺��Щ���ʵ����ͬʱ����������Ʒ��֧�֣�
int do_value(string arg)
	�ṩһ���������ҹ���������Ʒ�ļ�ֵ
int do_list()
	�г��������ж��ٶ������ڳ���
int do_sell(string arg)
	��������ϵ���Ʒ���������
void pay_money(object ob,int value,int num,string op)
	��Ǯ�Լ���Ϣ��ʾ��Ĭ�ϸ�Ǯ����Ϊthis_player()��op��ֵֻ������"��"����"�䵱"
void get_money()��pay_money�෴
*/

//������������������Ʒ������Ӧ�ð�������㣬����ֻ��һ��ԭ���ϵ����ֵ��ʵ�����ֵ
//����query("max_sell")�õ�
#define MAX_SELL 100

/* ����˵��:
sell_number : �Ǳ�������������Ʒ�����������ʼΪ0
sell_object : ������¼��������������Ʒ
��������    : �ƶ���/d/sroom/storage��������Ϊ��ʼ��������tag/selled����Ϊ1��ʾ������

*/

inherit BID_ROOM;

string get_dwei(object);

void pay_money(object ob,int value,int num,string op)
{
	string dwei;
	dwei=get_dwei(ob);
	if(!op)
		op="��";
	message_vision("$N"+op+"��"+chinese_number(num)+
		dwei + ob->query("name") + "��\n",this_player(1));
	MONEY_D->pay_player(this_player(), value * 70 / 100);
	tell_object(this_player(),"������"+MONEY_D->price_str( value * 70 / 100)+"��\n");
}


string get_dwei(object ob)
{
	string dwei;
	//�ж�������λ
	if(!stringp(dwei=ob->query("base_unit")))
		dwei=ob->query("unit");
	if(!stringp(dwei))
		dwei="Щ(������λ����!)";
	return dwei;
}

void init()
{
	::init();
	add_action("do_sell","sell");
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_value","value");
}


int do_value(string arg)
{
	//���и����⣬���ܶ�base_value�ߣ�����value�׵Ĺ��Ƽ�ֵ��
	object ob;
	string dwei;
	int value,num;
	if (!arg)
		return notify_fail("��Ҫ��ʲô�ļۣ�\n");
	if (sscanf(arg,"%d %s",num,arg)!=2)
		num = 1;
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô�ļۣ�\n");
	if (ob->query("money_id"))
		return notify_fail("��û�ù�Ǯ����\n");
	if (userp(ob))
		ob->set("value", ob->query("per") * 500);
	dwei=get_dwei(ob);		
	value = ob->query("value");
	value*=num;
	if(value==0)
		value=ob->query("base_value")*num;
	if (value < 1)
		write(chinese_number(num)+dwei+ob->query("name") + "һ�Ĳ�ֵ��\n");
	else 
		write(chinese_number(num)+dwei+ob->query("name") + "ֵ" + 
		MONEY_D->price_str(value * 70 / 100) + "��\n");
	return 1;
}

//op��ֵֻ������"��"����"���"
void get_money(object ob,int num,string dfn,string op)
{
	string dwei;
	object nob,me;
	int vl;
	me=this_player();
	if(!vl=ob->query("base_value"))
		vl=ob->query("value");
	if(!op)
		op="��";
	if(op!="��"&&op!="���")
		return notify_fail("get_money()����!->op="+op+"\n");
	if(vl<1)
	{
		write("�����Ʒ�ļ۸��е����⣬��ʱ���ܸ��㣡\n");
		return;
	}
	dwei=get_dwei(ob);
	switch (MONEY_D->player_pay(me, vl*num))
	{
		case 0:
			write("�����ϵ�Ǯ����"+op+chinese_number(num)+dwei+ob->name(1)+"��\n");
			return;
		case 2:
			write("�����Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
			return;
		default:
			message_vision("$N����"+MONEY_D->price_str(vl*num)+
				op+"��"+chinese_number(num)+dwei+ob->name(1)+"\n",me);
			//�ƶ�OB��ע�⣡û�м��㸺�������
			if(ob->query_amount()!=0)
			{
				ob->set_amount(num);
				if(ob->move(me)==0)
				{
					ob->move(environment(me));
					message_vision("$N���ϵĶ���̫���ˣ�"+chinese_number(num)+dwei+ob->name(1)
						+"�ò��ȵ���������\n",me);
				}
			}
			else
			{
				for(vl=num;vl>0;vl--)
				{
					nob=new(base_name(ob));
					if(nob->move(me)==0)
					{
						nob->move(environment(me));
						message_vision("$N���ϵĶ���̫���ˣ�"+nob->name(1)+"�ò��ȵ���������\n",me);
					}
				}
			}
			//���ٵ�����Ļ������������ݲ�ͬ�ĵ��ý��в�ͬ�Ĵ���
			if(op=="��")
			{
				if((query("sell_object/"+dfn+"/number")-num)==0)
					delete("sell_object/"+dfn);
				else
					add("sell_object/"+dfn+"/number",-num);
			}
			else
			{
				if((query("pawn_object/"+me->query("id")+"/"+dfn+"/number")-num)==0)
					delete("pawn_object/"+me->query("id")+"/"+dfn);
				else
					add("pawn_object/"+me->query("id")+"/"+dfn+"/number",-num);
			}
	}
	return ;
}	
int do_buy(string arg)
{
	int num,sno;
	mapping sob,fob;
	string fn,dfn;
	object ob;
	if(!sob=query("sell_object"))
		return notify_fail("��������û���κζ�������������\n");
	if(!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if(query_temp("busy"))
	{
		this_player()->receive_damage("qi",10);//����ˢ��Ļ
		return notify_fail("�Բ�������æ���أ����Ժ�\n");
	}
	remove_call_out("enough_rest");
	call_out("enough_rest",1);
	set_temp("busy",1);
	if(sscanf(arg,"%d %s",num,arg)!=2)
		num=1;
	if(sscanf(arg,"%s %d",arg,sno)!=2)
		sno=1;
	dfn="�޴���";
	foreach(fn in keys(sob))
	{
		fob=sob[fn];
		if(member_array(arg,fob["id"])!=-1)
			sno--;
		if(sno==0)
		{
			dfn=fn;
			break;
		}
	}
	if(dfn=="�޴���"||sno!=0)
		return notify_fail("��Ҫ��Ķ�����������û��������\n");
	ob=new(replace_string(dfn,"\\","/"));
	fob=sob[fn];
	if(num>fob["number"])
		num=fob["number"];
	get_money(ob,num,dfn,"��");//ʹ��Ĭ�ϵ�this_player()���в�����
	return 1;
}

int do_list()
{
	object ob;
	mapping sob;
	int number;
	string file,str,tmp,prop;
	str="";
	if(!sob=query("sell_object"))
		return notify_fail("��������û���κζ�������������\n");
	foreach(file in keys(sob))
	{
		ob=new(replace_string(file,"\\","/"));
		if(!objectp(ob))
			continue;//Ӧ��ɾ�������ԣ�
		prop="sell_object/"+file;
		number=query(prop+"/number");
		if(ob->query_amount()!=0)
			ob->set_amount(number);
		ob->set_name(query(prop+"/name"),query(prop+"/id"));
		if(!(tmp=ob->query("base_unit")))
			tmp=ob->query("unit");
		str+=chinese_number(number)+tmp+ob->name(1)+"("+
			implode(ob->parse_command_id_list(),",")+") ���ۣ�";
		if(ob->query("base_value"))
			str+=MONEY_D->price_str(ob->query("base_value"));
		else
			str+=MONEY_D->price_str(ob->query("value"));
		str+=" ��������"+CHINESE_D->chinese_time(5,(string)ctime(query(prop+"/time")))+"\n";
	}
	this_player()->start_more(str);
	return 1;
}

int do_sell(string arg)
{
	//����no_give����Ʒ
	object ob,me,nob,tmpob;
	object *obs,*tobs;
	int number,num,tmp;
	string str,prop;
	int value,i;
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	me=this_player(1);
	if(query_temp("busy"))
	{
		me->receive_damage("qi",10);//����ˢ��Ļ
		return notify_fail("�Բ�������æ���أ����Ժ�\n");
	}
	remove_call_out("enough_rest");
	call_out("enough_rest",1);
	set_temp("busy",1);
	if (sscanf(arg,"%d %s",num,arg)!=2)
		num=1;
	if (!(ob = present(arg, me)))
		return notify_fail("��Ҫ��ʲô��\n");
	if (ob->query("money_id"))
		return notify_fail("��������Ǯ������\n");
	if (stringp(ob->query("no_drop"))||ob->query("no_pawn")||ob->query("nopawn")||
		ob->query("nopawn")||ob->query("no_pawn")||ob->query("item_origin"))
		return notify_fail("����������������\n");
	if (ob->query("food_supply"))
		return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");
	if (ob->query("shaolin"))
		return notify_fail("С��ֻ��һ���Դ����ɲ��������������\n");
	if (userp(ob))
	{
		/*��ʱ��ֹ����������ң�Ҫ�޸�Ϊֻ�������˷�������ң�*/
		return notify_fail("����������������ģ����ܹ����˿ڣ������ȥ����Ȼ�ҽйٱ��ˣ�\n");
		num=1;//��Ϊ��ֻ������һ�������ԼӸ�������������룡
		CHANNEL_D->do_channel(ob, "rumor",
			sprintf("%s��ĳ�˹����ˡ�", ob->name(1)));
	}
	else
	if((ob->query("enpawn")==0)//���������Բ�Ϊ0��˵�����ǿ������ģ�������is_character()�ж��أ�
		&&(
			ob->query("hunmi")!=0||living(ob)
			||ob->query_temp("block_msg/all")==1
		)
	)
		return notify_fail("��������ǻ��ѽ������ô����湻�����ˣ�\n");
	//�˴����num���Ƿ�Ϸ���
	if((tmp=ob->query_amount())!=0)//�����set_amount����Ʒ��ֱ�Ӳ�ѯamount
	{
		if(tmp<num)
			num=tmp;
	}
	else//����ID�����ֽ���ͳ�ƣ��Ȼ�ȡ������ƷȻ���ų�����ֻʣͬ����ͳ�ƣ�
	{
		obs=all_inventory(me);
		tmp=sizeof(obs);//�����˿�ʱ�����д�
		tobs=({});
		for(i=0;i<tmp;i++)
		{
			if( !( obs[i]->name(1)!=ob->name(1) || !obs[i]->id(ob->query("id")) ) )
				tobs=tobs+({ obs[i] });//��ͬ���︴�Ƶ�tobs��
		}
		obs=tobs;//��obs��Ϊtobs
		tmp=sizeof(obs);
		if(tmp<num)
			num=tmp;
	}
	//�����amount��ƷӦ�÷��������
	if(ob->query_amount()!=0)
	{
		if(!objectp(nob=new(base_name(ob))))
			write("��������Ʒ����"+(string)(ob->query_amount()-num)+"\n");
		nob->set_amount(ob->query_amount()-num);//����������ϵ���Ʒ�����٣���
		//nob->move(this_player());�������������move��ob�Ļ���������ͬ��OBJECT�ˣ�
		ob->set_amount(num);
	}
	else
		nob=ob;//����value<30ʱ�жϳ���
	value = ob->query("value");
	if(!value)
		value=ob->query("base_value");
	if(value<1)
		value=1;
	value*=num;
	number=num;	
	if (value < 30)
	{
		ob->set_amount(nob->query_amount()+num);
		write(ob->query("name") + "һ�Ĳ�ֵ��\n");
	}
	else 
	{
		if ( userp(ob))
		{
			//�������Ĳ�����Ӫ�ߵ�Ǯ������������ʱ��Ҳֻ����Ӫ�����
			pay_money(me,value,1,"��");
			ob->move("/d/sroom/storage");
			ob->set("startroom","/d/sroom/storage");
			ob->set("tag/selled",1);
		}
		else
		if (value < 50)
		{
			pay_money(ob,value,num,"��");
			if(pointerp(obs))//���Ϊ��˵���Ƿ�amount��Ʒ��Ӧ�ð�num�����
			{
				for(i=num;i>0;i--)
				{
					tmpob=obs[0];
					obs=obs - ({ tmpob });
					if(objectp(tmpob))
						destruct(tmpob);
				}
			}
			else//���������˵��ǰ���Ѿ��ݻ��ˣ������Ӧ����amount��Ʒ
			{
				destruct(ob);
				nob->move(me);
			}
		}
		else
		{
			//�����Ǵ��������Ĵ���չ���������Ʒ�Ĵ���
			//��μ�¼�����������Ʒ�أ�
			//��Ʒ�ļ�����ʱ�䣬������name��id
			//str��������ļ���
			str=base_name(ob);
			str=replace_string(str,"/","\\");		//ע�⣺"\\"��"\"!
			//��Ϊ����ǿ���amount�����ģ���ôquery_amount�϶�������0
			//��������amount��query_amount�϶�����0
			//����ֱ��query_amount�Ϳ����ж��Ƿ������amount����
			//�������number==0��ô˵������amount��Ʒ����������һ����1
			prop="sell_object/"+str;//���ô洢����Ʒ��������
			
			//����������������������Կ�Ͷ�ʻ���������������
			//�������Ӧ��֧�ֿ�������һ�ֻ������ͬʱ��಻Ӧ�ñ�MAX_SELL��
			i=query("max_sell");
			if(i>MAX_SELL)
				i=MAX_SELL;
			if(i<1)
				i=1;
			if(!query(prop))//�����ѯ���ˣ�˵��ԭ�����Ѿ����ڸ���Ʒ�ˣ�û�����ʾ����������Ʒ��
				if(sizeof(query("sell_object"))>i)
					return notify_fail("�Բ��𣬲ֿ��Ѿ������˻���޷�������Ķ����ˡ�\n");
			set(prop+"/time",time());
			set(prop+"/name",ob->name(1));//���Ե���Ӧ�ö������������
			set(prop+"/id",ob->parse_command_id_list());//����һ��string *���ͣ�
			set(prop+"/number",number+query(prop+"/number"));//�Ƿ�Ӧ�ö������Ʒ
			pay_money(ob,value,num,"��");
			//������Ҫ��������Ĵ������︺�����ӣ�buy�����︺�����
			if(pointerp(obs))//���Ϊ��˵���Ƿ�amount��Ʒ��Ӧ�ð�num�����
			{
				for(i=num;i>0;i--)
				{
					tmpob=obs[0];
					obs=obs - ({ tmpob });
					if(objectp(tmpob))
						destruct(tmpob);
				}
			}
			else//���������˵��ǰ���Ѿ��ݻ��ˣ������Ӧ����amount��Ʒ
			{
				destruct(ob);
				nob->move(me);
			}
		}
	}
	return 1;
}
