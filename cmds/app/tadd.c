// toptenadd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string type,player;
	object ob;

	seteuid(geteuid(me));
	if (!arg||sscanf(arg,"%s %s",type,player)!=2)
		return notify_fail("ָ���ʽ : toptenadd <����> <���ID>\n");
	if(!objectp(ob=find_player(player)))
		return notify_fail("û��"+player+"�����һ�"+player+"�����ߡ�\n");
	switch(type)
	{
	case "rich":
		if(TOPTEN_D->topten_add(ob,type))
			write("���"+player+"�ɹ�����"+RICH_B+"��\n");
		else
			write("���"+player+"û�ʸ�����"+RICH_B+"��\n");
		break;
	case "pker":
		if(TOPTEN_D->topten_add(ob,type))
			write("���"+player+"�ɹ�����"+PKER_B+"��\n");
		else
			write("���"+player+"û�ʸ�����"+PKER_B+"��\n");
		break;
	case "exp":
		if(TOPTEN_D->topten_add(ob,type))
			write("���"+player+"�ɹ�����"+EXP_B+"��\n");
		else
			write("���"+player+"û�ʸ�����"+EXP_B+"��\n");
		break;
	default:
		return notify_fail("���ڻ�û��"+type+"�������а�\n");
	}
	return 1;
}

int help()
{
write(@HELP
ָ���ʽ : tadd <����> <���ID>
HELP
    );
    return 1;
}
