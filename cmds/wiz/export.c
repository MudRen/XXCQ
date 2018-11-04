#define MASTER "/adm/obj/master"
inherit F_CLEAN_UP;
#define SPLIT "\n.\n"
#define EM_HEAD "\n.\nbegin:\n.\n"
int main(object me,string file)
{
	string *all_keys,key,str,item;
	mapping emote;
	if(!file||file=="")
		return notify_fail("�÷���export �ļ���\n");
	file=MASTER->make_path_absolute(file);
	write("׼�����emote���ݵ��ļ�"+file+"�\n");
	if(MASTER->valid_write(file,me,"write_file")==0)
		return notify_fail("�㲻��д���ļ������ʧ�ܣ�\n");
	if(file_size(file)!=-1)
		return notify_fail("�����Ѿ����ڣ����Ƚ���ɾ����\n");//���Զ�д�жϵģ�
	all_keys=EMOTE_D->query_all_emote();
	str="";
	foreach(key in all_keys)
	{
		emote=EMOTE_D->query_emote(key);
		str+=EM_HEAD+key+SPLIT;
		foreach(item in keys(emote))
			if(item!="updated")
				str+=item+":"+emote[item]+SPLIT;
	}
	if(write_file(file,str,1)==0)
		return notify_fail("д�ļ�"+file+"��������ϸ�������¼��\n");
	write("����ɹ���>>"+file+"\n");
	return 1;
}
