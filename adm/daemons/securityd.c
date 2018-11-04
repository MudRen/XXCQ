// securityd.c
//ע�⣡���ļ����ڽ��ʺ�mirror1��Ȩ�ޣ����ʺ���ʽ���У�
#include <login.h>

mapping wiz_status=([]);//

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

// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in 
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.

mapping trusted_write = ([
	"/": 		({ "Root", "(admin)" ,"(hufa)"}),
	"d":		({ "(arch)" }),
	"data":		({ "(player)" }),
	"kungfu":	({ "(arch)" }),
	"u":        ({"(hufa)","(arch)","(angel)","(wizard)","(apprentice)"}),
	"adm/etc/users":({"(hufa)","(arch)","(angel)","(wizard)","(apprentice)","(immortal)",
					"(player)"}),
	"adm/etc/iduser":({"(hufa)","(arch)","(angel)","(wizard)","(apprentice)","(immortal)",
					"(player)"}),
]);

mapping exclude_write = ([
	"adm" : ({"(hufa)"}),
	"data":	({ "(hufa)"}),
	"log":	({ "(hufa)"}),
	"cmds":({"(hufa)"}),
]);
/*
����ɵ����ã�
A.�ۺ�дȨ�ޣ�
(���������𼶼���)
immortal���κ�дȨ�ޣ�
apprentice,angel,wizard����д�Լ���Ŀ¼
arch����д�Լ���Ŀ¼��/d,/kungfu��/clone
hufa����д��/adm,/log,/data���������Ŀ¼
admin����д��/log,/data���������Ŀ¼(�����ʱ������)
B.�ۺ϶�Ȩ�ޣ�
(��������������)
admin,hufa,arch���Զ�����Ŀ¼(arch���ܶ�/adm, /www)
wizard���Զ�/inherit,/include
angel���Զ�/d,/clone,/kungfu
apprenticeֻ���Զ�/d
c.���ಹ�䣺
����admin��hufa������/u�µ�Ŀ¼���ļ���ÿ����ֻ�ܶ�д�Լ���Ŀ¼��
d.δ��ɵ����룺
��/cmdsҲ����Ȩ�޸�����Ե�readȨ��(������/u)
��ftpd�Ŀɶ�����дȨ��ҲҪ��Щ��Ӧ�Ľ�
*/
mapping trusted_read = ([
	"/": 		({ "Root", "(admin)","(hufa)","(arch)"}),
		//��ζ�⼸�����Զ�/������û�б�exclude_read������Ŀ¼��
	"d":		({ "(wizard)","(angel)","(apprentice)","Domain"}),//Domain����ĸ�����д�д��ĸ
		//"domain"Ϊ/d,/clone,/kungfu�µ�object��euid!
	"kungfu":	({ "(wizard)","(angel)","Domain" }),
	"kungfu/skill" : ({ "(player)" }),//����Ҳ��������ǻ��кܶ�skill�ļ���ʧ��
	"clone":	({ "(wizard)","(angel)","Domain" }),
	"clone/quest" : ({ "(player)","(angel)","(apprentice)","(immortal)"}),
	"inherit" : ({"(wizard)"}),
	"include" : ({"(wizard)"}),
	"doc" : ({"(player)"}),
	"adm/etc/wizlist": ({"(player)"}),
	"data/ladder.txt": ({"(player)"}),
		//��Ϊÿ��update����ļ�ʱ���Լ���Ȩ�ޱ���Ϊ(player),��������Ϊplayer�ɶ���
	"adm/etc/users":({"(hufa)","(arch)","(angel)","(wizard)","(apprentice)","(immortal)",
					"(player)"}),
	"adm/etc/iduser":({"(hufa)","(arch)","(angel)","(wizard)","(apprentice)","(immortal)",
					"(player)"}),
]);

mapping exclude_read = ([
	"adm": ({"(arch)"}),
	"www" : ({"(arch)"}),
	"u" : ({ "(arch)"}), 
		//��Ȼarch����������/u��д�����˵�Ŀ¼����Ȼ����дδ�ز��ã�Ҫ�������߶�Ȩ����
]);


