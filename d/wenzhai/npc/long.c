// long.c ������
// mlf���,lks ���

#include <ansi.h>

inherit NPC;
#include "/kungfu/class/fameng/erdai.h"
inherit F_MASTER;

void create()
{
	set_name("������",({"long tuzhu","long"}));
	set("nickname",HIC"����ƽ��"NOR);
	set("gender","����");
	set("attitude","peaceful");
	set("age",33);
        set("combat_exp",1000000);
	set("max_qi",1000);
	set("max_neili",1500);
        set("max_jingli",1500);
        set("eff_jingli",1500);
        set("jingli",1500);
        set_skill("tao",200);
        set("neili",1500);
        set_skill("force",150);
        set_skill("bairen-shengong",150);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("throwing",200);
        set_skill("fengye-xiangsi",200);
       map_skill("dodge","fengye-xiangsi");
	map_skill("force","bairen-shengong");
        create_family("���ζ���",2,"����");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
                 carry_object("/d/wenzhai/npc/obj/tielianzi")->wield();
        set("chat_chance", 3);
	set("chat_msg", ({
		(: exert_function, "heal" :),
	}));
		set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );
}

/*
void init()
{
        object ob;
       object *obb;
       mapping myfam,myparty;
       int i;
      object me=this_player();
        if( interactive(me) && me->query_temp("killwei") && (file_name(environment(me))=="/d/wenzhai/damen") ) {
        message_vision(HIG"ͻȻ��·�ߵ�����ವķɳ�һö�����\n"NOR,me);
       obb=users();
        for(i=0; i<sizeof(obb); i++) {
        myfam=(mapping)obb[i]->query("family");
        myparty=(mapping)obb[i]->query("party");
        if ((myfam && myfam["family_name"]=="���ζ���") || (myparty && myparty["party_name"]==HIG"���ζ���"NOR) )
    tell_object(obb[i],HIC"���ζ�������Ϯ�����������ٻر������ء�\n"NOR);
        }
        message_vision("�����ţ��ִܳ�������Ӱ����������\n",me);
        ob=new("/d/huafu/npc/menwei");
        ob->move(environment(me));
        ob->kill_ob(me);
        me->kill_ob(ob);
        ob=new("/d/huafu/npc/menwei");
        ob->move(environment(me));
        ob->kill_ob(me);
        me->kill_ob(ob);
        ob=new("/d/huafu/npc/menwei");
        ob->move(environment(me));
        ob->kill_ob(me);
        me->kill_ob(ob);
        message_vision(HIC "��������������ȶ�ס����ȥ����!\n" NOR,this_player());
        this_object()->move("/d/huafu/dongxiangfang");
      if (objectp(ob=present("tang yidu",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/huafu/dongting");
      if (objectp(ob=present("yin shengxue",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/huafu/neitang");
      if (objectp(ob=present("hua kufa",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/huafu/xixiangfang");
      if (objectp(ob=present("song zhanmei",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/wenzhai/sxge");
      if (objectp(ob=present("qing moushi",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/wenzhai/damen");
      if (objectp(ob=present("long tuzhu",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/wenzhai/neitang");
      if (objectp(ob=present("wen mengcheng",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/wenzhai/xixiangfang");
      if (objectp(ob=present("luo wuxia",environment(this_object()))));
      ob->move("/d/huafu/dating");
       this_object()->move("/d/huafu/dating");
        }
            return;
}

*/
