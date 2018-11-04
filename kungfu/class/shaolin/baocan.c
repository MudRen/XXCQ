// bao.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "bao can", "can" }) );
	set("title", "���ֳ���");
	set("gender", "����");
	set("age", 90);
	set("long",
		"����һ��������ݣ��ݹ��㶡����ɮ������ɫ�ݻƣ���ͬһ�ο�ľ��\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 1500000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("qi", 4000);
	set("max_qi", 2000);
	set("neili", 4000);
	set("max_neili", 2000);
	set("jiali", 90);

	create_family("������", 35, "����");

	set_skill("force", 220);
	set_skill("parry", 220);
	set_skill("dodge", 220);
	set_skill("unarmed", 220);

  set_skill("banruo-changong", 220);
	set_skill("shaolin-shenfa", 220);
	set_skill("huaibao-tianxia", 220);
	
	map_skill("force", "banruo-changong");
	map_skill("unarmed", "huaibao-tianxia");
	map_skill("dodge", "shaolin-shenfa");

	setup();
}

void init()
{
	object ob = this_player();

        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, this_player());
        if(ob->query("title")=="���ֳ���")
          return;
      add_action("do_yun","yun");
      add_action("do_yun","exert");
       command("chat "+ob->query("name")+"����������峤�ϵ����С�\n");
	  call_out("do_test",5,this_player());
}

void greeting(object ob)
{
	object me;
	me = this_object();
	
	if(ob->query("shen") < -10000) {
	  command("say ��а�ɹ������ô������صأ�������!\n");
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, ob);
	}
	else 
		{
		   command("say ��֪���ܲ���ѧ�����ǵĻ���������!\n");
		   command("look "+ob->query("id"));
		   command("walkby");
		}
}

int do_test()
{
	object me,ob;
	mapping fam;
	me = this_object();
	ob = this_player();
	fam = ob->query("family");

    if(!(fam = ob->query("family")) || fam["family_name"] != "������")
	{
	 command("say "+RANK_D->query_respect(ob)+"��ϧ�㲻�����ֵ���!");
	 command("sigh");
	 return 1;
	}

  if(fam["master_name"] != "������ʦ")
  {
  command("say "+RANK_D->query_respect(ob)+"�㲻���������ŵĵ��ӣ���ȥ��!\n");
  command("addoil "+ob->query("id"));
  return 1;
}
	COMBAT_D->do_attack(me, ob, query_temp("weapon") );
	if (ob->query("qi") < ob->query("max_qi")/4)
	  {
	     command("chat "+ob->query("name")+"û�н������ϵĵ�һ��!\n");
	     return 1;
	  }
	 command("chat "+ob->query("name")+"�������ϵĵ�һ��!\n");
             call_out("do_test2",5,this_player());

	return 1;
}

int do_test2()
{
	object me,ob;
	me = this_object();
	ob = this_player();

	COMBAT_D->do_attack(me, ob, query_temp("weapon") );
	if (ob->query("qi") < ob->query("max_qi")/4)
	  {
	     command("chat "+ob->query("name")+"û�н������ϵĵڶ���!\n");
	     return 1;
	  }
	 command("chat "+ob->query("name")+"�������ϵĵڶ���!\n");
             call_out("do_test3",5,this_player());

	return 1;
}

int do_test3()
{
	object me,ob;
	me = this_object();
	ob = this_player();

	COMBAT_D->do_attack(me, ob, query_temp("weapon") );
	if (ob->query("qi") < ob->query("max_qi")/4)
	  {
	     command("chat "+ob->query("name")+"û�н������ϵĵ�����!\n");
	     return 1;
	  }
	 command("chat "+ob->query("name")+"�������ϵĵ�����!\n");
             call_out("halt",5);

	return 1;
}

void halt()
{
	string name,new_name;
	object ob,me;
	ob = this_player();
	me = this_object();
	command("halt");
	if(!interactive(ob)) command("sigh "+ob->query("id"));

	command("chat* gongxi "+ob->query("id"));
	command("say ���ܽ����������������в�������ǰ;�����ǾͰѻ��������񹦴��ڸ��㡣\n"
		           "���ҿ��Ժ�����ƽ��ƽ����,����Ǳ��ֱ���!\n");
        ob->set("title","���ֳ���");
	message_vision(HIB"ֻ��"+me->query("name")+"��˫��һ�ƣ�һ������������������!\n",ob);
	message_vision(CYN"һ�������"+me->query("name")+"����һ�ӣ�����ĵ��˵�ͷ��\n"NOR,ob);
	ob->set_skill("huaibao-tianxia",30);
	name = ob->query("name");
	new_name = "��" + name[2..3];
	ob->set("name", new_name);
}

int do_yun()
{
command("say ���ﲻ���˹�!");
return 1;
}
