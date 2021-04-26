#define CK_DELAY 10*1
#define TIME_OUT 30*1
#define DEBUG

#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>

inherit F_DBASE;
//��������ʹ�õ�socket�źͷ��ͱ�־
nosave int my_socket;
//������������ж϶��ߣ���

nosave int session_id=0;
nosave mapping cur_session=([]);// object sob,string cmd
nosave int cur_sid=0;
nosave int timeout_running=0;
nosave string server_ip="127.0.0.1";
nosave string server_port="8848";

nosave string password="pass";
object requst_ob;

int write_message(string);
int do_connect(string arg);
void chat(string arg,string opt);

nosave int add_lock=0;

nosave int doing=0;
nosave int connected=0;
nosave int logined=0;
nosave int do_session_flag=0;
nosave int waiting=0;//�ȴ�������֤

nosave string buff="";
int del_session(string sid)
{
	chat("׼��ɾ��sidΪ:"+sid+" ������","debug");
	delete("session/"+sid);
}
mapping session() //id,cur_sesson  ��������ʹ��DBASE����Ϊ�漰������mapping
{
	return query("session");
}


//�Ե�ǰ��ҲҪ��

int make_sid()
{
	return session_id++;
}

void process(mixed msg)
{
	string sid,*msgarr;
	mapping tmps=([]);

	if(!stringp(msg))
	{
		chat("�յ����ַ�������ֵ","sys");
		return;
	}
	//msg������һ�������ַ���Ӵ��Ӧ�÷��д���
	msgarr=explode(msg,"\n");
	for(int i=0;i<sizeof(msgarr);i++)
	{
		msg=msgarr[i];
		msg=replace_string(msg,"\r","");
		chat("����:"+msg,"sys");
		if(sscanf(msg,"%s`%s",sid,msg)==2)
		{
			tmps=query("session/"+sid);
			if(sizeof(keys(tmps))<=0)
				chat("ϵͳ���󣬽��յ����������ڵ�����ID������","sys");
			//���ͻ�����������
			if (msg=="pass ok")//switch?
			{
				//���õ�¼�ɹ�
				chat("��¼�ɹ�","debug");//δ��ʾ����
				logined=1;
			}
			else if (msg=="session end")
			{
				chat(sprintf("�յ��������������ͻ�����Ϣ��ָ�������%O",query("session/"+sid+"/object")),"debug");
				//����������������ݵ��û�
				query("session/"+sid+"/object")->incoming(sid,buff);
				buff="";//���û�����
				//�Ƿ������ж����ӣ�
				del_session(sid);
				do_session_flag=0;//����һ������
			}
			else
			{

				chat("sizeof(msg)"+sizeof(msg)+" δ֪����["+msg+"]\n","sys");
			}
		}
		else
		{
			//���ͻ��������ַ����ݣ���ʵ��Ϣ����ҲӦ�������������ƣ����ⷢ��
			buff=buff+msg;
		}
	}
}


//����ؼ��͸��ӵ�״̬�������͹��ܣ�ֻҪ��ȫʵ�� session��״̬������һ���Ķ�������ôdo_session���������ε���
//ÿ��������ɺ�Ӧ���и������ܾ��ٴν��иö���
void do_session()
{
	string cmd1;
	string sid1;
	mapping tmp=session();
#ifdef DEBUG
	chat("do_session()������","debug");
#endif

	do_session_flag=1;//����������������ʱ����1���˳�������0���� cur_sid�����Ҫ���������

	sid1=(string)cur_sid;//����cur_sid   ���������������
	chat("׼������"+sid1,"new");
	//�ж�cur_sid�Ƿ��Ѿ�����
	if(!mapp(query("session/"+sid1)))
	{
		do_session_flag=0;
		chat("�����Ѿ���ɣ��������������"+sid1+"!","debug");
		return;
	}

	cmd1=tmp[sid1+"/cmd"];
	//Ӧ�ú���һ��TimeOut����
	if(connected)//����Ѿ���������
	{
		chat("�Ѿ�����","debug");
		if(logined)//�����ͨ���˿�����֤�Ļ�
		{
			//�ͳ���������ͷ��ص�sid
			//����״̬Ϊ waiting=1; ��ʱ���Բ��ٵ�������
			waiting=1;
			write_message(sid1+"`"+cmd1);
		}
		else//δͨ����֤��δ������֤�����򷢿���
		{
			//������֤������ڼ�������ܺã�����ȥ����Ϣ���Ժܿ췵��
			if(!waiting)
			{
				write_message(sid1+"`"+password);
			}
			//�Ѿ������˿������ٷ��ͣ�������˴η��Ͷ�ʧ�أ���
		}
	}
	else
	{
		//��ʼ��������
		chat("����������","debug");
		if(do_connect(server_ip+ " " + server_port))
		{
			connected=1;
			buff="";//���յ�����Ϣ�������
			call_out("do_session",1);//���ϼ�������
			return;
		}
		else
		{
			chat("�����޷��������ӡ�","sys");
		}
	}
	call_out("do_session",CK_DELAY);
}


