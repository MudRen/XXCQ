
// ��ȫϵͳv0.1 Write By JackyBoy@CuteRabbit Studio for CCTX & SDXL
// ע�⣺
// �������������ȷ������Ȩ�޵�����²ſ�����ȷʹ�ã�һ��Ȩ�޷������ͻ����ϵͳ�޷�����
// ��ʱ��ֻ���ֶ����Ĵ洢�ļ�������û���ɾ�����ļ��ſ����ٴ�������
// ���ԣ�����ֻ�п��Ե�¼�������û��ſ���ʹ�øð�ȫϵͳ������
// ��Ȼ�������ṩ��������Ȩ�����÷��������ǽ���Ҫ��һ��ԭ����ϵͳ�İ�ȫ����
// ��д�ڣ�1999/7/14
// 7/15�޸ģ���Ȩ�������޸�Ϊ����һ�����ö����Ȩ��#include <login.h>

inherit F_DBASE;
inherit F_SAVE;

static mapping wiz_status=([]);//

string *wiz_levels = ({
	"(player)",
	"(immortal)",
	"(apprentice)",
	"(angel)",
	"(wizard)",
	"(arch)",
	"(hufa)",
	"(admin)"
});

//��ʼ����Ϊ�գ�Ȼ����create()��ʱ��������ļ����ȡ����
static mapping trusted_write = ([]);
mapping exclude_write = ([]);
static mapping trusted_read = ([]);
static mapping exclude_read = ([]);

string query_save_file()
{
	return __DIR__"securd.o";
}

void restore_list()
{
	//������������Ե���modify_access_list()�����������ѭ����
	string *t_read,*t_write;
	string *e_read,*e_write;
	//Ԥ�������ţ���Ȼ�޷���ϵͳ������ʦ������һ��Ҫ��֤���������Ȼ�ȡ���ID
	set("wiz_status/jackyboy","(admin)");
	// "/" �ǱȽ������Ŀ¼��һ��Ҫ����Root��(admin)��ȡ��д�룡
	// ����ͬʱ��Ҫע����һЩ�����ǲ�����exclude�ģ�����Root��/�Ķ�д��Domain��/d�Ķ�ȡ�ȵ�
	// ��ЩӦ���ô�����Ʋ��ɸı䣬Ȼ���������С���Ŀ�������������admin������Ȩ�޷��䣡
	// �����ĸ����Ա�������Ϊ�գ�������valid_read��valid_write����ʱ����������������
	// ��������һЩĬ�ϵ�ֵ!exclude������Ĭ�����ã����ǿ��Զ�����(player)�����Զ�д"/"������
	// ��������Ͳ�����ģ�(��Ȼ���࣬ȴ���ǻ������㣡)
	t_read=query("trusted_read/\n");
	t_write=query("trusted_write/\n");
	if(sizeof(t_read))
	{
		t_read=t_read - ({ROOT_UID});
		t_read=t_read - ({"(admin)"});
		t_read=t_read + ({ROOT_UID,"(admin)"});
	}
	else
		t_read=({ROOT_UID,"(admin)"});
	if(sizeof(t_write))
	{
		t_write=t_write - ({ROOT_UID});
		t_write=t_write - ({"(admin)"});
		t_write=t_write + ({ROOT_UID,"(admin)"});
	}
	else
		t_write=({ROOT_UID,"(admin)"});
	set("trusted_read/\n",t_read);
	set("trusted_write/\n",t_write);
	
	e_read=query("exclude_read/\n");
	e_write=query("exclude_write/\n");
	if(sizeof(e_read))
	{
		e_read=e_read - ({"(player)"});
		e_read=e_read + ({"(player)"});
	}
	else
		e_read=({"(player)"});
	if(sizeof(e_write))
	{
		e_write=e_write - ({"(player)"});
		e_write=e_write + ({"(player)"});
	}
	else
		e_write=({"(player)"});
	set("exclude_read/\n",e_read);
	set("exclude_write/\n",e_write);
	
	wiz_status = query("wiz_status");
	trusted_write = query("trusted_write");
	trusted_read = query("trusted_read");
	exclude_write = query("exclude_write");
	exclude_read = query("exclude_read");
	return ;
}

