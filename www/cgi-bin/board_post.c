#include <mudlib.h>
#include <net/config.h>
#include <ansi.h>
#include <net/dns.h>
#include <net/httpd.h>

#define BOARD_CAPACITY 1024
#define BOARD_PATH "/clone/board/"

inherit F_SAVE;
inherit F_DBASE;

private mapping *notes;

string result(string);

void create();
void setup();
void post(string,string,string,string);

string gateway(string);
private string HTML_encode(string);
int tochinese(string,int);

void create() {
	seteuid( geteuid() );
}

void setup() {
	restore();
}

string query_save_file()
{
	string id;
	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string gateway(string args) {
	object ob;
	string id,pass,password,title,text,board;
	mapping vaild_boards;

	if( !args ) return result("��������ñ��");

	if( sscanf(args,"board=%s?id=%s&pass=%s&title=%s&text=%s",
					board,id,pass,title,text) != 5 )
		return result("��������ñ��");

	vaild_boards = ("/www/cgi-bin/board_list.c")->query_boards();
	if( undefinedp(vaild_boards[board]) )
		return result("��������ñ��");

	if( !vaild_boards[board][1] )
		return result( sprintf("%s��ֻ���ͣ����ܷ������¡�",vaild_boards[board][0])	);

	ob = new(LOGIN_OB);
	ob->set("id", id);
	if(ob->query("id")!=id)
		HTTP_DEBUG("ID���ô����û���WEB������ʧ�ܣ�");
	if( !ob->restore() )
		return result("û��������"+id+"����δ���ױ��");

	password = ob->query("password");
	if( crypt(pass, password) != password )
		return result("������󣬻�δ���ױ��");
	post( board,sprintf("%s(%s)",ob->query("name"),id),HTML_encode(title),HTML_encode(text) );
	destruct(ob);

	return result("������ϡ�");
}

string result(string str)
{

 return sprintf( @EndFormat
<HTML>
<HEAD>
<TITLE>%s</TITLE>
</HEAD>
<body>
%s
</BODY>
</HTML>
EndFormat
        , CHINESE_MUD_NAME,str,

    );
}
private string HTML_encode(string str) 
{
	string retval = "";
	int len = strlen(str);

	for(int i=0; i<len; i++)
		{
		switch(str[i])
			{
				case '%':
					retval +=" ";
					retval[strlen(retval)-1] = tochinese(str,i+1);
					i+=2;
					break;
    				case '&':
					retval += "&amp;";
					break;
				case '+':
					retval += " ";
					break;
				case '?':
					retval += "��";
					break;
				case '<':
					retval += "&lt;";
					break;
				case '>':
					retval += "&gt;";
					break;
				case '"':
					retval += "&quot;";
					break;
				default:
					retval += str[i..i];
					break;
			}
	}
	return retval;
}

void post(string id,string who,string title,string text)
{
	mapping note;
	set("board_id",id);
	setup();

	notes = query("notes");
	note = allocate_mapping(4);
	note["title"] = title;
	note["author"] = who;
	note["msg"] = text;
	note["time"] = time();

	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

	set("notes", notes);
	save();

	(BOARD_PATH+id)->setup();
	return;
}

int tochinese(string str,int index)
{    int ch;

    if (48 <= str[index] && str[index]<= 57)
       ch = str[index]-48;
    else 
        if (97<=str[index]&&str[index]<=102)       
           ch=str[index]-97+10;
        else
           if (65<=str[index]&&str[index]<=70)       
               ch=str[index]-65+10;
   ch = ch *16;
   if (48 <= str[index+1] && str[index+1]<= 57)
         ch = ch+str[index+1]-48;
    else 
        if (97<=str[index+1]&&str[index+1]<=102)       
           ch=ch+str[index+1]-97+10;
        else
           if (65<=str[index+1]&&str[index+1]<=70)       
               ch=ch+str[index+1]-65+10;
    return ch;
}