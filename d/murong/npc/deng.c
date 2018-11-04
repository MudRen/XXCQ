// deng.c �˰ٴ�

inherit NPC;
inherit F_MASTER;                        
#include <ansi.h>
#include <localtime.h>
#include "app.h"
int ask_fenmu();
int ask_jifen();
void create()
{
	set_name("�˰ٴ�",({"deng baichuan","deng","baichuan"}));
        set("title","����ׯׯ��");
  	set("long", 
              "�����ǹ���Ľ������ׯ��ׯ����\n");
        set("age", 25);
	set("attitude", "friendly");
        set("unique", 1);
	set("shen_type", 1);
	set("per", 30);
	set("str", 36);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	set("combat_exp", 750000);
	set("score", 85000);

        set_skill("finger",130);
        set_skill("dodge",130);
        set_skill("force", 120);
	set_skill("shenyuan-gong", 120);
	set_skill("yanling-shenfa", 150);
        set_skill("parry", 130);
	set_skill("canhe-zhi", 130);
        set_skill("literate", 130);

	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "xingyi-zhang");
        map_skill("finger", "canhe-zhi");	

	prepare_skill("finger","canhe-zhi");
	setup();
        carry_object("/clone/misc/cloth")->wear();        
        create_family("����Ľ��",3,"����");
        set("inquiry", ([
            "name" : "�Ҿ��ǹ���Ľ������ׯׯ���˰ٴ���\n",
            "here" : (: ask_fenmu :),                             
            "rumors" : "���������һλ��ʦ����������Τ���������������˾���Ϊ��Ľ�ݵ��Ա�֮������ʩ������Ϊ��\n",            
            "����" : "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�\n",
            "����" : "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����\n",
            "������" : "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�\n",
            "����Ǭ" : "����Ǭ���Ҷ��ܣ����������ϼׯ��ׯ����\n",
            "����ͬ" : "����ͬ�������ܣ�����������ׯ��ׯ����������ϲ��˵����Ҳ����Ҳ����\n",
            "�粨��" : "�粨�������ĵܣ�����������˪ׯ��ׯ����������ϲ�������˴�ܡ�\n",
            "����ˮ�" : "����ˮ��ǰ������ס�ĵط��������ﲻԶ��\n",
            "����С��" : "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�\n",
            "��٢��ɽׯ" : "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��\n",
            "��ʩˮ��" : "���������������֮���ڣ��ҿɲ������˵��\n",       
            "����" : (: ask_jifen :),
            "ɨĹ" : (: ask_jifen :),
]));                 

}
int ask_jifen()
{
	mapping fam;                         
	mixed *ltime;
	int i, current_month, current_day, current_hour;	
	object me, ob, *obj;
	me = this_player();
	ob = this_object();
	obj = all_inventory(environment(ob));	
	ltime = localtime(time());
	current_month = ltime[LT_MON]+1;
	current_day = ltime[LT_MDAY];                     
	current_hour = ltime[LT_HOUR];	
        if( sizeof(obj) > 2)
        {
		for(i=0; i<sizeof(obj); i++)
		{
			if( obj[i]->is_character() && obj[i]->query("family/family_name") != "����Ľ��")
			{
				command("say �����������ﻹ�ǲ�˵Ҳ�ա�");
				return 1;
			}
			else if(current_month == 4 && current_day == 4 )
			{                                            
				command("say �����������ڣ��������ʱǰ�����أ�ɨĹ�ɡ�");
				return 1;
			}
			else                                                                                 
			{                         
				command("say �ȵ������������������أ�ɨĹ�ɡ�");
		                return 1;
			}
		}
	}

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
        {
                command("say "+ RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��");
                return 1;
	}
	if(current_month == 4 && current_day == 4 )
	{                                            
		command("say �����������ڣ��������ʱǰ�����أ�ɨĹ�ɡ�");
		return 1;
	}
	command("say �ȵ������������������أ�ɨĹ�ɡ�");
	return 1;
}                
	
int ask_fenmu()
{
	mapping fam; 
	int i;
	object me, ob, *obj;
	me = this_player();
	ob = this_object();
	obj = all_inventory(environment(ob));

        
        if( sizeof(obj) > 2)
        {
		for(i=0; i<sizeof(obj); i++)
		{
			if( obj[i]->is_character() && obj[i]->query("family/family_name") != "����Ľ��")
			{
				command("say �����������ﻹ�ǲ�˵Ҳ�ա�");
				return 1;
			}

			else                                                                                 
			{
				command("say �Դ���ү��ȥ��֮�󣬹���ÿ��������������������ү��ɨĹ��");
		                return 1;
			}
		}
	}

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
        {
                command("say "+ RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��");
                return 1;
	}

	command("say �Դ���ү��ȥ��֮�󣬹���ÿ��������������������ү��ɨĹ��");
	return 1;
}                