// yin.c ��ʢѩ

#include <ansi.h>

#include "/d/huafu/npc/cam.h"
inherit NPC;
inherit F_MASTER;
#include "/d/huafu/npc/yin.h"

int ask_kungfu();
void heal_ob();
void recover_ob();
void create()
{
	set_name("��ʢѩ", ({ "yin shengxue", "yin" }));
	set("nickname",HIW"��ɽ����"NOR);
         set("rank","����");
	set("gender", "����");
	set("age", 33);

        set("combat_exp", 800000);
          set("max_neili",3000);
          set("neili",3000);
          set("max_qi",3000);
          set("eff_qi",3000);
          set("qi",3000);
          set("max_jingli",3000);
          set("eff_jingli",3000);
          set("jingli",3000);
        set_skill("cuff",50 );
        set_skill("confu",150);
        set_skill("force",150);
        set_skill("dodge",150);
          set_skill("poshan-dao",350);
               set_skill("blade",350);
        set_skill("banruo-changong",150);
        
        map_skill("force","banruo-changong");
	map_skill("blade","poshan-dao");
       create_party(HIG"���ζ���"NOR,HIR"�ܽ�ͷ"NOR,5);
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/huafu/npc/obj/poshan-dao")->wield();
          set("inquiry",([
                    "��ɽ����" : (: ask_kungfu :),
                    "ѧ��" : (: ask_kungfu1 :),
                    "blade" : (: ask_kungfu2 :),
                    "����" : (: ask_kungfu2 :),
                    "����" : (: ask_kungfu :),
          ]));
          set("chat_chance",2);
          set("chat_msg",({
                 (: recover_ob :),
          }));
          set("chat_chance_combat",30);
          set("chat_msg_combat",({
                (: perform_action,"blade.shipo" :),
                (: recover_ob :),
          }));
}

void heal_ob()
{
        command("yun heal");
        return;
}

void recover_ob()
{
        command("yun recover");
        return;
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

