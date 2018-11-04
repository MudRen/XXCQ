#include <ansi.h>

inherit SR_DEALER;

/*
�䵱��Ʒ������pawn_object������һ�����û���ID��ID�����ǵ䵱��Ʒ���ļ���
��������Ǹ���Ʒ��һЩ��Ϣ��
*/

//ÿ����ԭ���Ͽ��Ե䵱�������Ʒ������
//ʵ�������Ե䵱������ҵ�"max_pawn"����������
#define MAX_PAWN 100

//ԭ���ϵ��̿��������������������ʺ�
//ʵ���������"max_account"���Կ���
//Ϊ�˲������˷���Դ��Ӧ���ڶ��ڼ�������һ������������Ƿ��й����˵��ʺŻ��߻��
#define MAX_ACCOUNT 300

//����䵱��Ʒ����ʱ�䣬������ʱ���Ҫ�����뾭Ӫ�ߵĴ����
//�Զ�����2592000�룬Ҳ����һ���£�(100000000�ڶ���������ģ�)
#define PAWN_TIME 60*60*24*30

void init()
{
	::init();
	add_action("do_pawn","pawn");
	add_action("do_redeem","redeem");
	add_action("do_redeemp","redeemp");
}

void checking(object ob)
{
	chat("sys","���Ժ��������á�\n");
	//��������д�ǿ��еģ�
	//������������д��鵱����Ļ����Ƿ���
	::checking(ob);
}

int do_redeemp(string target)
{
	object me,dest;
	me=this_player();
	if(!target||target=="")
		return notify_fail("��Ҫ��ʲô�ˣ�\n");
	if(query_temp("busy"))
	{
		me->receive_damage("qi",10);//����ˢ��Ļ
		return notify_fail("�Բ�������æ���أ����Ժ�\n");
	}
	remove_call_out("enough_rest");
	call_out("enough_rest",1);
	set_temp("busy",1);
	if(!objectp(dest=find_player(target)))
		return notify_fail("���("+target+")Ŀǰ�������ϣ�\n");
	if( !dest->query("tag/selled"))
		return notify_fail(dest->name(1)+"��������û��أ�\n");
	switch (MONEY_D->player_pay(me, dest->query("per") * 700))
	{
	case 0:
		return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	case 2:
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
		message_vision("$N�����һ"+dest->query("unit")+dest->query("name")+"��\n", me);
		dest->move(this_object());
		dest->set("startroom",base_name(this_object()));
		dest->set("tag/selled",0);
		message("vision",
			HIY "ֻ����ವ�һ����һ���������˵ļһ���컨���ϵ���������\n" NOR,
			environment(dest), dest);
		tell_object(dest, "�㱻" + me->query("name") + "���˳�����\n");
	}
	return 1;
}

int do_redeem(string arg)
{
	object ob,me;
	mapping sob,fob;
	int number,num,sno;
	string file,str,tmp,prop,fn,dfn;
		
	me=this_player(1);
	//�����Ʒ��ȡ���˾ͱ�ʾȡ���ʻ���
	if(member_array(me->query("id"),keys(query("pawn_object")))==-1)
		return notify_fail("��û�������￪������ô��ȡ�����أ���\n");
	if(query_temp("busy"))
	{
		me->receive_damage("qi",10);//����ˢ��Ļ
		return notify_fail("�Բ�������æ���أ����Ժ�\n");
	}
	remove_call_out("enough_rest");
	call_out("enough_rest",1);
	set_temp("busy",1);
	sob=query("pawn_object/"+me->query("id"));
	//��ʱ��ʾ�е䵱�˵���Ʒ����
	if(!arg)//�޲�������ʾ�䵱��Ʒ�����
	{
		str="���ڱ����̵䵱����Ʒ�У�\n";
		foreach(file in keys(sob))
		{
			ob=new(replace_string(file,"\\","/"));
			if(!objectp(ob))
				continue;//Ӧ��ɾ�������ԣ�
			prop="pawn_object/"+me->query("id")+"/"+file;
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
			str+=" ���䵱��"+CHINESE_D->chinese_time(5,(string)ctime(query(prop+"/time")))+"\n";
		}
		this_player()->start_more(str);
		return 1;
	}
	//��ȡ��Ʒ�Ĵ����
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
		return notify_fail("��Ҫ��Ķ�������û�е䵱��ѽ��\n");
	ob=new(replace_string(dfn,"\\","/"));
	fob=sob[fn];
	if(num>fob["number"])
		num=fob["number"];
	get_money(ob,num,dfn,"���");//�������һ������������"���"����"��"
	return 1;
}

