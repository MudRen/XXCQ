// qi.c ����ϼ


inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include "/kungfu/class/fameng/sandai.h"

int ask_quit( );
void create()
{
	set_name("����ϼ", ({ "qi lianxia", "qi" }));
	set("nickname",HIR"����������"NOR);
         set("rank","����");
	set("gender", "Ů��");
	set("age", 23);

        set("combat_exp", 300000);
          set_skill("tao",80);
          set_skill("parry",80);
          set_skill("cuff",80);
          set_skill("force",80);
          set_skill("dodge",80);
          set_skill("bairen-shengong",80);
          set_skill("fengye-xiangsi",80);
          set_skill("yiye-zhiqiu",80);
        
        map_skill("force","bairen-shengong");
          map_skill("dodge","fengye-xiangsi");
          map_skill("cuff","yiye-zhiqiu");
          map_skill("parry","yiye-zhiqiu");

          prepare_skill("cuff","yiye-zhiqiu");
	
        create_party(HIG"���ζ���"NOR,HIM"��Ժ"NOR,2);
        create_family("���ζ���",3,"����");
        set("inquiry", ([
                "�˳�" : (: ask_quit :),
                "quit" : (: ask_quit :),
        ]) );
	setup();
        set("chat_chance",1);
	set("chat_msg",({
                "����ϼ˵����ֻҪ��Ϊ��Ϊ�������֮ʿ�������Լ������Ƿ��ζ�����\n",
                "����ϼ˵������������ٳ���Ҫ���ˣ��⼸���������ӡ���Ҫ�úö��š�\n",
	}));
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
/*
	object ob;
       object *obb;
       mapping fam,party;
       mapping myfam,myparty;
       int i;
      object me=this_player();
	if( interactive(me) && me->query_temp("killwei") && (file_name(environment(me))=="/d/huafu/menfang") ) {
       fam=(mapping)me->query("family");
       party=(mapping)me->query("party");
        message_vision(HIG"ͻȻ��·�ߵ�����ವķɳ�һö�����\n"NOR,me);
       obb=users();
	for(i=0; i<sizeof(obb); i++) {
	myfam=(mapping)obb[i]->query("family");
	myparty=(mapping)obb[i]->query("party");
	if ((myfam && myfam["family_name"]=="���ζ���") || (myparty && myparty["party_name"]==HIG"���ζ���"NOR) )
      {
       if (fam)
       {
                tell_object(obb[i],HIC"���ζ�������"+fam["family_name"]+"��Ϯ�����������ٻر������ء�\n"NOR);
         }
        if (party)
         {
                tell_object(obb[i],HIC"���ζ�������"+party["party_name"]+"����Ϯ�����������ٻر������ء�\n"NOR);
         }
         obb[i]->set_temp("compaign_start",1);
        }
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
        message_vision(HIC "����ϼ���������ȶ�ס����ȥ����!\n" NOR,this_player());
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
*/

}

void attempt_join()
{
        object ob;
        object mee;
        
        ob = this_player () ;
        mee=this_object();
        if ((int)ob->query("shen") < 0)
        {
        message_vision(HIC "����ϼ��$N��ŭ����һ����Ͳ��Ǻ���!\n" NOR,this_player());
//      set_leader(this_player());
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, this_player()); 
        return;
        }
        if(ob->query("party"))
        {
        command("say ���Ѿ��������������ˣ�����������!\n");
        return;
        }
        if ((int)ob->query("shen") < 1000)
        {
        message_vision(HIC "����ϼҡҡͷ�����㻹��������!\n" NOR,this_player());
        return;
        }
        if (ob->query("combat_exp")<10000)
        {
        message_vision(HIC "����ϼ��$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
        return;
        }
                command("smile");
                command("handshake "+this_player()->query("id"));
                command("nodjoin "+this_player()->query("id"));
                command("tell "+this_player()->query("id")+" ��ҴӴ˾���һ�����ˡ�\n");
        return;
}
     int ask_quit( )
    {
     if (this_player()->query("party/party_name")==HIG"���ζ���"NOR)
       {
        command("dao");
        command("heng "+this_player()->query("id"));
        this_player()->delete("party");
        return 1;
        }
        else 
          { command("say �㲻�Ƿ��ε�����ʲô��?\n");
          command("say ����"+this_player()->query("party/party_name")+",�������ʲô��?\n");
          return 1;
        }
     }