void create()
{
	string *wizlist, wiz_name, wiz_level;
	int i;

	wizlist = explode(read_file(WIZLIST), "\n");
	wiz_status = allocate_mapping(sizeof(wizlist));
	for(i=0; i<sizeof(wizlist); i++) {
		if( wizlist[i][0]=='#' 
		|| sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
		wiz_status[wiz_name] = wiz_level;
	}
}

string *query_wizlist() { return keys(wiz_status); }

// This function returns the status of an uid.
string get_status(mixed ob)
{
	string euid;
	
	if( objectp(ob) ) {
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
	string uid, *wiz, wizlist;
	int i;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if( userp(ob) )			uid = getuid(ob);
	else if(stringp(ob))	uid = ob;
	else return 0;
	
	if( status == "(player)" )
		map_delete(wiz_status, uid);
	else
		wiz_status[uid] = status;
	wiz = keys(wiz_status);
	for(wizlist = "", i=0; i<sizeof(wiz); i++)
		wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
	rm(WIZLIST);
	write_file(WIZLIST, wizlist);
	log_file( "static/promotion", capitalize(uid)
	 + " become a " + status + " on " + ctime(time()) + "\n" );
	return 1;
}

string *get_wizlist() { return keys(wiz_status); }
int valid_read(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

	if( !objectp(user) )
		error("TRUST_D->valid_read: Invalid argument type of user.\n");

	//if( sscanf(file, LOG_DIR + "%*s") && func=="read_file" ) return 1;

	if( func=="restore_object" ) {
		if(sscanf(file,DATA_DIR+"SaveRoom/%*s"))
			return 1;
		if( sscanf(base_name(user), "/clone/%*s")
			&& sscanf(file, "/data/%*s")
			&& file == (string)user->query_save_file()+__SAVE_EXTENSION__  )
                        return 1;
		if( sscanf(file,"/data/board/%*s"))
			return 1;//������������ȡboard����
	}

	// Get the euid and status of the user.
	euid = geteuid(user);
	if( !euid ) return 0;
	status = get_status(user);

	if( euid==ROOT_UID|| euid=="NONAME" ) return 1;
	if((file=="/u/"||file=="/u")&&wiz_level(status)>wiz_level("(immortal)"))
		return 1;

	if( sscanf(file, "/u/" + euid + "/%*s") 
		||file=="/u/"+euid)
		return 1;

	path = explode(file, "/");

	// Check if we are excluded in one of the directories containing the file.
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_read[dir]) ) continue;
		if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
		if( member_array(status, exclude_read[dir])!=-1 ) return 0;
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, trusted_read["/"])!=-1 ) return 1;
	if( member_array(status, trusted_read["/"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_read[dir]) ) continue;
		if( member_array(euid, trusted_read[dir])!=-1 ) return 1;
		if( member_array(status, trusted_read[dir])!=-1 ) return 1;

	}
	if(wizhood(user)!="(player)")
		log_file("wiz_read_fail.log", sprintf("%s(%s) read attempt on %s failed.\n", geteuid(user), wizhood(user), file));
	else
		log_file("read_fail.log", sprintf("%s(%s) read attempt on %s failed.\n", geteuid(user), wizhood(user), file));
	return 0;
}
// valid_write - called by the master object to determine whether if an user
//               is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object. 												- Annihilator

int valid_write(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

	if( !objectp(user) )
		error("TRUST_D->valid_write: Invalid argument type of user.\n");

	if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;
	
	// Let user save their save file
	if( func=="save_object" )
	{
		if( sscanf(file, DATA_DIR+"SaveRoom/%*s") )
      		return 1;
		if( sscanf(base_name(user), "/clone/%*s")
			&&	sscanf(file, "/data/%*s")
			&&	file == (string)user->query_save_file()+__SAVE_EXTENSION__  )
	            return 1;
	    log_file("dpm.log","����洢��\n"+user->name(1)+geteuid(user)+get_status(user)+
	    	"file:"+file+"\n");
	}

	// Get the euid and status of the user.
	euid = geteuid(user);
	if(file == (string)ROOM_D->get_file_name(user))
		return 1;
	if(sscanf(file,DATA_DIR+"SaveRoom/%*s"))
		return 1;
	if( !euid ) return 0;
	if( euid==ROOT_UID || euid=="NONAME") return 1;
	//���ɶ��Ͳ���д add by jackyboy
	if(valid_read(file,user,func)==0)
		return 0;
	status = get_status(user);

	path = explode(file, "/");

	// Check if we are excluded in one of the directories containing the file.
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_write[dir]) ) continue;
		if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
		if( member_array(status, exclude_write[dir])!=-1 ) return 0;
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, trusted_write["/"])!=-1 ) return 1;
	if( member_array(status, trusted_write["/"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_write[dir]) ) continue;
		if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
		if( member_array(status, trusted_write[dir])!=-1 ) return 1;
	}

	log_file("write_fail.log", sprintf("%s(%s) write attempt on %s failed.\n", geteuid(user), wizhood(user), file));
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
