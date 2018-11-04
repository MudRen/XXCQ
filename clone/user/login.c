#include <login.h>

#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;
inherit F_ENCODING;

void logon()
{
	call_out( "time_out", LOGIN_TIMEOUT );
	this_object()->set_temp("loging",1);
	//���������Ϊ1��ʱ��Ӧ�ÿ��Դ��̣�
	//JackyBoy��Դ����Ը�����/feature/save.c���int save()����
	//����ļ�/adm/daemons/logind.c
	LOGIN_D->logon( this_object() );
}

// Don't destruct(this_object()) in the net_dead() interactive apply or
// there'll be error message: Double call to remove_interactive()
//��net_dead()�����ﲻ�ܵ���destruct���ݻ�������
void net_dead()
{
	remove_call_out("time_out");
	call_out( "time_out", 1 );
}

void time_out()
{	
	object body;
	if( objectp(body=query_temp("body_ob"))&&!query_temp("loging")) return;
	//�����query_temp(body_ob)����query_temp(loging)��Ϊ0��˵������ѡ�Ա���ʱ��Ӧ�÷��أ�
	if( interactive(this_object()))
		write("���������߽���������ʱ��̫���ˣ��´���������ɡ�\n");
	write("ϵͳkickout���ˡ�\n");
	destruct(this_object());
}

// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
	string id;

	id = query("id", 1);
	if( !stringp(id) ){
		CHANNEL_D->do_channel(this_object(),"sys","login.c : query fail!"+id);	
		return 0;
	}
	return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}

void receive_message(string type, string str)
{
	if( type!= "write" ) return;
	str = CONVERT_D->output(str,this_object());
	receive(str);
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
}

// Protect login object's data against hackers.
// ���ڻ��ǲ����ģ�������©�����������ô����ļ�Ȼ��save
nomask mixed set(string prop, mixed data)
{
	if( geteuid(previous_object()) != ROOT_UID ) 
	{
		write("login set is error!"+geteuid(previous_object())+"\n");
		return 0;
	}
	return ::set(prop, data);
}
