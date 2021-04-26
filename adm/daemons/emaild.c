//�����ʼ��ػ�����v0.1�汾   ��д��JackyBoy@CuteRabbit Studio 1999/7/11

/*
������չ�Ĺ��ܣ���MUD�ڵ����ֱ�ӷ���ת���������ҵ���ʵemail���ţ�
������ͬϵ�е�MUD���໥�������ʼ���
һЩ����˵����
email���ԣ�
	������������ʼ�����һ��mapping���͵����ԣ���������ʵʱ������־���ܵ�һ����
	��������һ��mapping�����ģ�
		rctp_to �Է����ʼ���ַ
		mail_from �����ߵ��ʼ���ַ
		subject �ż�������
		msg �ż�������
		smtp ���÷����ż���SMTP����������ʡ��

*/

//����Ƿ��д����ʼ��ļ��ʱ�䣬����Ϊ��λ
#define CK_DELAY 60*1

#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>

inherit F_SAVE;
inherit F_DBASE;
//��������ʹ�õ�socket�źͷ��ͱ�־
nosave int my_socket,status=0,scount=0;
//ȱʡ�ķ����ʼ���������ַ
nosave mapping d_smtp=([
	"ip":"202.96.104.8",
	"port":"25",
	"name":"pub.cnnb.net",
	]);
//��ʽʹ�õķ����ʼ���������ַ
nosave mapping smtp;
//�ʼ����ռ��ˣ������ˣ��������Ϣ��
nosave string rcpt_to,mail_from,subject,msg,en;

int write_message(string);

string query_save_file()
{
	return __DIR__"emaild.o";
}

void setup()
{
	restore();
	//���ó�ʼֵ

	//����email��麯��
	call_out("check_email",1,this_object());
}

void create()
{
	set("channel_id", "�����ʼ�����");
	setup();
}

void chat(string arg,string opt)
{
	CHANNEL_D->do_channel(this_object(),opt,arg);
	return;
}

int add_email(string m_from,string r_to,string title,string msg,mixed smtp)
{
	string tmp_en;
	mapping tmp_em;

	tmp_em=([]);
	//Ӧ�ü���ַ����Ϣ�ĺϷ��ԣ�
	tmp_en=CHINESE_D->chinese_time(5,ctime(time()));
	if(query("email/"+tmp_en))
	{
		//�����������ͬ����Ŀ�ˣ����ӳ�60���ٳ���
		call_out("add_email",60+random(5),m_from,r_to,title,msg,smtp);
		return 1;
	}
	tmp_em["mail_from"]=m_from;
	tmp_em["rcpt_to"]=r_to;
	tmp_em["subject"]=title;
	tmp_em["msg"]=msg;
	if(mapp(smtp))
		tmp_em["smtp"]=smtp;
	set("email/"+tmp_en,tmp_em);
	save();
	return 1;
}

int delete_email(string tmp_en,int opt)
{
	mapping tmp_em;
	chat("ɾ���ʼ�������"+tmp_en+"\n","debug");
	if(!tmp_en)
		return 0;
	if(opt)
	{
		if(!tmp_em=query("email/"+tmp_en))
			log_file("emaild.log","��ɾ�������ڵ��ʼ���"+tmp_en+"\n");
		else
			log_file("emaild.log","ɾ���ʼ���\n"+
				"Mail From: "+tmp_em["mail_from"]+"\n"+
				"RCPT To:   "+tmp_em["rcpt_to"]+"\n"+
				"Subject:   "+tmp_em["subject"]+"\n"+
				"Smtp Server:"+smtp["name"]+"("+smtp["ip"]+")"+" Port:"+smtp["port"]+"\n"+
				"MSG:\n"+tmp_em["msg"]+"\n");
	}
	delete("email/"+tmp_en);
	return 1;
}

int close_socket()
{
	if( query("connected") )
	{
		if( socket_close(my_socket) )
		{
			chat("�ر�socket���ָ�����״̬��\n","debug");
			delete("connected");
		}
		else
			chat("�ر�socketʧ�ܡ�\n","debug");
	}
	else
		chat("��û�����ӡ�\n","debug");
	if(!delete_email(en,0))
		chat("ɾ���ʼ�����!\n","sys");
	en=0;//stringp�����ֵ������ж��أ�
	status=0;//�����ţ�����Щֵ���³�ʼ��
	my_socket=0;
	chat("��������enΪ��"+en+"\n","debug");
	save();
	return 1;
}

int do_telnet(string arg)
{
	int err;
	if( query("connected") )
		socket_close(my_socket);
	my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
	if ( my_socket < 0 )
	{
		chat("����socketʧ�ܡ�\n","debug");
		return 1;
	}
	err = socket_connect( my_socket, arg , "read_callback","write_callback" );
	if( err==EESUCCESS )
	{
		chat("�Ѿ�����" + arg + "\n","debug");
		set("connected",1);
	}
	else
	{
		chat("�޷�����" + arg + "\n","debug");
		close_socket();
	}
	return 1;
}


