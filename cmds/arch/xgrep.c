// xgrep.c
//write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/1
inherit F_CLEAN_UP;
int help();
int do_grep(string,string,int);

nosave string pattern;
nosave string result;

int main(object me, string arg)
{
	string  path,wild;
	int level;
	level=1;
	result="ƥ���ļ��У�\n";
	seteuid(geteuid(me));
	write("X grep ���� v0.1  \nWrite By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1\n"+
		"��ҳ��http://mud.yn.cninfo.net/jackyboy\n�ʼ���jackyboy@126.com\n");
    if (!arg) return help();
    if (sscanf(arg,"-d %s %s",path,pattern)!=2)
    {
    	if(sscanf(arg,"-d%d %s %s",level,path,pattern)!=3)
    		if(sscanf(arg,"%s %s",path,pattern)!=2)
    		{
    			write ("\n������������\n\n");
    			return help();
    		}
    }
    else
    	level=15;//��-d����Ĭ�ϼ���Ϊ���м�
    if(level<0) level=1;
    if(level>15) level=15;
    //����path�ֽ��wild
    path=resolve_path(me->query("cwd"),path);
    write("δ����·����\t"+path+"\n");
    //write("�������ַ�����\t"+pattern+"\n");
    write("����Ŀ¼����\t"+level+"\n");
    wild=resolvePath(path,0);
    path=resolvePath(path,1);
    write("������·����\t"+path+"\n");
    write("������ͨ�����\t"+wild+"\n\n");
    do_grep(path,wild,level);
    write("\n����������\n");
    write(result+"\n");
	return 1;
}

int do_grep(string path,string wild,int level)
{
	//int i;string *fs;
	string sbuffer,file;
	reset_eval_cost();//��������ʣ��ִ��ʱ�䣬�������ã�
	if(this_player()->query("env/debug"))
		write("��ʼ����"+path+wild+"\n");
	if(level<0)
	{
		//write("�������ƣ������ٽ���������\n");
		return 0;
	}
	//for(i=0;i<(sizeof(fs=get_dir(path+wild))-1);i++)
	//	write(fs[i]+"\n");

	foreach(file in get_dir(path+wild))
	{
		//write("��飺"+path+file+"\n");
		//write("file_size���أ�"+file_size(path+file)+"\n");
		if(file=="."||file=="..")
			continue;

		switch(file_size(path+file))
		{
			case -1:
				//�޷���ȡ��Ŀ¼������
				break;
			case -2:
				if(file!="."&&file!="..")
					do_grep(path+file+"/","*",level-1);
				break;
			default:
				//write("����ļ���"+path+file+"\n");
				if(!sbuffer=read_file(path+file))
				//��̫����ļ���ȡ����Ҫʧ�ܣ����Ҳ�����ͼ��ȡ�������ļ�����Ϊ����\0!
				{
					write("���ļ�"+path+file+"����\n");
					return 0;
				}
				if(strsrch(sbuffer,pattern)!=-1)
					result=result+"��"+path+file+"���ҵ�"+pattern+"\n";//Ӧ���Ǽ�¼��������������
			/*
				if(strsrch(read_file(path+file),pattern)!=-1)
					write(path+file+"\n");
				break;
			*/
		}

	}
	return 1;
}

int help()
{
  write(@HELP

X grep ���� v0.1  Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1
��ҳ��http://mud.yn.cninfo.net/jackyboy
�ʼ���jackyboy@126.com


ָ���ʽ : xgrep [-d[0-15]] ·�� ��Ҫ�������ַ���
��ָ���������ָ��(����Ŀ¼��������ͨ�����ָ��)������Ŀ¼��Ѱ�Һ���Ҫ
�������ַ������ļ���������λ����ʾ������
ע�⣬Ĭ�Ͻ�������ǰĿ¼��
��֪BUG��
�Զ������ļ������������������Ϊ��ֹ��'\0'���õ�һ��string�
HELP
    );
    return 1;
}
