//Ϊ�˷���edit����鿴����ϸ�ĺ�������˵�������ļ�β
// �ɴ洢����Ͷ��ķ������ BID ROOM v0.1b0
// JackyBoy@CuteRabbits Studio for CCTX 1999/5/17
/*
A] ���ݽṹ���������ԣ�
owner:
	����һ��mapping���ԣ��йؼ���id��mid��name��mname��value
	����id��nameΪ���̾�Ӫ�ߵ�id�����֣���mid��mnameΪ��ʱ�����NPC��ID�����֣������������
	Ϊ�˷�����ҹ�ӶNPC�������Լ���Ӫ���̡�valueΪͶ��������ʽ𣬿�����Ͷ���ʽ�
bider1,bider2:
	������mapping��¼��ǰ��λͶ���ߵ������Լ���ֵ������id,name,value�����⻹��Ͷ��ʱ�䡣
bided:
	��������Ѿ��б����������Բ�Ϊ�գ����ǿ�����owner������ȡ�������Եġ�
auto:
	�����Զ�Ӧ��ģʽ������auto_model�����������أ��ɵ������������ã������δ���ÿ��
	�����йء�
account:
	����Ϊһ��mapping��������¼ӯ��������������룬����һ�ʽ��׵�ʱ�䣬����Ҳ���������
	һ���ʽ�������Ҫ����δ���ÿ�ʽ����ˣ�
	
B] �ṩ�����
rsave:
	�ṩ����ʦ������Ϊ�洢���ITEM�����ݡ���д�ڼ�ʹ��
rset:
	�ṩ����ʦ��������һЩ���ԡ���д�ڼ�ʹ��
bid,sumbit:
	Ϊ����ṩͶ�����������С�(δ���)��Ҫ��Ͷ������ѡ���б��ߵ����⡣
	��������ʹ��void reset()�����Լ���setup()�е���reset()��������飡
show:
	��ʾ���̵ĸ������Ե�״̬��������ʹ�ã�����ʽʹ�ú����ʦ����������ȼ���
	
C] TipS:
1���о�ӪȨ�����Ӧ�ÿ��Դ�����ȡ����������Ŷ�����ȥ�������Ҫ���Ǻã�ֻ��ʹ��Ͷ���ʽ�ʽ
	�ſ���������������ʹ����Ҵӽ�������ɵķ�ʽ�Ļ��Ͳ����ԣ�
2������ЩҪ����ҽ���д��Ĳ���Ҫ�������Ƿ���Ȼ���ڣ�ͬ���أ������ɱӦ��Ҫע���һЩ���ݵ�
	Ӱ�죬�ܱ����Ӧ�þ������⣬����ע���������
	������Ͷ�������ĳ������б�Ӧ�Ը���Ҵ��ڷ���м�飬�����Ͷ��ʱҲӦ�ü��ԭ��������Ƿ�
	��Ȼ���ڡ�
*/

/*
������˵����
int do_save()
	�����ṩ�ֶ���this_object()����save()���ã���Ҫ������ʦ����д�ó���󣬸�����
	���Բ����ڣ�Ŀǰ��Ҫ�������do_set����ʹ��
string query_save_file()
	����ȷ��this_object()�Ĵ����ļ�
void chat()
	�����ṩһ�����Ե�Ƶ����һ��������Ƶ����������ɺ�Ӧ��ȥ�����Ե�Ƶ�����������Բ�
	������д����
void up2owner()
	��bider1���mapping��ĵ�һͶ��������Ϊ��Ӫ�ߣ�����ɾ��bider1����Ϊֱ��
	set(mapping,mapping)����ɴ�ַ�Ĵ��룬����д�ú������⣬������ݽṹ�б仯��ֻ��
	Ҫ�޸���������Լ������������Ϳ����ˡ�
void down2bider()
	����һ�������෴�Ĳ�����
void bider12()
	ͬup2owner()���ƣ������ǽ�bider1���ݸ��Ƶ�bider2�ϣ�bider1Ҳû��ɾ��
void bider21()
	ͬbider12�෴���ǽ�bider2���ݸ��Ƶ�bider1�ϣ������bider2
int do_set(string arg)
	�����ڼ�Ϊ����д���������Եĺ�����������ɺ�Ӧ�����ƿ������õ����ԣ�������Ӫ��
	����һЩoptions���õ����ԡ�
string list_bider()
	���ظ÷����Ͷ����������ַ���������
void init()
	�ṩ�������������ĺ�����Ӧ����ʱӦ����޸ġ�
int exist_id(string arg)
	�����û��IDΪarg��������ݴ��ڣ���Ӧ����1��0��
int working()
	���owner��Ϊ�գ��򷵻�1��ʾ���ھ�Ӫ״̬��
int auto_model()
	���auto���Է�0����ʾ��Ӫ��Ҫ��Ҹ�Ԥ���ú���Ӧ�÷ּ�����߼���������bid room��
*/

