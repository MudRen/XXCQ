#define MASTER "/adm/obj/master"
inherit F_CLEAN_UP;
#define SPLIT "\n.\n"
#define EM_HEAD "\n.\nbegin:\n.\n"
int main(object me,string file)
{
	string key,str,str1,item,type,mesg;
	mapping emote;
	if(!file||file=="")
		return notify_fail("�÷���import �ļ���\n");
	file=MASTER->make_path_absolute(file);
	write("׼�����ļ�"+file+"����emote���ݡ�\n");
	if(MASTER->valid_read(file,me,"read_file")==0)
		return notify_fail("�㲻��д���ļ������ʧ�ܣ�\n");
	if(file_size(file)<0)
		return notify_fail("���������ڣ�\n");
	str=read_file(file);
	foreach(str1 in explode(str,EM_HEAD))
	{
		emote=([]);
		if(sscanf(str1,"%s"+SPLIT+"%s",key,str1)!=2)
			return notify_fail("�ؼ���emote���ʶ�ȡ����\n");
		//if(mapp(EMOTE_D->query_emote(key)))//����key���emote!
		//	continue;
		foreach(item in explode(str1,SPLIT))
		{
			if(sscanf(item,"%s:%s",type,mesg)!=2)
				return notify_fail("����"+key+"�����ݷ�������\n");
			emote[type]=mesg;
		}
		emote["updated"]=me->id(1);
		EMOTE_D->set_emote(key,emote);
		write("�ɹ�����emote -> "+key+"!\n");
	}
	return 1;
}
