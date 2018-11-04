//δ��emote�ڲ�˳������
#define MASTER "/adm/obj/master"
#define MAX 40
inherit F_CLEAN_UP;
#define SPLIT "\n.\n"
#define EM_HEAD "\n.\nbegin:\n.\n"
int main(object me,string file)
{
	string *all_keys,key,str,item,fn;
	mapping emote;
	int i,j;
	if(!file||file=="")
		return notify_fail("�÷���export �ļ���\n");
	file=MASTER->make_path_absolute(file);
	write("׼�����emote���ݵ��ļ�"+file+"�\n");
	if(MASTER->valid_write(file,me,"write_file")==0)
		return notify_fail("�㲻��д���ļ������ʧ�ܣ�\n");
	if(file_size(file)!=-1)
		return notify_fail("�����Ѿ����ڣ����Ƚ���ɾ����\n");//���Զ�д�жϵģ�
	all_keys=sort_array(EMOTE_D->query_all_emote(),1);
	str="";i=0;j=0;
	foreach(key in all_keys)
	{
		emote=EMOTE_D->query_emote(key);
		str+=EM_HEAD+key+"\n\n"SPLIT;
		foreach(item in keys(emote))
			switch(item)
			{
				case "updated":break;
				default:
					str+=item+":"+emote[item]+SPLIT;
			}
			str+="=======================================\n";
		if((++i%MAX)==0)
		{
			str=replace_string(str,EM_HEAD,"");
			str=replace_string(str,SPLIT,"");
			fn=file+(string)j;
			if(write_file(fn,str,1)==0)
				return notify_fail("������ļ�"+fn+"����\n");
			write("����� >>"+fn+"\n");
			str="";j++;
		}
	}
	str=replace_string(str,EM_HEAD,"");
	str=replace_string(str,SPLIT,"");
	fn=file+(string)j;
	if(write_file(fn,str,1)==0)
		return notify_fail("������ļ�"+fn+"����\n");
	write("����� >>"+fn+"\n");
	write("����ɹ���>>"+file+"X\n");
	return 1;
}