//��������Ǿ���this_object�Ĵ洢Ŀ¼�ģ�����Ȩ�����⣬�漰��SECURITY_D��Ķ�д����
#define BIDROOM_DIR DATA_DIR+"SaveRoom/bidroom/"

//��������ʾ�����һ��Ͷ�궯�����ٷ��ӽ���Ͷ�꣬ѡ����Ӫ��
#define BID_TIME 60*30

//��������ʾ����������check�������һ��Ͷ���Լ���Ӫ�ڽ�����
#define CHECK_DELAY 60*30

//��������ʾ�������Ӫ�ߵľ�ӪȨ����
#define OWN_TIME 60*120

//�ļ���Ȩ��˵������Ϣ��ο�dangpu.h����ʽ������Ӧ���ƶ�������
//Ȩ������Ϊ��/data/SaveRoom/�µ��κζ�д����ֻҪ��restore_object or save_object������
//��ο�/adm/daemons/securityd.c

#include <ansi.h>
inherit ROOM;
inherit F_SAVE;

//����Ԥ����
string query_save_file();
void enough_rest();
void chat(string,string);
int working();
int auto_model();


//��д��Ӫ�߻�ȡ����ĺ�������������һ����������������һ��������������ȡ���󣬻���һ���鿴��
//show������ʵ�֣�
int make_money(int value)
{
	int i;
	if(!working())
		return 0;
	i=value/20;
	if(i<5)
		i=5;
	if(i>500)
		i=500;
	add("money",i);
	save();
	return query("money");
}

int do_makemoney()
{
	int value;
	object me=this_player();
	value=query("money");
	if(value<=0)
		return notify_fail("�㻹û���κ����������ȡ�ģ�\n");
	MONEY_D->pay_player(me,value);
	write("��Ӿ�Ӫ"+query("short")+"��ȡ����������ȡ�ˣ�"+MONEY_D->money_str(value)+"��\n");
	delete("money");
	save();
	return 1;
}

//����æ״̬ɾ������
void enough_rest()
{
        delete_temp("busy");
}

void setup()
{
	restore();
	set("no_clean_up",1);//�������ò��ܱ��ݻ�
	chat("sys",query("short")+"��setup()�����á�\n");
	set("no_get",1);
	set("no_get_from",1);//���������������Է������get����
	call_out("checking",1,this_object());
}


int do_save()//���淿�����ݵ������ļ���
{
	if(wiz_level(this_player(1))<wiz_level("(wizard)"))
		return notify_fail("��ļ����ܽ������ֲ�����\n");
	write("���̵������ļ���"+query_save_file()+"...\n");
	if(!save())
		write(query("short")+"���ݴ洢ʧ�ܡ�\n");
	else
		write(query("short")+"�����Ѿ����̡�\n");
	return 1;
}

//�����ļ��ɼ̳е��ļ���ȫ·��ת���õ�������ʹ����base_name����ֹ�̳еĳ��������ֽ�β��
//�Է���ɴ����ļ��ظ���
string query_save_file()
{
	string f_name;
	f_name=base_name(this_object());
	f_name=replace_string(f_name,"/","_");
	return BIDROOM_DIR+f_name;
}