void save_list()
{
	set("trusted_write",trusted_write);
	set("trusted_read",trusted_read);
	set("exclude_write",exclude_write);
	set("exclude_read",exclude_read);
	return ;
}

int save()
{
	save_list();
	return ::save();
}

//�û��ӿڳ��򣬸������Ȩ���б�
string print_access_list(object user,string type)
{
	string str,file,*acc;
	if(wiz_level(user)<wiz_level("(hufa)"))
		return "Ȩ�޲����޷���ȡAccess_List!\n";
	str="Ȩ�޴�ȡ�б����£�\n";
	if(type=="all"||type=="exclude_read")
	{
		str+="���ų���>>\n";
		if(sizeof(exclude_read))
			foreach(file in keys(exclude_read))
			{
				acc=exclude_read[file];
				file=replace_string(file,"\n","/");
				str+=file+"\t: "+implode(acc,",")+"\n";
			}
	}
	if(type=="all"||type=="trusted_read")
	{
		str+="�����α�>>\n";
		if(sizeof(trusted_read))
			foreach(file in keys(trusted_read))
			{
				acc=trusted_read[file];
				file=replace_string(file,"\n","/");
				str+=file+"\t: "+implode(acc,",")+"\n";
			}
	}
	if(type=="all"||type=="exclude_write")
	{
		str+="д���ų���>>\n";
		if(sizeof(exclude_write))
			foreach(file in keys(exclude_write))
			{
				acc=exclude_write[file];
				file=replace_string(file,"\n","/");
				str+=file+"\t: "+implode(acc,",")+"\n";
			}
	}
	if(type=="all"||type=="trusted_write")
	{
		str+="д�����α�>>\n";
		if(sizeof(trusted_write))
			foreach(file in keys(trusted_write))
			{
				acc=trusted_write[file];
				file=replace_string(file,"\n","/");
				str+=file+"\t: "+implode(acc,",")+"\n";
			}
	}
	return str;
}

//�û��ӿڳ��򣬸���ά��Ȩ���б�access_list
int modify_access_list(object user,string op,string type,string file,string *acc_user)
{
	string *acc;
	int i;
	if(!file||!sizeof(acc_user))
		return 0;
	if(wiz_level(user)!=wiz_level("(admin)"))//ֻ����Adminά���б�
		return 0;
	file=replace_string(file,"/","\n");//���ļ����б����������Ȼ·����"/"��mapping��"/"������
	switch(op)
	{
		case "add":
			switch(type)
			{
				case "trusted_read":
				case "trusted_write":
				case "exclude_read":
				case "exclude_write":
					sscanf(file,"/%s",file);//�������һ��/����
					acc=query(type+"/"+file);
					if(sizeof(acc))
					{
						for(i=sizeof(acc_user);i>0;i--)
						{
							acc=acc - ({acc_user[i-1]});
							acc=acc + ({acc_user[i-1]});
						}
					}
					else
						acc= acc_user;
					set(type+"/"+file,acc);
					break;
				default:
					//����ʶ�������
					return 0;
			}
			break;
		case "del":
			switch(type)
			{
				case "trusted_read"://
				case "trusted_write":
				case "exclude_read":
				case "exclude_write":
					sscanf(file,"/%s",file);//�������һ��/����
					acc=query(type+"/"+file);
					if(sizeof(acc))
					{
						for(i=sizeof(acc_user);i>0;i--)
							acc=acc - ({acc_user[i-1]});
					}
					if(sizeof(acc))
						set(type+"/"+file,acc);
					else
						delete(type+"/"+file);
					break;
				default:
					//����ʶ�������
					return 0;
			}
			break;
		default:
			//Ȩ�����ò�������ʶ��
			return 0;
	}
	save();
	restore_list();
	return 1;
}

void create()
{
	//��wizlist�����ﴢ�棬��������/adm/etc/wizlist��洢��
	set("channel_id","��ȫ����");
	restore();
	restore_list();	
}

string *query_wizlist() { return keys(wiz_status); }

