// made by lks

#include <ansi.h>

int ask_me();
inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/xuehepai/wei.h"
void heal_ob();
void recover_ob();

void create()
{
        set_name("�ο�",({"ren kuang","ren"}));
        set("nickname",HIY"���ֹ���"NOR);
	set("gender","����");
	set("int",30);	
	set("con",30);
	set("str",30);
	set("dex",30);
	set("bac",40);
        set("yiqiguan_riyue",2);
       set("che",1);
	set("age",40);
	set("attitude","friendly");
        set("combat_exp",800000);
        set("kill",1000);
	set("long",
  "Ӣ������,���д󽫷�ȡ�\n"
	);
        set("neili",3000);
        set("jingli",3000);
        set("max_neili",3000);
        set("max_jingli",3000);
        set_skill("literate",120);
        set_skill("cuff",180);
        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("youran-bu",180);
        set_skill("yudi-whip",180);
        set_skill("whip",180);
        set_skill("jieniu-dao",180);
        set_skill("blade",180);
        set_skill("yiqiguan-riyue",180);
        set_skill("arrow",180);
        set_skill("youren-arrow",180);
        set_skill("force",180);
        set_skill("tao",140);
        map_skill("force","yiqiguan-riyue");
        map_skill("blade","jieniu-dao");
        map_skill("dodge","youran-bu");
        map_skill("arrow","youren-arrow");
        map_skill("whip","yudi-whip");
	
       create_family("Ѫ����",12,"����");
	setup();
       set("inquiry",([
            "Ѫ�ӳ�" : (: ask_me :),
            "che" : (: ask_me :),
       ]));
        carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
        set("chat_chance", 2);
	set("chat_msg", ({
		(: heal_ob :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: exert_function, "zhibiao" :),
                (: recover_ob :),
	}) );
}

	
void heal_ob()
{
	command("yun heal");
	command("yun heal");
	command("yun heal");
	command("yun recover");
	return;
}

void recover_ob()
{
	command("yun recover");
	return;
}

int ask_me()
{
           mapping fam;

           object me=this_player();

           fam=(mapping)me->query("family");

           if (!fam || fam["family_name"]!="Ѫ����")
           {
                  command("say ���뱾�ɲ��޹ϸ𣬴˻��Ӻ�˵��");
                  return 1;
           }
             if (!(present("xuehe che",environment(me))))
            {
                 command("say Ѫ�ӳ��Ѿ���ȡ���ˡ�");
                 return 1;
            }
            if (me->query("combat_exp")>500000) {
                  command("say �ðɣ����Ѫ�ӳ����߰ɡ�");
              me->set_temp("ask1",1);
                return 1;
                   }
                else {
                     command("say ��ľ��鲻�������Ѫ�ӳ���Ū���ˡ�");
                     return 1;
                }

}

