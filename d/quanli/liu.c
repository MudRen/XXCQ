// quhanshan.c
// by mulan

#include <ansi.h>
inherit NPC;
int ask_rank();

void create()
{
        set_name("�����", ({"liu suifeng", "liu"}));
        set("gender", "����");
        set("age", 56);
        set("nickname",HIW"��������"NOR);
        set("long",
        "����磡 ��һ����������������ը����ÿ���˶�� �����ܹܣ�����۵�Ψһ���ţ�\n");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 30);
        set("dex", 999);

        set("title","��Ȩ����__��ʦ��");

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 500000);
        set("score", 300000);

        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("liuxu-shenfa",220);  
        set_skill("dodge", 220);
        set_skill("parry", 200);
        set_skill("literate",180);

        map_skill("dodge", "liuxu-shenfa");
        
        set("inquiry", ([
            "rank" : (: ask_rank :),
            "����" : (: ask_rank :),            
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
//	carry_object(__DIR__"obj/grayrobe")->wear();

}

int ask_rank()
{
	object me;
	int v_task;
	string v_rank;
	string *title1 = ({
"����","����","�ٶ�","��ȭ","����","��Ӱ","����","һ��","����","����",
"����","ѪӰ","����","ǧ��","�쵶","����","��ɱ","���","�ɵ�",
});
	me = this_player();
	v_task = (int)me->query("party/tasks");
	
	if(me->query("party/party_name")!="Ȩ����")
	{
		command("say �㲻��Ȩ������ˣ��Ҳ��ܰ���!\n");
		return 1;
	}
	
	if(me->query_temp("rank") == 1)
	{
		command("say ����첻�ǲ�������\n");
		return 1;
	}
	
	if(v_task > 10000)
	v_rank = HIY"��̳����";
	else if(v_task > 5000)
	v_rank = HIW"�����֮����";
	else if(v_task > 2000)
	v_rank = HIB""+title1[random(sizeof(title1))]+"�ֶ�"+HIM"����"NOR;
	else if(v_task > 1000)
	v_rank = RED""+title1[random(sizeof(title1))]+"���"+HIM"����"NOR;
	else
	command("say ��Ա�����ҳ϶Ȼ�����������ʵ�°�!\n");
	command("chat* gongxi "+me->query("id"));
	command("chat "+me->query("name")+"��Ȩ������"+v_rank+"һְ��\n");
	me->set_temp("rank",1);
// 	me->set("party/",v_rank);
	return 1;
}
#include "/kungfu/class/quanli/quanli.h"