void check_pool()
{
	int tmp_sid,i;
	string *arr1;
	arr1=keys(session());
#ifdef DEBUG
	chat("������������sizeof(session):"+sizeof(arr1)+" do_session_flag="+do_session_flag,"debug");
#endif
	if(sizeof(arr1)>0&&do_session_flag==0)
	{
		//��ʼ���ӻ����������
		//������Ӧ��ѡ�������ĸ�����(keys(session)����С���Ǹ���)
		sscanf(arr1[0],"%d",cur_sid);
		for(i=0;i<sizeof(arr1);i++)
		{
			sscanf(arr1[i],"%d",tmp_sid);
			if(cur_sid > tmp_sid) cur_sid=tmp_sid;
		}
		chat("check_pool������������̣�����"+cur_sid,"debug");
		if(do_session_flag==0)	do_session();//�Ƿ�Ҫ����һ��TimeOut�����أ�
		//����ֹ�ٴε��ûᵼ�½���Խ��Խ�ࣨ��Ը��do_session��Խ��̱�����п���)
	}
	else
	{
		chat("����ִ������:"+(sizeof(arr1)>0)+" " + (do_session_flag==0),"debug");
	}
	call_out("check_pool",CK_DELAY+5);//���ʱ�����ƿ���̫���ˣ�����̫�����������CPU������
	//һ��ŷ����ŵĻ�Ӧ�����ϼ��һ�࣡
}

int add_session(string cmd,object caller)
{
	string str1;
	mapping tmp=([]);
	int sid=make_sid();
	if(add_lock) return 0;//����ס���ܾ�ִ��
	add_lock=1;
	str1=sprintf("%d",sid);
	tmp["object"]=caller;
	tmp["cmd"]=cmd;
	set("session/"+str1,tmp);
	add_lock=0;
	return 1;
}
varargs string show_session(string sid)
{
	string *arr,tmp;
	int i;
	if(!stringp(sid))
	{
		mapping tmps=session();
		arr=keys(tmps);
		i=sizeof(arr);
		tmp="\n";
		if(i>0)
		{
			for(i=0;i<sizeof(arr);i++)
			{
				tmps=query("session/"+arr[i]);
				tmp=tmp+"sid:"+arr[i]+" cmd:"+tmps["cmd"]+ " object:"+sprintf("%O",tmps["object"])+"\n";
			}
		}
		else
			tmp="û������\n";
	}
	else
	{
		//������ʾָ��������

	}
	return tmp;
}




//ÿ����ʼ�������Ӻ�͵����������ʱ���ڵĶϿ����ã�����һ�����ӳ�ʱ�������
int close_socket()
{
	if( connected )
	{
		if( socket_close(my_socket) )
		{
			chat("�ر�socket���ָ�����״̬��\n","debug");
			connected=0;
		}
		else
			chat("�ر�socketʧ�ܡ�\n","debug");
	}
	else
		chat("��û�����ӡ�\n","debug");
	my_socket=0;
	return 1;
}

int do_connect(string arg)
{
	int err;
	if( connected )
		socket_close(my_socket);
	my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
	if ( my_socket < 0 )
	{
		chat("����socketʧ�ܡ�\n","debug");
		return 0;
	}
	err = socket_connect( my_socket, arg , "read_callback","write_callback" );
	if( err==EESUCCESS )
	{
		chat("�Ѿ�����" + arg + "\n","debug");
		connected=1;
	}
	else
	{
		chat("�޷�����" + arg + "��������룺"+err+"\n","debug");
		close_socket();
		return 0;
	}
	return 1;
}

//Ӧ���и�ͳһ�ķַ����������յ�����Ϣ�ַ���ȥ����ȻҲҪ������Ϊ��ʱ�޷���������
void read_callback(int s,mixed message)
{
#ifdef DEBUG
    chat( BOLD + "Զ�˷��أ�" + NOR + message ,"debug");
#endif
	process (message);
	return ;
}

void write_callback(int fd)
{
	int res;
	res = socket_write( fd,"");
	if (res == EESUCCESS || res == EECALLBACK)
		connected=1;
	else
		chat("д��������:"+res,"sys");
}

int write_message(string arg)
{
	if( !arg ) arg="";
	socket_write(my_socket,arg+"\n");
	return 1;
}

void setup()
{
	set("session",([]));
	//����email��麯��
	chat(query("channel_id")+"�������" ,"sys");
	call_out("check_pool",1);
}

void create()
{
	set("channel_id", "�������Ӿ���");
	setup();
}

void chat(string arg,string opt)
{
	CHANNEL_D->do_channel(this_object(),opt,arg);
	return;
}

void start_timeout()
{
	if(timeout_running!=0)
	{
		chat("��ʱ�����Ѿ����У��˳���","sys");
		return;
	}
	chat("��ʱ����������","chat");
	call_out("timeout",1);
}

void timeout()
{
	//����ʣ��ʱ����������Ƿ񻹼����ӳ٣����������ж����ӣ��ָ���ʼ״̬��
	if(sizeof(keys(query("session")))>0)
		chat("�������������ʱdo_session_flagΪ1����ʱ(Ӧ�����������ж�)","sys");
	else
		chat("�����Ѿ�˳�����","sys");
}
