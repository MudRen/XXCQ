// ls.c modify by jackyboy@cctx 98/12/18
#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, j, w, col,*dis,d,abs_flag;
	string dir,dir1,*filter;
	mixed *file;
	seteuid(geteuid(this_player(1)));
	abs_flag=0;
	dir = resolve_path(me->query("cwd"), arg);
	arg=dir;

	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) 
		dir += "/";

	file = get_dir(dir, -1);
	if( !sizeof(file) )
	{
		if (file_size(dir) == -2) 
			return notify_fail("Ŀ¼�ǿյġ�\n");
		else
			return notify_fail("û�����Ŀ¼��\n");
	}
	//����arg�е�'*','?'
	filter=explode(arg,"/");
	j=sizeof(filter);
	if(j>0)
	{
		arg=(strsrch(filter[0],"*")==-1&&strsrch(filter[0],"?")==-1)?filter[0]:"";
		for(i=1;i<j;i++)
		{
			if(strsrch(filter[i],"*")!=-1)
				i++;
			else
				if(strsrch(filter[i],"?")!=-1)
					i++;
				else
					arg+="/"+filter[i];
		}
	}
	i = sizeof(file);
	w = 0;
	d=0;
	dis=allocate(i);
	while(i--) {
		dir1=file[i][0];
		j=strlen(arg)-1;
		if(j<0) j=0;
		dir1=(arg[j]=='/')?(arg+dir1):(arg+"/"+dir1);
		dir1=(dir1[0]=='/')?dir1:"/"+dir1;
		if(file[i][0]=="."||file[i][0]=="..")
			continue;//ֱ���������ˣ���Ȼ".."���ǲ���������ʾ
		if(file_size(dir1)==-1)
			dis[d++]=i+1;
		file[i][0] =(file[i][1]==-2)?file[i][0]+"/":file[i][0];
		if (strlen(file[i][0])>w) 
			w = strlen(file[i][0]) + 1;
	}
	d=0;
	write("\nĿ¼��" + dir + "\n");
	col = 70 / (w+6);
	d=0;
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++)
		{
			d++;
			if(member_array(i+1,dis)==-1)//�ж�Ŀ¼�Ƿ�ɶ�i+1
				printf("%4d %-*s%s", file[i][1]/1024 + 1, w+1,
					file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
					((i+1)%col)?"  ":"\n");
			else
			{	d--;
				printf(HIY"%4d %-*s%s"NOR, file[i][1]/1024 + 1, w+1,
					file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
					((i+1)%col)?"  ":"\n");
				
			}
		}
	else write("    û���κε�����\n");
	write("\n");
	
	return 1;	
}

int help()
{
	write(@HELP
ָ���ʽ: ls [<·����>]
�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г�����Ŀ¼
�����ݣ����г��ĵ�����ǰ���ʾ * �ŵ����Ѿ�����������
��ɫĿ¼Ϊ��Ȩ�޶�ȡ��Ŀ¼�� 
JackyBoy @ CCTX 98/12/18
HELP
	);
	return 1;
}

