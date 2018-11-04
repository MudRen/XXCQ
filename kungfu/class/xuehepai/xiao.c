// made by lks

#include <ansi.h>
#include "/kungfu/class/xuehepai/xiaojob.h"

inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_me1();
int ask_job();
#include "/kungfu/class/xuehepai/xiao.h"
#include "/kungfu/class/xuehepai/cloth.h"
void heal_ob();
void recover_ob();

void create()
{
        set_name("������",({"xiao xiaotian","xiao"}));
        set("nickname",HIR"��ڤѪū"NOR);
	set("gender","����");
	set("int",30);	
	set("con",30);
	set("str",30);
	set("dex",30);
	set("bac",40);
	set("age",40);
	set("attitude","friendly");
        set("combat_exp",500000);
        set("kill",1000);
	set("long",
"Ӣ������,��ʼ�տ�����һ�����֣����Ҳѳ���ˡ�\n"
	);
        set("neili",2000);
        set("jingli",1800);
        set("max_neili",2000);
        set("max_jingli",1800);
        set_skill("literate",100);
        set_skill("cuff",150);
        set_skill("parry",150);
        set_skill("dodge",150);
        set_skill("youran-bu",150);
        set_skill("xuehe-jian",150);
        set_skill("sword",150);
        set_skill("force",150);
        set_skill("tao",100);
        set_skill("feixue-quan",150);
        set_skill("throwing",150);
        set_skill("huaxue-shenzhen",150);
        set_skill("huaxue-dafa",150);
        map_skill("force","huaxue-dafa");
        map_skill("dodge","youran-bu");
        map_skill("cuff","feixue-quan");
        map_skill("sword","xuehe-jian");
        map_skill("throwing","huaxue-shenzhen");
        prepare_skill("cuff","feixue-quan");
	
       create_family("Ѫ����",13,"����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/longmen/xuehepai/obj/zhen")->wield();
        set("chat_chance", 2);
	set("chat_msg", ({
		(: heal_ob :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: exert_function, "xisui" :),
                (: exert_function, "xuewu" :),
                (: recover_ob :),
	}) );
       set("inquiry",([
              "Ѫ��" : (: ask_me :),
              "job" : (: ask_job :),
              "xueyi" : (: ask_me :),
              "cancel" : (: ask_me1 :),
       ]));
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
           object ob;
           mapping fam;

           object me=this_player();

           fam=(mapping)me->query("family");

           if (!fam || fam["family_name"]!="Ѫ����")
           {
                  command("say ���뱾�ɲ��޹ϸ𣬴˻��Ӻ�˵��");
                  return 1;
           }
           if (me->query("combat_exp")<300000)
           {
                  command("say ���ʵս����̫���ˡ�");
                  return 1;
           }
             if (me->query("max_neili")<300)
           {
                  command("say ���������Ϊ̫���ˡ�");
                  return 1;
           }
           if (query("yi"))
           {
                 command("say Ѫ���Ѿ��������ˡ�");
                 return 1;
            }
                  command("say �ðɣ��Ұ�Ѫ�����㡣");
                    set("yi",1);
                  ob=new("/d/longmen/xuehepai/obj/xueyi");
                  ob->move(me);
                  return 1;
}

int ask_job()
{
        object me;
        object ob;
        mapping myfam;
        me=this_player();

        myfam=me->query("family");
        
        if ( !myfam || myfam["family_name"] != "Ѫ����" )
        {
                command("say "+RANK_D->query_respect(me)+"������Ѫ���ɵĵ��ӣ������������ͷ����أ�");
                return 1;
        }
        
        if (me->query_temp("job_start"))
        {
                command("say ���Ѿ��й����ˣ�������ȥ��");
                return 1;
        }
        
          if (me->query("combat_exp")>40000)
        {
                command("say "+RANK_D->query_respect(me)+"����ʱ�����书�ˣ���ЩС�¾Ͳ����鷳���ˡ�");
                return 1;
        }
        
        tell_object(me,"�ð�,��˵��ɽɽ���ϵ�ʯͷ���ʲ���\n");
        tell_object(me,"��ȥ��һ���������Ҫ��һЩ������\n");
         if (!(ob=present("hammer",me)))
         {
         ob=new("/kungfu/class/xuehepai/obj/hammer");
         ob->move(me);
           }
        me->set_temp("job_start",1);
        return 1;
}


int ask_me1()
{
                object me;
                mapping family;

                me=this_player();
                family=(mapping)me->query("family");

                if ( !family || family["family_name"]!="Ѫ����")      return 0;
            if (me->query_temp("job_start"))  {
                      command("poor "+me->query("id"));
                           command("say �ðɣ� �ٸ�"+me->query("name")+"��һ�λ���ɡ�");
                           me->add("combat_exp",-(me->query("combat_exp")/1000));
                           me->add("potential",-(me->query("potential")/1000));
                           me->delete_temp("find");
                      return 1;
           }
           return 0;
}


