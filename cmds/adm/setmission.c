// by xiha@hslj2  05/11/1999  
// last modified by xiha@workgroup on Aug 26,1999
#include <ansi.h>
inherit F_CLEAN_UP;
//string replace_color(string,int);
//�˺������ƶ���/adm/simul_efun/message.c����Ϊsim_efunʹ�ã�
//����ڶ�������Ϊ0��ʾ�����ɫ���ƣ�����Ϊ��$HIW$���ַ����滻Ϊ��ɫ���ƴ���

int main(object me, string arg)
{
	int i, flag = 0;
	object ob;
	string mission, wname, wmin, file;
	string *wmission;
	if( me!=this_player(1) ) return 0;
	if( !arg || sscanf(arg, "%s %s", arg, mission)!=2 )
		return notify_fail("ָ���ʽ��setmission <ʹ����> (Ŀǰ����)\n");
	//��ʵ����ֻҪ�ж�һ���Ƿ�����ʦ�б����OK��
	if( !objectp(ob = present(arg, environment(me))) || !userp(ob) )
		return notify_fail("��ֻ�ܸı䵱ǰʹ���ߵ�����\n");
	mission = replace_color( mission, 1);
	file=read_file("/adm/etc/wizmission");
	if(file)
		wmission = explode(file, "\n");
	else
		wmission = ({});
	for(i=0; i<sizeof(wmission); i++)
	{
		if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
		if( wname==ob->query("id") )
		{
			wmission[i] = sprintf("%s %s\n", wname, mission);
			flag = 1;
			break;
		}
	}
	for( file = "", i=0; i<sizeof(wmission); i++) file += wmission[i] + "\n";
	if(!flag)
		write_file("/adm/etc/wizmission", ob->query("id") + " " + mission + "\n", 0);
	else
		write_file("/adm/etc/wizmission", file, 1);
	message_vision("$N��$n�Ĺ��������Ϊ " + mission + " ��\n", me, ob);
	return 1;
}
        
int help(object me)
{
        write(@HELP
ָ���ʽ : setmission <ĳ��> (Ŀǰ����)
�����ı���ʦ��ǰ���������˵�������� wizlist ʹ�á�
HELP
        );
        return 1;
}

