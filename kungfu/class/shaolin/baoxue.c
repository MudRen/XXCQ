// bao.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("��ѩ", ({ "bao xue", "xue" }) );
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

        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, this_player());
        if(this_player()->query("title")=="���ֳ���")
          return;
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
	 return 1;
	}

  if(fam["master_name"] != "������ʦ")
  {
  return 1;
}
	COMBAT_D->do_attack(me, ob, query_temp("weapon") );
	if (ob->query("qi") < ob->query("max_qi")/4)
	  {
	     return 1;
	  }
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
	     return 1;
	  }
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
	     return 1;
	  }
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

	message_vision(HIB"ֻ��"+me->query("name")+"��˫��һ�ƣ�һ������������������!\n",ob);
	message_vision(CYN"һ�������"+me->query("name")+"����һ�ӣ�����ĵ��˵�ͷ��\n"NOR,ob);
	ob->set_skill("huaibao-tianxia",30);
	name = ob->query("name");
	new_name = "��" + name[2..3];
	ob->set("name", new_name);
}

