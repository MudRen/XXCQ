/* ע���� v0.1 JackyBoy@CuteRabbit Studio 1999/7/12

ע�����ķ���棬����ʹ��������뷢���ʼ������ǲ���/adm/daemons/emaild.c����ػ�������
*/
#include <mudlib.h>

#ifdef SERVER_NAME
#else
#define SERVER_NAME "202.101.189.4"
#endif

#ifdef SERVER_PORT
#else
#define SERVER_PORT "5555"
#endif

inherit ROOM;

void init()
{
	add_action("do_register","register");
	add_action("do_register","zhuce");
}

int query_regroom()
{
	return 1;
}

string make_password()
{
	string id;
	int i;
	string *source=({"a","b","c","d","e","f","g","h","i",
		"j","k","l","m","n","o","p","q","r","s","t","u","v",
		"w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L",
		"M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
		"0","1","2","3","4","5","6","7","8","9"});
	id="";
	for(i=random(3)+6;i>0;i--)
	{
		id=id+source[random(sizeof(source))];
	}
	return id;
}

int do_register(string dest)
{
	//����������ǿ����ǲ���������register������email�ˣ���Ȼ���δע����Ϳ�������email
	object me,linkob;
	string pass,id_num,msg;
	int i;
	me=this_player(1);
	linkob=me->query_temp("link_ob");
	if(me->query("registered"))
	{
		//��ʱӦ�ý���ȡ���������������������email��ַ��
		dest=linkob->query("email");
	}
	if( !dest||!sscanf(dest,"%*s@%*s.%*s") )
		return notify_fail("�����ʼ���ַ����"+dest+"��\n");
	//������ҵ�ע����Ϣ
	pass=make_password();//�����������
	if(!linkob->set("password", crypt(pass,0) ))
		write("password seting is fail!\n");
	linkob->set("email",lower_case(dest));
	me->set("email",lower_case(dest));
	//����ע���������һ�����ֻ����һ�η��ţ�
	if(me->query("send_reg_email")!=1)
	{
		id_num=read_file(IDUSER,1);
		i=atoi(id_num); 
		i++;
		write("\n���ǵ�"+i+"��ע������ѣ�");
		id_num=sprintf("%d",i);
		write_file(IDUSER,id_num,1);//Ҫ������ȷ��дȨ�ޣ�
		//��inheritĿ¼���ܲ���д����ļ��أ�����
	}
	me->set("startroom","/d/bianliang/guangming");
	me->set("send_reg_email",1);
	me->save();
	linkob->save();
	//����ע���ż�
	write("\n���͵�"+dest+"���ʼ��Ѿ����뷢�Ͷ��У�\n����㲻���յ����ţ�������ע�ᣡ\n");
	msg="\n"+"(ע�⣺���ż������ͬʱ�յ���⣬�������һ��Ϊ׼��)\n\n"+
		me->name(1)+"("+me->query("id")+")����ã���ӭ���١�"+CHINESE_MUD_NAME+"����\n\n"+
		"Ϊ����������ڱ���Ϸ�е�ע����������ʹ�������ṩ�������¼��Ϸ���ע�ᡣ\n\n���ע�������ǣ�"+
		pass+"\n��Ϸ��ַΪ��"+SERVER_NAME+"\n�˿�Ϊ��"+SERVER_PORT+"\n\n"+
		"Ϊ���ʺŲ����������ã����ڵ�¼������ʹ��passwd�����޸�������룺\n"+
		"    passwd�Ĳ�����������ʹ��passwd����passwd -1��ʾ�޸������ʽ���룡\n"+
		"    ʹ��passwd -2���޸���ı������룬Ҳ���������¼ʱʹ�õ����롣\n"+
		"    �������붪ʧ�����ᵼ���㶪ʧ��Ľ�ɫ(ֻҪ��ԭ�����õ�email��ַ����ȷ��)��\n"+
		"    ����ȴ�������������������ʹ�㲻���յ�ע���ż���\n"+
		"������Ѿ�ע�������ʧ���룬������������ʺ�ʱ�ı���������룡Ȼ��������\n"+
		"register����zhuce��������뷢��������䡣\n"+
		"����������ĸ���������Ϣ�����ڰ��������������������ʱ���Զ��������ÿ��\n"+
		"����Ϸ�������������ʱʹ��chfn�����޸ĸ���������Ϣ��\n"+
		"����Ϸ��������ʹ��help�����ȡ��ϸ���������߷��ʱ���Ϸ��ҳ��\n";
	//��Ӧ������һЩ��������Ϸ��Ϣ���Լ������İ�����Ϣ��
	EMAIL_D->add_email("Сѩ����",dest,"ע���ż�!",msg);//δ�ж��Ƿ�ʹ��ָ����smtp
	return 1;
}
