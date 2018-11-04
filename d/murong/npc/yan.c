// yan.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "yan mama", "mam", "yan" }));
        set("gender", "Ů��");
        set("unique", 1);
        set("age", 50);      
	set("title",BLU	"���ʷ�����"NOR);
	set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "peaceful");
	set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
	set("jiali",30);
	set("score", 8000);

        set_skill("cuff", 70);
	set_skill("parry",70);
	set_skill("yanling-shenfa",70);
        set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan-gong",70);
	set_skill("murong-daofa", 70);
        set_skill("blade",70);
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
	map_skill("blade", "murong-daofa");
        
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);

        setup();
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/clone/misc/cloth")->wear();
        set("inquiry", ([
            "name" : "������٢��ɽׯ�Ļ������¡�\n",
            "here" : "�����ǻ��ʷ���ר�Űѷ����ô������������ʡ�\n",
            "rumors" : "���һ���նε�С�Ӵ����������ˡ�\n",
        
 ]));           
}
void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && ( (fam = ob->query("family")) && fam["family_name"] != "����Ľ��" ) )
        {
                        command("say �������ʲ�̫�����������������������ʰɣ�����\n");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
