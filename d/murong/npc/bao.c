// bao.c ����ͬ

inherit NPC;
inherit F_MASTER;        
#include "app.h";
void create()
{
	set_name("����ͬ",({"bao butong","bao","butong"}));
        set("title","���ׯׯ��");
        set("nickname","��������");
  	set("long", 
              "������Ľ�ݸ��Ľ���ֵܹ���Ľ�ݽ��ׯ��ׯ����\n");
        set("age", 25);
	set("attitude", "friendly");
        set("unique", 1);
	set("shen_type", 1);
	set("str", 46);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	set("combat_exp", 850000);
	set("score", 85000);

        set_skill("sword",130);
        set_skill("dodge",130);
        set_skill("force", 130);
	set_skill("shenyuan-gong", 130);
	set_skill("yanling-shenfa", 130);
        set_skill("parry", 130);
        set_skill("murong-daofa", 150);
        set_skill("literate", 130);
        set_skill("finger", 130);
        set_skill("canhe-zhi", 130);
        set_skill("strike", 130);
        set_skill("xingyi-zhang", 130);

	map_skill("force", "shenyuan-gong");
        map_skill("strike", "xingyi-zhang");
        map_skill("finger", "canhe-zhi");
	map_skill("dodge", "yanling-shenfa");
       	map_skill("parry", "murong-daofa");
       	map_skill("blade", "murong-daofa");  
       	
       	prepare_skill("finger", "canhe-zhi");
        prepare_skill("strike", "xingyi-zhang");
        create_family("����Ľ��",3,"����");
        set("inquiry", ([
            "name" : "��Ҳ����Ҳ���Ҿ��ǹ���Ľ�ݽ��ׯׯׯ������ͬ��\n",
            "here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
            "rumors" : "Ľ�ݹ��ӵ��Ա�֮������ʩ��������������\n",
            "����" : "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�\n",
            "����" : "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����\n",
            "������" : "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�\n",
            "�˰ٴ�" : "�˰ٴ����Ҵ�磬������������ׯ��ׯ����\n",
            "����Ǭ" : "����Ǭ���Ҷ��磬���������ϼׯ��ׯ����\n",
            "�粨��" : "�粨�������ĵܣ�����������˪ׯ��ׯ����������ϲ�������˴�ܡ�\n",
            "����ˮ�" : "����ˮ��ǰ������ס�ĵط��������ﲻԶ��\n",
            "����С��" : "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�\n",
            "��٢��ɽׯ" : "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��\n",
            "��ʩˮ��" : "���������������֮���ڣ��ҿɲ������˵��\n",       
        ]));
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();   
}
        