void read_callback(int ,mixed message)
{
    chat( BOLD + "Զ�˷��أ�" + NOR + message ,"debug");
    switch(status)
    {
    	case 0:
    		if(sscanf(message,"220%*s"))
    		{
    			status++;
    			write_message("HELO " +smtp["name"] );
    			return;
    		}
    		break;
    	case 1:
    		if(sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("MAIL FROM:<"+mail_from+">");
    			return ;
    		}
			break;
    	case 2:
    		if(sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("RCPT TO:<"+rcpt_to+">");
    			return ;
    		}
    		break;
    	case 3:
    		if(sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("DATA");
    			return;
    		}
    		break;
    	case 4:
    		if(sscanf(message,"354%*s"))
    		{
    			status++;
    			if(sscanf(msg,"%*s\r\n.\r\n%*s"))
    			{
    				chat("���ڷ��͵��ʼ������Ƿ����ݣ����ܻ��޷����͡�\n","sys");
    				log_file("emaild","\n��ͼ�������ݣ�\n"+
    					smtp["name"]+"("+smtp["ip"]+")"+smtp["port"]+"\n"+msg+"\n");
    			}
    			write_message(msg+"\n.\n");
    			return;
    		}
    		break;
    	case 5:
    		if(sscanf(message,"451%*s"))
    			chat("Smtp Server�������ݳ�������ѡ��������\n","sys");
    		else
    			chat("�ż��Ѿ���ȷ������!\n","debug");
    		break;
    }
    if(status!=5||!sscanf(message,"250%*s"))
    	chat("���ͳ���","sys");
    status=0;
	write_message("QUIT");
	close_socket();
	return ;
}

void write_callback(int fd)
{
	int res;
	if(query("connect"))return ;
	res = socket_write( fd,"");
	if (res == EESUCCESS || res == EECALLBACK)
		set("connected",1);
}

int write_message(string arg)
{
	if( !arg ) arg="";
	socket_write(my_socket,arg+"\n");
	return 1;
}
void send_email()
{
	mapping email;
	string ATTACH;

	if(!stringp(en))
		return;
	if(!email=query("email/"+en))
	{
		close_socket();
		chat("�����ʼ���ʧ�����ͼ�¼��Ϊ��"+en+"\n","sys");
		log_file("emaild.log","�����ʼ���ʧ�����ͼ�¼��Ϊ��"+en+"\n");
		return;
	}
	ATTACH="\n\n" +
		"Сѩ���ߵ�ַ��202.101.189.4 5555\n"+
		"              10.104.4.4 5555\n"+
		"              10.163.179.201 5555\n"+
		"Сѩ������վ��ҳ ��http://www.snowmud.com\n" +
		"���ֵı���MUD��http://mud.yn.cninfo.net/jackyboy\n" +
		"               http://www.lhmz.yn.cninfo.net/jackyboy\n\n" +
		"                                    " +
		"Сѩ������ʦ����\n���ʼ��ɡ�"+CHINESE_MUD_NAME+"�������ʼ�ϵͳ����!\n"+
		"�ż��ύʱ�䣺"+en+"\n"+
		"�ż�����ʱ�䣺"+CHINESE_D->chinese_time(0,(string)localtime(time()));

	rcpt_to=email["rcpt_to"];
	subject=email["subject"];
	mail_from=email["mail_from"];
	msg=email["msg"];
	msg="FROM:"+CHINESE_MUD_NAME+"<jackyboy@126.com>\n"+
		"TO:"+rcpt_to+"\n"+
		"SUBJECT:"+subject+"��"+CHINESE_MUD_NAME+"��\n"+
		"MIME-Version:1.0\n"+
		"DATE:"+time()+"\n"+
		"X-MAILER:LPMUD�����ʼ�����v0.1\n"+"\n"+msg+ATTACH;
	//�����ʼ���������ַ��
	smtp=(mapp(email["smtp"]))?email["smtp"]:d_smtp;
	//׼����ʼtelnet���ʼ�
	if(!my_socket&&do_telnet(smtp["ip"]+" "+smtp["port"])==0)
	{
		chat("�ظ��������ӻ����޷������ʼ���������\n"+
			smtp["name"]+"("+smtp["ip"]+")"+" �˿�"+smtp["port"]+"\n","sys");
		close_socket();
		return;
	}
	else
		chat("ϵͳ��Ȼ��������״̬��\n","debug");//Ӧ���������Ӵ����ͳ�ʱ����
	return ;
}


void check_email()
{
	string *earray;
	if(en!=""&&stringp(en))
	{
		//Ӧ�ü�¼ʧ�ܴ��������60����û�з��ųɹ���ȥ����
		if(++scount>20)
			close_socket();//��ʱ����ż���ʧ��
		else
		{
			chat("���ڷ���("+en+")���Ⱥ�...\n","sys");
			call_out("check_email",6,this_object());
		}
		return;
	}
	scount=0;//����δ�ɹ�����
	if(!query("email"))//���û���ʼ��������ڷ��ţ���CK_DELAY����ټ��
	{
		chat("�޵����ʼ�!\n","sys");
		call_out("check_email",CK_DELAY,this_object());
		return;
	}
	earray=keys(query("email"));
	if(sizeof(earray)<1)
	{
		call_out("check_email",CK_DELAY,this_object());
		return;
	}
	en=earray[0];//ʹ��en��Ϊ�����ʼ���־���������ﲻһ��Ҫ0�ģ����������ȷ���������ţ�
	chat("��ʼ�������ʼ�:"+en+"\n","debug");
	status=0;
	send_email();
	call_out("check_email",10,this_object());
	//һ��ŷ����ŵĻ�Ӧ�����ϼ��һ�࣡
}