// �����������һ��uid����obj��status
string get_status(mixed ob)
{
	string euid;
	if( objectp(ob) ) 
	{
		euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
	}
	else if( stringp(ob) ) euid = ob;
	if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
	else if( member_array(euid, wiz_levels)!=-1 ) return euid;
	else return "(player)";
}

int get_wiz_level(mixed ob)
{
	return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string status)
{
	string uid;

	//Ӧ�ü��һ��status�Ƿ��ʽ��ȷ��
	if( geteuid(previous_object())!= ROOT_UID)
		if(!wiz_level(previous_object())>wiz_level("(arch)"))//����arch,hufa������ʦ��
			return 0;
	//����ط�Ӧ���ϸ�����Ƿ���Ȩ��������������
	if( objectp(ob)&&userp(ob) )	
		uid = getuid(ob);
	else 
		if(stringp(ob))
			uid = ob;
		else
		{
			CHANNEL_D->do_channel(this_object(),"sys","�Ƿ�������ʦ����"+ob+" "+status+"\n");
			return 0;
		}
	if( status == "(player)" )
		map_delete(wiz_status, uid);
	else
		wiz_status[uid] = status;
	set("wiz_status",wiz_status);
	save();
	log_file( "static/promotion", capitalize(uid)
	 + " ��Ϊ " + status + " ʱ�䣺" + CHINESE_D->chinese_time(5,ctime(time())) + "\n" );
	return 1;
}

string *get_wizlist() { return keys(wiz_status); }

int valid_read(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;
	if( !objectp(user) )
		error("SECURITY_D->valid_read: user���������ֵ�Ƿ���\n");
	//�������������뷵��1
	if(func == "file_size" || func == "stat")
		return 1;

	// ȡ���û���euid��status
	euid = geteuid(user);
	status = get_status(user);
	//"NONAME"��ϵͳ������ʱ����������������Ӧ���ǰ�ȫ��
	//������Ҳ�ǽ�����û���˿����Լ������Լ���euid��������ϵġ�
	if( euid==ROOT_UID|| euid=="NONAME" ) return 1;
	//immortal���ϵĲſ��Խ���/uĿ¼��
	if(status == "(admin)")
		return 1;
	// Modify By JackyBoy
	if(file==query_save_file()) return 1;//���������Ĵ洢�ļ������κ��˶����Զ�ȡ��
	if( func=="restore_object" || func=="save_object" ) {
		if(sscanf(file,DATA_DIR+"SaveRoom/%*s"))
			return 1;
		if( sscanf(base_name(user), "/clone/%*s")
			&& sscanf(file, "/data/%*s")
			&& file == (string)user->query_save_file()+__SAVE_EXTENSION__  )
                        return 1;
		if( sscanf(file,"/data/board/%*s"))
			return 1;//������������ȡboard����
	}
	if( !euid )
	{
		log_file("read_fail.log","û��euid to read "+file+" with "+func+"\n");
		return 0;
	}
	path=explode(base_name(user),"/");
	if(arrayp(path))
	{
		if(sizeof(path)>1)
			dir="/"+implode(path[0..(sizeof(path)-2)],"/");
		else
			dir="/";
		//log_file("test","�ж�"+dir+"  "+file+"\n");
		if(sscanf(file,dir+"%*s"))
			return 1;
	}

	if((file=="/u/"||file=="/u")&&wiz_level(status)>wiz_level("(immortal)"))
		return 1;
	//����/u�µĿ��Զ��Լ���Ŀ¼��
	if( sscanf(file, "/u/" + euid + "/%*s") 
		||file=="/u/"+euid)
		return 1;

	path = explode(file, "/");

	// �����ų�������ų��ˣ���ֱ�ӷ���1����������жϣ�
	// ���ڱ���Ĺ�ϵ��"/"��"\n"ȡ����
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "\n");
		//�˴����exclude_readΪ�վͳ���
		if( undefinedp(exclude_read[dir]) ) continue;
		if( member_array(euid, exclude_read[dir])!=-1 )
		{
			log_file("read_fail.log","euid���ų����"+euid+":"+exclude_read[dir]+"\n");
			return 0;
		}
		if( member_array(status, exclude_read[dir])!=-1 )
		{
			log_file("read_fail.log","status���ų����"+status+":"+exclude_read[dir]+"\n");
			return 0;
		}
	}

	// �������α���������򷵻�1������ʧ��
	if( member_array(euid, trusted_read["\n"])!=-1 ) return 1;
	if( member_array(status, trusted_read["\n"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "\n");
		if( undefinedp(trusted_read[dir]) ) continue;
		if( member_array(euid, trusted_read[dir])!=-1 ) return 1;
		if( member_array(status, trusted_read[dir])!=-1 ) return 1;
	}
	if(wizhood(user)!="(player)")
		log_file("wiz_read_fail.log", sprintf("%s(%s) ��ͼԽȨ��ȡ %s ��\n", 
			geteuid(user), wizhood(user), file));
	else
	log_file("read_fail.log", sprintf(CHINESE_D->chinese_time(6,ctime(time()))+"%s(%s) ��ͼ���� %s ʧ�ܡ�������"+func+"\n", 
			geteuid(user), wizhood(user), file));
	return 0;
}