void chat(string type,string arg)
{
	object ob;
	switch(type)
	{
		case "sys":
			foreach( ob in users())
			{
				if(wizardp(ob))
					message("channel:sys", HIR"��ϵͳ��"+arg+"\n"NOR, ob);
			}
			break;
		case "chat":
			message("channel:chat",HIC"�����ġ�"+arg+"\n"NOR, users());
			break;
		default:
			break;
	}
}

void up2owner()
{
	mapping tmp;
	//����ȷ��tmp����Ϊ��
	tmp=query("bider1");
	//set("owner",tmp);//���������Ǵ��ĵ�ַ�������Ǵ�ֵ��
	set("owner/id",tmp["id"]);
	set("owner/name",tmp["name"]);
	set("owner/value",tmp["value"]);
	set("owner/time",time());//��¼���ڵ�ʱ�䣬������checking()���ж��Ƿ��Ѿ�����һ������
}
//����Ӫ�߽���ΪͶ����
void down2bider()
{
	mapping tmp;
	//����ȷ��tmp����Ϊ��
	tmp=query("owner");
	//set("bider1",tmp);//���������Ǵ��ĵ�ַ�������Ǵ�ֵ��
	set("bider1/id",tmp["id"]);
	set("bider1/name",tmp["name"]);
	set("bider1/value",tmp["value"]);
	set("bider1/time",time());//��¼���ڵ�ʱ�䣬������checking()���ж��Ƿ��Ѿ�����һ������
}

//��bider1���ݸ��Ƶ�bider2��
void bider12()
{
	mapping tmp;
	//����ȷ��tmp����Ϊ��
	tmp=query("bider1");
	//set("bider2",tmp);//���������Ǵ��ĵ�ַ�������Ǵ�ֵ��
	set("bider2/id",tmp["id"]);
	set("bider2/name",tmp["name"]);
	set("bider2/value",tmp["value"]);
	set("bider2/time",time());//��¼���ڵ�ʱ�䣬������checking()���ж��Ƿ��Ѿ�����һ������
}

//��bider2�����ݸ��Ƶ�bider2��
void bider21()
{
	mapping tmp;
	//����ȷ��tmp����Ϊ��
	tmp=query("bider2");
	//set("bider1",tmp);//���������Ǵ��ĵ�ַ�������Ǵ�ֵ��
	set("bider1/id",tmp["id"]);
	set("bider1/name",tmp["name"]);
	set("bider1/value",tmp["value"]);
	set("bider1/time",time());//��¼���ڵ�ʱ�䣬������checking()���ж��Ƿ��Ѿ�����һ������
}

int do_set(string arg)//��ʱ�ṩ�����÷���ĸ������ԣ�������ԣ�
{
	string prop,values;
	int valued;
	if(wiz_level(this_player())<wiz_level("(wizard)"))
		return notify_fail("��ļ����ܽ������ֲ�����\n");
	if(!arg||arg=="")
		return notify_fail("��Ҫ����ʲô���ԣ�\n");
	if(sscanf(arg,"%s %d",prop,values)==2)
	{
		write("����"+prop+"��ֵΪ"+set(prop,values)+"(����)��\n");
		return 1;
	}
	if(sscanf(arg,"%s %s",prop,valued)==2)
	{
		write("����"+prop+"��ֵΪ"+set(prop,values)+"(�ַ���)��\n");
		return 1;
	}
	
	return notify_fail("����!���������Ƿ�������ȷ��\n");
}

string list_bider()
{
	mapping tmp;
	string str;
	if(!mapp(tmp=query("bider1")))
	{
		if(query("owner"))
			str=query("short")+"�Ѿ����˾�Ӫ�ˣ������޺򲹾����ߣ�\n";
		else
			str=query("short")+"��û����Ͷ���أ�\n";
	}
	else
	{
		if(query("owner"))
			str=query("short")+"�Ѿ����˾�Ӫ�ˡ�\n";
		else 
			str="";
		str=str+query("short")+"��һͶ���ߣ�"+tmp["name"]+"("+tmp["id"]+")\tͶ���"+
			MONEY_D->price_str(tmp["value"])+"\n";
		if(mapp(tmp=query("bider2")))
			str=str+"�ڶ�Ͷ���ߣ�"+tmp["name"]+"("+tmp["id"]+")\tͶ���"+
				MONEY_D->price_str(tmp["value"])+"\n";
	}
	return str;
}
void init()
{

	add_action("do_save","rsave");
	add_action("do_set","rset");
	add_action("do_bid","bid");
	add_action("do_bid","submit");
	add_action("do_show","show");
	add_action("do_makemoney","ticheng");
}

