//ע�᷿�� ��лBigfoot@SDXL��֧�ֺͰ���
//JackyBoy@CuteRabbit Studio for CCTX 1999/5/16

#include <mudlib.h>
#include <ansi.h>

inherit REGROOM;

void create()
{
    set("short",  CHINESE_MUD_NAME+"ע�ᴦ" );
    set("long", 
    NOR"��ӭ����"+CHINESE_MUD_NAME+"��ע�ᴦ��\n"+
    "�������Ķ�ע����֪("HIR"����look notes����"NOR")��\n"+
    "������ϸ�Ķ���������("HIR"����look rules����"NOR")��\n"+
    "�����ͬ�⽭������������ע����ĵ��������ַ��\n"+
    "("HIR"register ���������ַ"NOR")\n"+
    "("HIR"zhuce ���������ַ"NOR")\n"+
    "������������"HIR"suicide -f"NOR"�����˳�������\n"+
    "\t\t\t\t"+CHINESE_MUD_NAME+"��ʦ����\n"+
    "\t\t\t\t\t\t"+"һ�žž�����¾���\n"
        );
	set("exits",([
		"��ʼ��Ϸ":"/d/bianliang/guangming",
	]));
	set("no_fight", 1);
	setup();
}

void init()
{
	::init();
	add_action("do_read","look");
	add_action("do_read","l");
}

int do_read(string arg)
{
	switch(arg)
	{
		case "notes":
			write(
				"�����������ȷ�ĵ��������ַ����ȷ��ע���ż�����ȷ�͵������\n"+
				"�����û�еõ�ע�����룬����ԭ���������¼����ע�ᡣ\n"+
				"������������ʦ��ϵ������������ҳ�����ԡ�\n"+
				"snowmud@126.com\n"+
				"snowmud@soim.net\n"
				);
			break;
		case "rules":
			write(
				"������help ����ȡ��ϸ����Ϸ��������Υ����Υ���ؾ���\n"+
				"����㲻ͬ�����������ʦ��ϵ������suicide -f�˳�������\n"
				);
			break;
		default:
			return 0;
	}
	return 1;
}