int do_pawn(string arg)
{
	//����no_give����Ʒ
	object me,ob,nob,tmpob;
	object *obs,*tobs;
	int number,num,tmp;
	string str,prop;
	int value,i;
	if (!arg)
		return notify_fail("��Ҫ�䵱ʲô��\n");
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
		return notify_fail("��Ҫ�䵱ʲô��\n");
	if (ob->query("money_id"))
		return notify_fail("����䵱��Ǯ������\n");
	if (stringp(ob->query("no_drop"))||ob->query("no_pawn")||ob->query("nopawn")||
		ob->query("nopawn")||ob->query("no_pawn")||ob->query("item_origin"))
		return notify_fail("�����������ܵ䵱��\n");
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
	if((ob->query("enpawn")==0))
		return notify_fail("����������ǲ���Ӫ�ģ����ܵ䵱���㻹�Ǹɴ��������ˣ�\n");

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
			//�䵱�����Ĳ�����Ӫ�ߵ�Ǯ�����ǵ䵱����ʱ��Ҳֻ����Ӫ�����
			pay_money(me,value,1,"�䵱");
			ob->move("/d/sroom/storage");
			ob->set("startroom","/d/sroom/storage");
			ob->set("tag/selled",1);
		}
		else
		if (value < 50)//valueС��50����Ʒֻ�����٣�
		{
			pay_money(ob,value,num,"�䵱");
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
			prop="pawn_object/"+me->query("id")+"/"+str;//���ô洢����Ʒ��������
			
			//�����û��ڱ����̵Ĵ洢���ﵽ�����ޣ�
			i=me->query("max_pawn");
			if(i>MAX_PAWN)
				i=MAX_PAWN;
			if(i<0)
				i=1;
			
			//�����ѯ���ˣ�˵��ԭ�����Ѿ����ڸ��ʺ���
			if( member_array(me->query("id"),keys(query("pawn_object"))) !=-1)
			{
				if(sizeof( query( "pawn_object/"+me->query("id") ) )>i)
					return notify_fail("�Բ�������ʺ��Ѿ��䵱�ܶ���Ʒ�ˣ������ٶ��ˡ�\n");
			}
			else
			{
				//��һ�μ���Ƿ���Կ���
				
				if(me->query("pawn_room")>0)
					return notify_fail("�㲻�����ڵ��̿���ͷ�ˡ�\n");
				me->add("pawn_room",1);
				//����������������Ϊ���������������ڶ�����̿���
				//Ĭ�Ͼ���ֻ����һ�����̿���
				i=query("max_account");
				if(i>MAX_ACCOUNT)
					i=MAX_ACCOUNT;
				if(i<0)
					i=1;
				if(sizeof(query("pawn_object"))+1 >i)
				{
					me->add("pawn_room",-1);//��ԭ�ɿ�����
					return notify_fail("�Բ�����������Ѿ���"+(string)(i+1)+"���˿��˻�ͷ�ˣ���ֻ�е�"+
						"�������ݺ��ٵ䵱�ˡ�\n");
				}
			}

			set(prop+"/time",time());
			set(prop+"/name",ob->name(1));//���Ե���Ӧ�ö������������
			set(prop+"/id",ob->parse_command_id_list());//����һ��string *���ͣ�
			set(prop+"/number",number+query(prop+"/number"));//�Ƿ�Ӧ�ö������Ʒ
			pay_money(ob,value,num,"�䵱");
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