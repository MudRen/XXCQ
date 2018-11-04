 
// objmaker.c created by Hunter(���) 
// for ESLib 
 
#define RMK_VERSION "(v1.0)" 
 
inherit ITEM; 
inherit F_AUTOLOAD; 
 
string *special_props = ({ 
        "name", "long" }); 
 
int save_room_file(string file,string str); 
 
void create() 
{ 
        set_name("����༭��" + RMK_VERSION, ({ "objmaker", "maker" }) ); 
        set_weight(100); 
        set("unit", "��" ); 
        set("long", @LONG 
����һ�����������١����췿��Ĺ��ߣ�����ʱ�䲻���������  lag ����ʦ 
����������������򵥵ķ��䣬���������������Լ����򷿼��Ʒ�ʣ���� 
��Ҫ̫������������������ʹ�����¼���ָ� 
 
mkobj <�������> 
 
    ���һ��������������ϣ�֮������� rrset �趨�����    ������ 
���ԡ� 
 
rset1 <�������> <��������> 
 
    �趨�����ϵ���ʱ������ԣ��� name(not short!)��long,id �� set �� 
�����ŵ�set �� 
 
 
saveobj 
 
    �������ϵ���ʱ����浵Ϊ��ʽ����� 
 
rset2 <�������> <��������> 
        �趨��Щ set ��û�����ŵ����ԣ��� no_drop,no_get,value�ȡ� 
LONG 
        ); 
} 
 
int query_autoload() { return 1; } 
 
void init() 
{ 
        if( wizardp(environment()) ) { 
                seteuid(getuid(environment())); 
                add_action("do_mkobj", "mkobj"); 
                add_action("do_rset", "rset1"); 
                add_action("do_saveobj", "saveobj"); 
                add_action("do_rrset","rset2"); 
        } 
} 
 
int do_mkobj(string arg) 
{ 
        string file,code; 
        object file1; 
 
        if( sscanf(arg, "%s", file)!=1 ) 
return notify_fail("ָ���ʽ��mkobj <�������>\n"); 
        seteuid(geteuid(this_player())); 
        file = resolve_path(this_player()->query("cwd"), file) + ".c"; 
        if( file_size(file)!=-1 ) 
                return notify_fail("���� " + file + " �Ѿ������ˡ�\n"); 
        if( !write_file(file ,@OBJ_CODE 
// This is a obj made by objmaker. 
 
inherit ITEM; 
 
void create() 
{ 
       set_name("������", ({ "obj" }) ); 
        set("long", "����һ����ֵǮ�ķ��\n"); 
        setup(); 
} 
 
OBJ_CODE 
        ) ) return notify_fail("��û��д�뵵��(" + file +")��Ȩ����\n"); 
        file1=new(file); 
        file1->move(this_player()); 
        message_vision("ֻ����$N������༭�����١���һ������������϶���һ��������\n", this_player()); 
        return 1; 
} 
 
int do_rset(string arg) 
{ 
        string prop, str; 
        object ob; 
        mixed data; 
 
        if( !arg || sscanf(arg, "%s %s", prop, str)!=2 ) 
                return notify_fail("ָ���ʽ��rset1 <�������> <��������>\n"); 
 
        if( sscanf(str, "%d", data)!=1 ) 
                data = str; 
        ob=present("obj",this_player()); 
        ob->set(prop,str); 
//      environment(this_player())->set(prop, str); 
        write("Ok.\n"); 
        return 1; 
} 
 
int do_rrset(string arg) 
{ 
        string prop; 
        object ob; 
        mixed str; 
 
        if( !arg || sscanf(arg, "%s %d", prop, str)!=2 ) 
                return notify_fail("ָ���ʽ��rset2 <�������> <��������>\n"); 
 
/*      if( sscanf(str, "%d", data)!=1 ) 
                data = str;*/ 
        ob=present("obj",this_player()); 
        ob->set(prop,str); 
//      environment(this_player())->set(prop, str); 
        write("Ok.\n"); 
        return 1; 
} 
 
int do_saveobj(string arg) 
{ 
        object env; 
        string str, *name1, file1,file; 
        mapping prop; 
        int i,age1; 
        env = present("obj",this_player()); 
        file1 = file_name(env) + ".c"; 
        if( !arg || sscanf(arg, "%d",age1)!=1 ) 
                return notify_fail("ָ���ʽ��saveobj <����>\n"); 
        str = "// Obj: "+file1 +  @OBJ_CODE 
 
 
inherit ITEM; 
 
void create() 
{ 
OBJ_CODE 
        ; 
        str += sprintf("\tset_name(\"%s\", ({\"%s\"}));\n", env->query("name"),env->query("id")); 
        str += sprintf("\tset(\"long\", @LONG\n%s\nLONG\n\t);\n", env->query("long") ); 
        prop = env->query_entire_dbase(); 
        name1 = keys(prop); 
        for(i=0; i<sizeof(name1); i++) { 
                if( member_array(name1[i], special_props)!=-1 ) continue; 
                str += sprintf("\tset(\"%s\", %O);\n", name1[i], prop[name1[i]] ); 
        } 
        str += sprintf("\tset_weight(%O);\n",age1); 
        str += "\n\tsetup();\n}\n"; 
 
        // Replace current directory with __DIR__ macro to make relocatable code. 
/*      if( file_size(file)!=-1 ) { 
                write("���� " + file + " �Ѵ��ڣ�Ҫɾ���ɵ���[y/n]"); 
                input_to("save_room_file",file,str); 
                return 1; 
        }*/ 
 
//      return save_room_file("y",file,str); 
        write("�������µ���: "); 
        input_to("save_room_file",str); 
        return 1; 
} 
 
int save_room_file(string file,string str) 
{ 
        object ob; 
        file = resolve_path(this_player()->query("cwd"), file) + ".c"; 
 
//      if( wizardp(environment()) ) { 
        ob=present("obj",this_player()); 
//              seteuid(getuid(environment())); 
                seteuid(getuid(ob)); 
 
//      if( strlen(yn)<1 || yn[0]!='y' ) return 1; 
        rm(file); 
        printf(str); 
        write("�浵 " + file + "...."); 
        if( write_file(file, str) ) { 
                write("Ok.\n"); 
                return 1; 
        } else 
                return notify_fail("��û��д���������(" + file + ")��Ȩ����\n"); 
} 
 
void owner_is_killed() { destruct(this_object()); } 
 
 
