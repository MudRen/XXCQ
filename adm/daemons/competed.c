// competed.c
// create by netplay@cctxII 
/*
�μӱ�����ѡ�ֵ÷ֹ������¼��������
A��˫��EXP������һ���ȼ�
        1��˫�����ϰ��˫�������ϰ� ʤ��300 ����0
        2��һ���ϰ�һ��δ��  
                �ϰ���--δ�ϰ���
                ʤ��200   ʤ��300
                ����-50   ����0

B��˫��EXP����ȣ������̫�����ֹ���䣩
        1��˫�����ϰ��˫�������ϰ����  
                EXP����--EXP����
                ʤ��200    ʤ��300      
                ����0      ����0        
       2��һ���ϰ�һ��δ��
                EXP���ϰ�--EXP��δ�ϰ�
                ʤ��0         ʤ��400
                ����-300        ����0

                EXP��δ�ϰ�--EXP���ϰ�
                ʤ��200         ʤ��200
                ����-50         ����-50

ע�������ϰ�Ϊ����ǰ50λ��
*/


inherit F_SAVE;
inherit F_DBASE;
int sort_fighter(object);
int query_place(object);
string *get_tops();
int wincom( string,string);
mapping top;

void create()
{	
	seteuid(getuid());
	set("channel_id","���侫��");
    if( !restore() && !mapp(top) )
        top = ([]);
}

string query_save_file() { return DATA_DIR + "topd"; }

void fighter_place(object winner,object loser)
{
	
	int wtag=0,ltag=0;
	int wexp,lexp;
	int wplace,lplace;
	object win_body,los_body;
	win_body=winner->query_temp("link_ob");
	los_body=loser->query_temp("link_ob");
	//��ѯ����˫���Ƿ����ϰ���Ա
	wtag=query_place(winner);
	ltag=query_place(loser);
	
	//��ѯ����˫����EXP
	wexp=winner->query("combat_exp");
	lexp=loser->query("combat_exp");

	//����������Ӧ�ĸ����˵Ļ�����Ӻͼ���
	if( (wexp+=wexp/2 > lexp) && (lexp+=lexp/2 > wexp) )//exp���һ��
	{	if( (wtag && ltag) || (!wtag && !ltag) )//˫�����ϰ���ϰ�
		win_body->add("jifen",300);
		if(wtag && !ltag)//ʤ���ϰ񣬸���û��
		win_body->add("jifen",200);
		if(ltag && !wtag)//�����ϰ�ʤ��û��
		{win_body->add("jifen",300);los_body->add("jifen",-50);}
	}else //exp��Բ�һ��
	{
			if((wtag && ltag) || (!wtag && !ltag))//˫�����ϰ���ϰ�
			if( lexp+=lexp/2 <= wexp ) //ʤ��EXP������
				win_body->add("jifen",200);
			else win_body->add("jifen",300);//ʤ��EXPС
			if(wtag && !ltag)//ʤ���ϰ񣬸���û��
			if( wexp+=wexp/2 <= lexp ) //ʤ��EXPС�����
			win_body->add("jifen",200);
			else los_body->add("jifen",-50);

			if(ltag && !wtag)//�����ϰ�ʤ��û��
			if( wexp+=wexp/2 <= lexp ) //ʤ��EXPС�����
			{win_body->add("jifen",400);los_body->add("jifen",-300);}
			else//ʤ��EXP��
			{win_body->add("jifen",200);los_body->add("jifen",-50);}
	}
	win_body->add("win",1);
	los_body->add("loss",1);

	wplace=sort_fighter(win_body);
	lplace=sort_fighter(los_body);
	
	//CHANNEL_D->do_channel( this_object(), "debug",
	//sprintf("ʤ���ߣ���%d����ʧ���ߣ���%d��\n",wplace,lplace));
	
	save();
	win_body->save();
	los_body->save();
	winner->save();
	loser->save();
}

int sort_fighter(object body)
{
	string *name;
	int jf,ave_jf;
	int win,loss;
	int i;
	//ȡ��ob�Ļ���
	jf=body->query("jifen");
	win=body->query("win");
	loss=body->query("loss");
	ave_jf=jf/(win+loss);
//debug
	//CHANNEL_D->do_channel( this_object(), "debug",
	//		sprintf("%sʤ��%d�Ρ�ʧ��%d�Ρ��ܻ���%d\n",body->query("id"),win,loss,jf));
	//ȡ���ڰ���Ա������������������������
	if (mapp(top))
	{
		name=keys(top);
		i=sizeof(name);
		if(i==0 && ave_jf>0)//������ְ�Ϊ�յĻ�
		{top=( [body->query("id"): ave_jf] );
		//debug
		//CHANNEL_D->do_channel( this_object(), "debug",
		//	sprintf("%s��ƽ������Ϊ%d\n",body->query("id"),ave_jf));
		return 1;
		}
		if(i<50 && ave_jf>0){
		top[body->query("id")]=ave_jf;//��������50��ֱ�Ӽ���
		//debug
		//CHANNEL_D->do_channel( this_object(), "debug",
		//	sprintf("%s��ƽ������Ϊ%d\n",body->query("id"),ave_jf));
		return query_place(body);} 
		else
		{
		name=get_tops();
		if(ave_jf>top[name[0]]){
			map_delete(top,name[0]);
			top[body->query("id")]=ave_jf;
			//debug
			//CHANNEL_D->do_channel( this_object(), "debug",
			//sprintf("%s��ƽ������Ϊ%d\n",body->query("id"),ave_jf));
			return query_place(body);
			}

		}
	}
	
}
//��ѯOB�����������û�ϰ񣬷���0���ϰ񣬷������Ρ�	
int query_place(object ob)
{
		string *name;
		string id;
		int i;

		id=ob->query("id");
		name=get_tops();
		for(i=0;i<50;i++)
		{
		if (id==name[i]) 
				{return i+1;break;}
		}
		return 0;
}
//�ú��������������а����Ա����
string *get_tops()
{	
	string *name;
	string str;
	int i,j,z;

	if(mapp(top))
	name=keys(top);

	z=sizeof(name);
	for(j=0;j<z-1;j++)
	for(i=0;i<(z-j)-1;i++)
	{	if(top[name[i]]<top[name[i+1]])
		{str=name[i];name[i]=name[i+1];name[i+1]=str;}
		if(top[name[i]]==top[name[i+1]])//������ͬ
			if(wincom(name[i],name[i+1]))
			{str=name[i];name[i]=name[i+1];name[i+1]=str;}
	}
	return name;
}

int wincom( string id1,string id2)
{
	object ob1,ob2;
	int i;
	ob1 = new(LOGIN_OB);
	ob1->set("id", id1);
	
	ob2 = new(LOGIN_OB);
	ob2->set("id", id2);
	
	if(ob1->restore() && ob2->restore())
		i=ob2->query("win") - ob1->query("win");
	destruct(ob1);
	destruct(ob2);
	return i;
}


string user_fight_info(string name)
{
	object ob;
	string msg;
		
	
	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() ) 
		return "�����ˡ�\n";
	
	msg = sprintf("%-25s������%s��  ʤ��%s��  �ܣ�%s�� \n",
		  ob->query("name")+"("+ob->query("id")+")",
		  chinese_number(ob->query("win")+ob->query("loss")),
		  chinese_number(ob->query("win")),
		  chinese_number(ob->query("loss")),
		   );
	destruct(ob);

	return msg;
}