int valid_write(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

	if( !objectp(user) )
		error("SECURITY_D->valid_write: ����user��ֵ�Ƿ���\n");
	// Get the euid and status of the user.
	euid = geteuid(user);
	if( !euid ) return 0;
	status = get_status(user);
	//��ߵ�Ч��
	if(status=="(admin)")
		return 1;
	if( euid==ROOT_UID || euid=="NONAME") return 1;
	if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;
	//���ɶ��Ͳ���д add by jackyboy
	if(valid_read(file,user,func)==0)
		return 0;
	// ���û��Ϳɴ洢�����ܴ洢�Լ���
	// �������ʹ���������㷨�����USERP(user)����ô���file==user->query_save_file()�Ϳ���д��
	if( func=="save_object" )
	{
		if( sscanf(file, DATA_DIR+"SaveRoom/%*s") )
      		return 1;
		if( sscanf(base_name(user), "/clone/%*s")
			&&	sscanf(file, "/data/%*s")
			&&	file == (string)user->query_save_file()+__SAVE_EXTENSION__  )
	            return 1;
		path=explode(base_name(user),"/");
		if(arrayp(path))
		{
			if(sizeof(path)>1)
				dir="/"+implode(path[0..(sizeof(path)-2)],"/");
			else
				dir="/";
			log_file("test","�ж�"+dir+"  "+file+"\n");
			if(sscanf(file,dir+"%*s"))
				return 1;
		}
	}

	if(file == (string)ROOM_D->get_file_name(user))
		return 1;
	if(sscanf(file,DATA_DIR+"SaveRoom/%*s"))
		return 1;

	path = explode(file, "/");

	// ���д�ų���������ų��򷵻�0����������ж�
	// ����Ĺ�ϵ����"/"���������"\n"�ϲ��жϣ�
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "\n");
		if( undefinedp(exclude_write[dir]) ) continue;
		if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
		if( member_array(status, exclude_write[dir])!=-1 ) return 0;
	}

	// ��������α���������򷵻�1����������д��
	if( member_array(euid, trusted_write["\n"])!=-1 ) return 1;
	if( member_array(status, trusted_write["\n"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "\n");
		if( undefinedp(trusted_write[dir]) ) continue;
		if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
		if( member_array(status, trusted_write[dir])!=-1 ) return 1;
	}

	log_file("write_fail.log", sprintf(CHINESE_D->chinese_time(6,ctime(time()))+"%s(%s) ��ͼд�� %s ʧ�ܡ�\n", geteuid(user), wizhood(user), file));
	return 0;
}

int valid_seteuid( object ob, string uid )
{
	if( uid==0 ) return 1;
	if( uid==getuid(ob) ) return 1;
	if( getuid(ob)==ROOT_UID ) return 1;
	if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
	if( wiz_status[uid] != "(admin)"
	&&	wiz_status[getuid(ob)] == "(admin)" )
		return 1;
	return 0;
}