int exist_id(string arg)
{
	object ob=new(USER_OB);
	if(!arg)
		return 0;
	ob->set("id",arg);
	return ob->restore();
}

int working()//�������������������ã������Ƿ����ִ�и�����
{
	if(!query("owner"))
		return 0;
	return 1;
}

int auto_model()//�����������ֵΪһ��ʾ�����Զ�Ӧ��ģʽ��������������Ҹ�Ԥ
{
	return query("auto");
}
//��������ﲻ��ֱ��ʹ��set,query����Ϊ������call_out����
void checking(object room)
{
	//�������������Ͷ���ߺ;�Ӫ�ߵ���ЧID����Ѿ���ɱ����������¼
	//���е�return ���ǰ��Ӧ���ٴ�call_out�����Լ���
	mapping tmp;
	room->chat("sys",room->query("short")+"��checking���������á�"
		+CHINESE_D->chinese_time(0,(string)localtime(time())));
	room->save();//�������ݣ���Ϊ���ʱ��������Ӧ�ò�Ӱ��ϵͳ������
	if((tmp=room->query("owner"))&&!exist_id(room->query("owner/id")))
	{
		//�����Ӫ�ߣ���Ϊ�Ѿ��������û������ˡ�
		room->chat("chat",tmp["name"]+"("+tmp["id"]+")�Ѿ��˳������ˣ�"+room->query("short")+
			"���½���Ͷ�ꡣ");
		room->delete("owner");
		room->chat("chat",room->list_bider());
		call_out("checking",1,room);
		return;
	}
	if((tmp=room->query("bider1"))&&!exist_id(room->query("bider1/id")))
	{
		//�����һͶ���ߣ���Ϊ�Ѿ��������û������ˡ�
		room->chat("chat",room->query("short")+"�ĵ�һͶ����"+tmp["name"]+"("+tmp["id"]+
			")�Ѿ��˳������ˡ�");
		room->delete("bider1");
		if(room->query("bider2"))
		{
			room->bider21();
			room->delete("bider2");
		}
		room->chat("chat",room->list_bider());
		call_out("checking",1,room);
		return;
	}	
	if((tmp=room->query("bider2"))&&!exist_id(room->query("bider2/id")))
	{
		//����ڶ�Ͷ���ߣ���Ϊ�Ѿ��������û������ˡ�
		room->chat("chat",room->query("short")+"�ĵڶ�Ͷ����"+tmp["name"]+"("+tmp["id"]+
			")�Ѿ��˳������ˡ�");
		room->delete("bider2");
		room->chat("chat",room->list_bider());
		call_out("checking",1,room);
		return;
	}
	if(working())
	{
		if(!(tmp=query("owner")))
			room->chat("sys",room->query("short")+"�޾�Ӫ�߾�Ӫ�����ڴ���״̬������ʦ����");
		else
		{
			if((time()-tmp["time"])>=OWN_TIME)
			{
				//���ﲻ�ü���û�id�Ƿ�����ˣ��ú�������
				//write_money(tmp["id"]);
				room->chat("chat",tmp["name"]+"��"+room->query("short")+
					"�ľ�ӪȨ�Ѿ����ڣ��������¾��꣡");
				if(room->query("bider1"))
					room->bider12();
				room->down2bider();
				room->delete("owner");
				//��ʾͶ������Ϣ
				room->chat("chat",room->list_bider());
			}
		}
	}
	else
	{
		if(!(tmp=query("bider1")))
			room->chat("sys",room->query("short")+"��û��Ͷ���ߣ�");
		else
		{
			if((time()-tmp["time"])>=BID_TIME)
			{
//�������һ������úܶ�ǮͶ�꣬Ȼ����ɱ����һ��ID���أ�
//����Ӧ�����б�ʱ������ID�Ĵ���Ƿ��㹻�����򻻵ڶ���Ͷ������
//�����������Ͷ��ʱ��ֱ�ӿ۳�������˱���߱��Զ��ų��򷵻�����Ŀ
//room->set("owner",tmp);//��Ҳ�Ǵ�ַ�ģ���������д��
				room->up2owner();
				room->bider21();
				room->delete("bider2");
				room->set("account",0);
				//��account���Լ�¼����������ʱ���ʣ�
				//accountӦ����һ��mapping���ԡ�
				room->chat("chat",room->query("owner/name")+"�����"+
					room->query("short")+"�ľ�ӪȨ!");
				room->chat("chat",room->query("short")+"�ĺ򲹾�����Ϊ"+
					room->query("bider1/name"));
				room->save();
				//�б괦��
			}
		}
		//����Ƿ�����Ͷ�꣬�Լ��Ƿ��б�
	}
	call_out("checking",CHECK_DELAY,room);
	return;
}

