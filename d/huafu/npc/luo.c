// luo.c ����ϼ
#include <ansi.h>
#include "/d/huafu/npc/cam.h"
inherit NPC;
inherit F_MASTER;
#include "/d/huafu/npc/luo.h"
int ask_kungfu();

void create()
{
	set_name("����ϼ", ({ "luo wuxia", "luo" }));
	set("nickname",HIY"�ɰ˽�"NOR);
         set("rank","����");
	set("gender", "����");
	set("age", 33);

	set("combat_exp", 1200000);
        set("max_neili",4000);
        set("neili",4000);
        set("max_qi",4000);
        set("eff_qi",4000);
        set("qi",4000);
        set("max_jingli",4000);
        set("eff_jingli",4000);
        set("jingli",4000);

        set_skill("cuff",100 );
        set_skill("confu",200);
        set_skill("force", 180);
        set_skill("dodge", 200);
                 set_skill("chixin-jian",350);
                 set_skill("sword",350);
        set_skill("bairen-shengong",180);

        map_skill("force","bairen-shengong");
	map_skill("sword","chixin-jian");
       create_party(HIG"���ζ���"NOR,HIW"����"NOR,6);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
            set("inquiry",([
                    "�����鳤��" : (: ask_kungfu :),
                    "ѧ��" : (: ask_kungfu1 :),
                    "sword" : (: ask_kungfu2 :),
                    "����" : (: ask_kungfu2 :),
                    "����" : (: ask_kungfu :),
            ]));
          set("chat_chance",2);
          set("chat_msg",({
              (: exert_function,"heal" :),
              (: exert_function,"heal" :),
          }));
          set("chat_chance_combat",30);
          set("chat_msg_combat",({
              (: perform_action,"sword.kuhai" :),
              (: exert_function,"recover" :),
          }));

          carry_object("/clone/misc/cloth")->wear();
          carry_object("/clone/weapon/changjian")->wield();
}

void attempt_join()
{
        object ob;
        object mee;
        
        ob = this_player () ;
        mee=this_object();
        if ((int)ob->query("shen") < 0)
        {
        message_vision(HIC "$n��$N��ŭ����һ����Ͳ��Ǻ���!\n" NOR,ob,mee);
//      set_leader(this_player());
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, this_player()); 
        return;
        }
        if ((int)ob->query("shen") < 1000)
        {
        message_vision(HIC "$Nҡҡͷ�����㻹��������!\n" NOR,mee);
        return;
        }
        if (ob->query("combat_exp")<10000)
        {
        message_vision(HIC "$n��$Nҡͷ�������ʵս����̫�͡�\n" NOR,ob,mee);
        return;
        }
                command("smile");
                command("handshake "+this_player()->query("id"));
                command("nodjoin "+this_player()->query("id"));
                command("tell "+this_player()->query("id")+" ��ҴӴ˾���һ�����ˡ�\n");
        return;
}

