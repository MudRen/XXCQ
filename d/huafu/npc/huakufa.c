// huakufa.c ���ݷ�
// made by lks

#include <ansi.h>
int ask_ye();
#include "/d/huafu/npc/cam.h"

inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/fameng/yidai.h"
void heal_ob();
void recover_ob();

void create()
{
        set_name("���ݷ�",({"hua kufa","hua"}));
        set("nickname",HIG"����"HIW"---"HIR"�󵱼�"NOR);
	set("gender","����");
	set("int",30);	
	set("con",30);
	set("str",30);
	set("dex",30);
	set("bac",40);
	set("age",40);
	set("attitude","friendly");
	set("shen_type",1);
	set("combat_exp",800000);
	set("score",1000);
	set("long",
	"�����ǻ���������---���ݷ���\n��Ȼ�������γɳ��ֱ�Ť������һ������ʲô�£����ǻ���һ�¶���ġ�"
	);
	set("neili",2000);
	set("jingli",1000);
	set("max_neili",2000);
	set("max_jingli",1000);
           set_skill("literate",280);
           set_skill("cuff",350);
           set_skill("dodge",350);
           set_skill("force",250);
           set_skill("bairen-shengong",250);
           set_skill("tao",350);
         set_skill("fengye-xiangsi",350);
           set_skill("parry",350);
           set_skill("throwing",350);
        set_skill("yiye-zhiqiu",250);
             map_skill("force","bairen-shengong");
             map_skill("dodge","fengye-xiangsi");
	map_skill("cuff","yiye-zhiqiu");
        prepare_skill("cuff","yiye-zhiqiu");
	
       create_family("���ζ���",1,"��ɽ��ʦ");
	setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/huafu/npc/obj/yeziye");
        carry_object("/d/huafu/npc/obj/bajiaoye");
         set("chat_chance", 1);
	set("chat_msg", ({
		"���ݷ������ؿ��˿���ɫ�����ҵ�Կ�ײ�֪������ȥ�ˣ�\n",
		"���ݷ�һ���Ŀ�ɥ�ࣺ�����ҿɵ���ȥ˯������\n",
		(: heal_ob :),
	}));
                set("inquiry",([
                        "����" : (: ask_ye :),
                        "yezi" : (: ask_ye :),
                ]));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: perform_action, "cuff.kuangfeng" :),
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

int ask_ye()
{
        object ob,me;
        mapping fam;
        
        me=this_player();
        fam=(mapping)me->query("family");
        
        if (!fam || (fam["family_name"]!="���ζ���"))
        {
                command("say �㲻�Ǳ�����ϵ���ӣ�Ҫ����ɶ��");
                return 1;
        }

        if (query("gived"))
        {
              command("say Ҷ���Ѿ������ˡ�");
              return 1;
        }

         if (fam && (fam["generation"]>3))
        {
                command("say ��ô��Ҫ�Ķ�����ֻ�ܸ������ŵĵ���,��ı��ֻ�������");
                return 1;
        }
        
        if (me->query("shen")< 1000)
        {
                command("shake");
                command("say �������̫���ˣ��Ҳ����Ľ����㡣");
                return 1;
        }                
        command("smile "+me->query("id"));
        command("say �ðɣ��Ұ�ΪһҶ֪�����Ƶ�Ҷ�Ӹ��㣬\n����������ǿһҶ֪���ɱ������");
        ob=new("/d/huafu/npc/obj/bajiaoye");
        ob->move(me);
        ob=new("/d/huafu/npc/obj/yeziye");
        ob->move(me);
           set("gived",1);
        return 1;
}