//�����������ṩ�����һ��Ͷ����������
//Ͷ��ʱ���������ʻ�ΪͶ���ʽ𣬲���Ͷ���ߵ�Ͷ����������ڵ�ǰͶ���߲�����Ͷ���߰�
//Ͷ���߽�������λ���ڶ�λΪ�󱸣�����һλ�޷�Ͷ�����ʱ��ڶ�λ�б꣬����ʱ���˻�Ͷ�����
int do_bid(string arg)
{
	int number,value;
	object me,ob;
	string type;
	mapping tmp;
	me=this_player(1);

	if(query("owner")&&arg&&arg!="cancel")//���owner���Բ�Ϊ0���ʾ�Ѿ������ھ�Ӫ��
		return notify_fail("�Բ��𣬵��������Ѿ������ھ�Ӫ�ˡ�\n");
	if(query_temp("busy"))
	{
		me->receive_damage("qi",10);//����ˢ��Ļ
		return notify_fail("�Բ�������æ���أ����Ժ�\n");
	}
	remove_call_out("enough_rest");
	call_out("enough_rest",1);
	set_temp("busy",1);
	if(arg&&arg=="cancel")//ʹ�ò���"cancel"���˳�Ͷ��
	{
		//����Ѿ����б��ߣ��������ȡ����ӪȨ�����Ҳ�����Ͷ���ʽ�
		if(query("owner/id")==me->query("id"))
		{
			delete("owner");
			chat("chat",me->query("name")+"�޷���Ӫ"+query("short")+"�����ŵ����ˡ�");
			//Ӧ�÷����ˣ���ΪͶ���߸���Ӫ�߲���һ���ˡ�
			return 1;
		}	
		if(query("bider1/id")==me->query("id"))
		{
			//�˳��߿۳�һ��Ͷ�ʣ����ڽ�����һ�룡��ΪͶ��ʱ�Ѿ��۳�ȫ��!
			me->add("balance",(to_int(query("bider1/value")/2)));
			chat("chat",me->query("name")+"�˳��˶�"+query("short")+"�ľ��꣡");
			if(!mapp(query("bider2")))
			{
				delete("bider1");
				delete("bider2");
			}
			else
			{
				//�����ڶ���Ϊ��һ������
				set("bider1",query("bider2"));
				set("bider1/time",time());//��������ʱ��
				chat("chat",query("short")+"�ĵ�һ��������"+query("bider1/name")+"("+
					query("bider1/id")+")��n");
				delete("bider2");
			}
			return 1;
		}
		if(query("bider2/id")==me->query("id"))
		{
			chat("chat",me->query("name")+"�˳���"+query("short")+"�����ˡ�");
			//����������ǵڶ����򲻽����κο۳�
			me->add("balance",query("bider2/value"));
			delete("bider2");
			return 1;
		}
		write("�㲢û������Ͷ�����У���ʹ��show bider�鿴Ͷ���������\n");
		return 1;
	}
	if(!arg||sscanf(arg,"%d %s",number,type)!=2)
		return notify_fail("�������㽫�Զ����ʽ������꣡\n");
	type=lower_case(type);
	if(member_array(type,({"gold","silver","coin","thousand-cash"}))==-1)
		return notify_fail("û��"+type+"���ֻ��Ұɣ���\n");
	value=("/clone/money/"+type+".c")->value()*number;
	if(value>me->query("balance"))
		return notify_fail("��������ʺ�û��ô��Ǯ��������������ʺű������ˡ�\n");
	//Ϊ�˱������̫��bug���ȿ۳�Ͷ���ʽ�����˱���߱��ų�����ʱ�򷵻�һ���ʽ�
	me->set("balance",me->query("balance")-value);
	//Ӧ�ü��bider1�������Ƿ���Ȼ���ڡ�
	if(tmp=query("bider1"))
	{
		if(value<=tmp["value"])
			if(me->query("id")==tmp["id"])
				return notify_fail("ֻ������Ͷ������ܽ��͵ġ�\n");
			else
				return notify_fail("��show bider������"+tmp["name"]+"��Ͷ��������Ӵ��\n");
		if(me->query("id")!=tmp["id"])
		{
			//��ʱӦ�ý�bider2��Ͷ���ʽ�ȫ������
			if(exist_id(query("bider2/id")))
			{
				ob=new(USER_OB);
				ob->set("id",query("bider2/id"));
				ob->restore();
				ob->add("balance",query("bider2/value"));
				if(ob->save())
					chat("sys","�ڶ�Ͷ���ߵ��ʽ𷵻سɹ���\n");
			}
			bider12();//�������ͬ����bider1���Ƶ�2�ϣ���ͬ��ֱ�Ӹ���
		}
		else
		{
			//��Ϊ��ͬһ�������Ͷ���ʽ�Ӧ���ȷ���ԭ��Ͷ���
			me->add("balance",tmp["value"]);
		}
	}
	
	set("bider1/id",me->query("id"));//ע����ߵ�Ӱ��
	set("bider1/name",me->query("name"));
	set("bider1/value",value);
	set("bider1/time",time());//��¼���ڵ�ʱ�䣬������checking()���ж��Ƿ��Ѿ�����һ������
	chat("chat",me->query("name")+"��"+MONEY_D->price_str(value)+"��Ͷ��"+query("short")
		+"�ľ�ӪȨ��");
	if(save())
		write("Ͷ��ɹ�������show status����鿴Ͷ�������\n");
	else
		write("Ͷ���������ϵ��ʦ������⡣\n");
	save();
	return 1;	
}

