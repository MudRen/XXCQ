// liu.c
// by mulan

#include <ansi.h>
inherit NPC;
int ask_rank();
int do_skills(string arg);


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
        set("accept", 6000);

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

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
}
int ask_rank()
{
	object me;
	int v_task,i,j,k,h;
	string v_rank,my_rank,str_i,str_j,str_k,str_h;
	string *title1 = ({
"����","����","�ٶ�","��ȭ","����","��Ӱ","����","һ��","����","����",
"����","ѪӰ","����","ǧ��","�쵶","����","��ɱ","���","�ɵ�",
});
	string *title2 = ({
"���","ǧ��","����","����","�˼�","쭷�","����","����","���","��Ǯ",
"����","Ѫ��","��ӥ","����","����","����","Ħ��","˼��",
});
	string *title3 = ({
"˫��֮һ","˫��֮��","һɱ",
});
	string *title4 = ({
"�׷��","����","�����",
});
	string *title5 =({
"ѩ��","ɽ��","����","־��","����","ڤ��","����","����",
});
    i = atoi(read_file("/d/quanli/npc/QUANLI_1",1,1));
    j = atoi(read_file("/d/quanli/npc/QUANLI_2",1,1));
    k = atoi(read_file("/d/quanli/npc/QUANLI_3",1,1));
    h = atoi(read_file("/d/quanli/npc/QUANLI_4",1,1));
	
	me = this_player();
	my_rank = me->query("party/rank");
	v_task = (int)me->query("party/tasks");
	
	if(me->query("party/party_name")!="Ȩ����")
	{
		command("say �㲻��Ȩ������ˣ��Ҳ��ܰ���!\n");
		return 1;
	}
	
		
	if(v_task > 10000)
	{
		if(strlen(my_rank)>9 && my_rank[9..10] == "��")
		{
		command("say �����ڲ���������\n");
		return 1;
		}
        if(h < (sizeof(title5)+1))
		{
        v_rank = HIY""+title5[h]+NOR"";
		h = h+1;
		}
		else
		{
			command("say ������ϯλ�Ѿ�����!\n");
			return 1;
		}
	}
	else if(v_task > 5000)
	{
		if(strlen(my_rank)>7 && my_rank[7..8] == "��")
		{
		command("say �����ڲ���������\n");
		return 1;
		}
		if(me->query("gender") == "����")
		{
            if(j < (sizeof(title3)+1))
			{
            v_rank = HIW"���������֮"MAG+title3[j]+NOR"";
			j = j+1;
			}
			else
			{
			command("say ���ŵ�ϯλ�Ѿ����ˣ���ȥ����һ���İ�!\n");
			return 1;
			}
		}
		else
		{
            if(k < (sizeof(title4)+1))
			{
            v_rank = HIW"���������֮"MAG+title4[k]+NOR"";
			k = k+1;
			}
			else
			{
				command("say ���ŵ�ϯλ�Ѿ����ˣ���ȥ����һ���İ�!\n");
				return 1;
			}
		}
	}
	
	else if(v_task > 2000)
	{
		if(strlen(my_rank)>19 && my_rank[17..20] == "���")
		{
		command("say �����ڲ���������\n");
		return 1;
		}			
       if(i < (sizeof(title2)+1))
		{
        v_rank = HIB""+title2[i]+RED" ���"NOR;
		i = i+1;
		}
		else
		{
			command("say ������ϯλ�Ѿ����ˣ���ȥ����һ���İ�!\n");
			return 1;
		}
	}
	else if(v_task > 1000)
	{
		if(strlen(my_rank)>22 && my_rank[20..23] == "����")
		{
		command("say �����ڲ���������\n");
		return 1;
		}			
		v_rank = RED""+title1[random(sizeof(title1))]+"���"+HIM"����"NOR;
		
	}
	else
	{
	command("say ��Ա�����ҳ϶Ȼ�����������ʵ�°�!\n");
	return 1;
	}
 	if(my_rank[7..8] == "��" && me->query("gender")=="����")
 	j = j-1;
 	if(my_rank[7..8] == "��" && me->query("gender")=="Ů��")
 	k = k-1;
 	if(my_rank[17..20] == "���")
 	i = i-1;

	command("chat* gongxi "+me->query("id"));
	command("chat "+me->query("name")+"��Ȩ������"+v_rank+"һְ��\n");
 	me->set("party/rank",v_rank);
 	
	str_i=sprintf("%d",i);
	str_j=sprintf("%d",j);
	str_k=sprintf("%d",k);
	str_h=sprintf("%d",h);

  if( write_file("/d/quanli/npc/QUANLI",v_rank+"     "+me->query("name")+"\n"))
  command("say ��ļ�¼д��ɹ�!\n");
     else command("say ��ļ�¼д��ʧ��!\n");
    write_file("/d/quanli/npc/QUANLI_1",str_i,1);
    write_file("/d/quanli/npc/QUANLI_2",str_j,1);
    write_file("/d/quanli/npc/QUANLI_3",str_k,1);
    write_file("/d/quanli/npc/QUANLI_4",str_h,1);
	
	return 1;
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="liu" )
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != "Ȩ����")
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
		return 1;
	}
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"�����Ŀǰ��ѧ���ļ��ܣ�\n"+

  "�����Ṧ (dodge)                         - ��ɲ� 220/    0	\n"+
  "�����ڹ� (force)                         - ��ɲ� 200/    0	\n"+
  "�����м� (parry)                         - ��ɲ� 200/    0	\n"+
  "�������� (sword)                         - ��ɲ� 200/    0	\n"+
  "����д�� (literate)                      - �����ž� 180/    0       0/    0	\n"+
"�������� (liuxu-shenfa)                  - �������� 220/    0       0/    0	\n");
   return 1;
}
#include "quanli.h"
