// feng.c �粨��

inherit NPC;
inherit F_MASTER;
#include "app.h"
int ask_here();
void create()
{
	set_name("�粨��",({"feng boe","feng","boe"}));
        set("title","��˪ׯׯ��");
        set("nickname","һ���");
  	set("long", "�����ǹ���Ľ����˪ׯ��ׯ����\n");
        set("age", 25);
	set("attitude", "friendly");
        set("unique", 1);
	set("shen_type", 1);
	set("str", 26);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	set("combat_exp", 850000);
	set("score", 85000);

        set_skill("strike",130);
        set_skill("dodge",130);
        set_skill("force", 130);
	set_skill("shenyuan-gong", 130);
	set_skill("yanling-shenfa", 130);
        set_skill("parry", 130);
	set_skill("xingyi-zhang", 130);
        set_skill("literate", 130);

	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "xingyi-zhang");
        map_skill("strike", "xingyi-zhang");	
        prepare_skill("strike", "xingyi-zhang");
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/blade")->wear();
       
        create_family("����Ľ��",3,"����");
        set("inquiry", ([
            "name" : "�Ҿ��ǹ���Ľ����˪ׯׯׯ���粨��\n",
            "here" : (: ask_here :),
            "rumors" : "���������һλ��ʦ����������Τ���������������˾���Ϊ��Ľ�ݵ��Ա�֮������ʩ������Ϊ��\n",            
            "����" : "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�\n",
            "����" : "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����\n",
            "������" : "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�\n",
            "�˰ٴ�" : "�˰ٴ����Ҵ�磬������������ׯ��ׯ����\n",
            "����Ǭ" : "����Ǭ���Ҷ��磬���������ϼׯ��ׯ����\n",
            "����ͬ" : "����ͬ�������磬����������ׯ��ׯ����������ϲ��˵����Ҳ����Ҳ����\n",
            "����ˮ�" : "����ˮ��ǰ������ס�ĵط��������ﲻԶ��\n",
            "����С��" : "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�\n",
            "��٢��ɽׯ" : "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��\n",
            "��ʩˮ��" : "���������������֮���ڣ��ҿɲ������˵��\n",       
            "��λ" : "��λ���ǰ�������ô��\n",            
]));
        
}

int ask_here()
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
				command("say ���﹩������λ��ү�ӵ���λ������ÿ�춼���������밲��");
		                return 1;
			}
		}
	}

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
        {
                command("say "+ RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��");
                return 1;
	}

	command("say ���﹩������λ��ү�ӵ���λ������ÿ�춼���������밲��");
	return 1;
}              