//�����������ṩһ������ز鿴�������Ե�ֵ���ֶ�
//��һ����ѯ��Ӫ��ʣ��ʱ��Ĺ��ܣ���������ں��汻�̳к�Ӧ������д����
int do_show(string arg)
{
	
	if(!arg||arg=="")
		return notify_fail("����鿴ʲô��\n");
	if(lower_case(arg)=="bider")
	{
		write(list_bider()+"\n");
		return 1;
	}
	if(lower_case(arg)=="status")
	{
		printf("���̵�ǰ״̬��\n"
			"�Զ�Ӧ��%s\n����Ͷ��״̬��%s\n���̾�Ӫ�ߣ�%s\n"
			"��һͶ���ߣ�%s\tͶ���%s\n"
			"�ڶ�Ͷ���ߣ�%s\tͶ���%s\n"
			"���̾�Ӫ״̬��%s\n"
			,
			(auto_model())?"ON":"OFF",
			(query("owner"))?"���":"δ���",
			(query("owner"))?(query("owner/name")+"("+query("owner/id")+")"):"��",
			(query("bider1"))?(query("bider1/name")+"("+query("bider1/id")+")"):"��",
			MONEY_D->price_str((query("bider1"))?(query("bider1/value")):0),
			(query("bider2"))?(query("bider2/name")+"("+query("bider2/id")+")"):"��",
			MONEY_D->price_str((query("bider2"))?(query("bider2/value")):0),
			(working())?"ON":"OFF",
			
		);
		return 1;
	}
	write("��û�ж�����"+arg+"�Ĵ������\n");
	return 1;
}
