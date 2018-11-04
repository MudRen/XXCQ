// /u/beyond/mr/npc/wang.c ������
// this is made by beyond
// update 1997.6.29
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int do_ask();
void create()
{
	set_name("������",({"wang furen","wang","furen"}));
	set("gender", "Ů��");
        set("unique", 1);
	set("rank_info/respect", "����");
        set("title","��٢��ɽׯ��");
  	set("long", 
              "��������٢��ɽׯ�����ˣ�������ȥ������ʮ�мӣ��������ȴ档\n");
        set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 20);
	set("int", 22);
	set("con", 28);
	set("dex", 23);
	set("per", 30);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1000);
	set("max_neili", 1500);
	set("jiali", 0);
	set("combat_exp", 80000);
	set("score", 15000);
        set("inquiry", ([
            "name" : "�Ҿ�����٢��ɽׯ�����ˣ��������ѵ�û��ʲô��ʾ��\n",
            "here" : "��������٢��ɽׯ��ׯԺ֮���ڣ��˴���Ϊ�ƽ�¥��\n",
            "rumors" : "������Ǳ���Ľ�ݲ����������ˡ�\n",
            "������" : "�������ҵı���Ů������ɱ�����������⡣\n",
            "Ľ�ݸ�" : "Ľ�ݸ������ǲ�������ֶ�����������Ա�֮����ʩ����ľ��������𽭺���\n",
            "������" : "������������٢��ɽׯ�Ĳ���֮����һ�����Ǳ����ȥ�ˡ�\n",
            "��٢��ɽׯ" : "���������٢��ɽׯ���Ҿ�����������ˡ�\n",
            "��ʩˮ��" : "���������������֮���ڣ�������ʩˮ��Ĳ����������Ƕ�Ķ�ѽ��\n",       
            "job" : (: do_ask :),
]));
        set_skill("murong-xinfa", 70);
        set_skill("dodge",70);
        set_skill("force", 70);
	set_skill("shenyuan-gong", 70);
	set_skill("yanling-shenfa", 70);
        set_skill("parry", 70);
	set_skill("literate", 70);
        set_skill("strike", 65);
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        
	setup();
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt")->wear();
       
}

int do_ask()
{
        mapping myfam;
        object me, ob, target;
        object* living;
        int i,j,size,tcomp,ucomp,tasktype;//tasktype=0 ���� 1 �л�
        size=sizeof(living);       
        i=random(size);
        j=i;        
        living=livings(); 
        me=this_player();                                         
       	ob=this_object();                                         
        target=living[j];
       	seteuid(geteuid(me));       	
        myfam = (mapping)me->query("family");


        ucomp=(int)me->query("combat_exp");
        tcomp=(int)target->query("combat_exp");        

	
	if(!myfam || myfam["family_name"] != "����Ľ��")
            return notify_fail("��Ҫ��ʲô��\n");
        while(1)
        {  

            if((target->query("race")=="����") && !userp(target) && !wizardp(target) )
            {
            	    if((tasktype==0) && (tcomp>=1.2*ucomp) && (tcomp<=2.2*ucomp))
                    {
                        command("say "+target->name()+"���뱾�����ԣ���ȥ����ɱ�ˣ�\n");
                   	tell_object(me,"�鰲ͨ�ó�һ�������ƣ������������"+target->name()+"�����֣��������㡣\n");
                    	tell_room(environment(me),"�鰲ͨ�ó�һ�������ƣ������������"+
                        target->name()+"�����֣�������"+me->name()+"��\n");
                    	return 1;
                }
                    else if(tasktype==1)
                    {
        	        command("say "+"����������ȥ�跨��"+target->name()+"��˳���̣�\n");
	                tell_object(me,"�鰲ͨ�ó�һ���л��ƣ������������"+target->name()+"�����֣��������㡣\n");
                    	tell_room(environment(me),"�鰲ͨ�ó�һ���л��ƣ������������"+
                        target->name()+"�����֣�������"+me->name()+"��\n");
                    	if(me->query_temp("quest/huilu",1)!=0)
                        me->delete_temp("quest/huilu");
	                return 1;
                    }
            }
            j++;
            if(j>=size)
                j=0;
            if(j==i)
                break;
        } 
        command("say ����û����������������ɡ�");
        return 1;                                
}