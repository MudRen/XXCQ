//By ɽèadx by snow 99-12-5

inherit NPC;
#include <ansi.h>

int	ask_me();
int	ask_ok();

void create()
{
        set_name("������", ({ "motobaby","moto" }));
        set("title","�����"+WHT"Сѩ������ѩɽ"+HIY"ɽ��"NOR);
        set("long", "����������ѩɽҲæ�˼�ʮ���ˣ���������Я������\n");
        set("gender", "����");
        set("age", 65);

        set_skill("dodge", 50);
        set_skill("force", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("blade", 50);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);

        set("inquiry", ([
		"job" : (: ask_me :),
		"ok" : (: ask_ok :),
        ]));
        setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	object me, ob;

	me = this_player();
	if ( !(int)me->query_temp("renwu") ) {
	switch ( random(7) ) {
	case 1 :
		me->set_temp("renwu",1);
        	ob=new(__DIR__"obj/mabu");
        	ob->move(me);
		command("say "+me->query("name")+"������Ĩ�����������Ұ�æ��������"
			+HIC+"(ca ����)\n"NOR);
		return 1;
	case 2 :
		me->set_temp("renwu",2);
        	ob=new(__DIR__"obj/hammer");
        	ob->move(me);
		command("say "+me->query("name")+"�������������������̰�æ������"
			+HIC+"(da ��)\n"NOR);
		return 1;
	case 3 :
		me->set_temp("renwu",3);
        	ob=new(__DIR__"obj/chaidao");
        	ob->move(me);
		command("say "+me->query("name")+"�����Ų񵶣����ӻ����æ����"
			+HIC+"(kan ��)\n"NOR);
		return 1;
	case 4 :
		me->set_temp("renwu",4);
        	ob=new(__DIR__"obj/shichu");
        	ob->move(me);
		command("say "+me->query("name")+"������ʯ�ƣ���ҩ���æ��ҩ��"
			+HIC+"(chong ��ҩ)\n"NOR);
		return 1;
	case 5 :
		me->set_temp("renwu",5);
        	ob=new(__DIR__"obj/shanzi");
        	ob->move(me);
		command("say "+me->query("name")+"���������ӣ�����ݰ�æ��ˮ��"
			+HIC+"(shao ˮ)\n"NOR);
		return 1;
	case 6 :
		me->set_temp("renwu",6);
        	ob=new(__DIR__"obj/caidao");
        	ob->move(me);
		command("say "+me->query("name")+"�����Ų˵�������¥��æ�вˡ�"
			+HIC+"(qie ��)\n"NOR);
		return 1;
		}
	}
	else {
		command("say "+me->query("name")+"�㻹���Ȱ���ͷ�Ļ����ɣ�\n"NOR);
		return 1;
	}
}

int ask_ok()
{
	object me;
	int amount;

	me = this_player();
	amount = random(3000);
	if ( (int)me->query_temp("renwu")==100 ) {
		me->delete_temp("wancheng");
		me->delete_temp("renwu");

		me->add("balance", amount);
		command("say �ðɣ�"+me->name()+
		"�ɵò�������"+MONEY_D->price_str(amount)+"����Ǯׯ����ʻ��ˣ�");
	}
	else {
		command("say "+me->name()+"���������ϵĻ���갡��");
		}
        return 1;
}

int recognize_apprentice(object ob)
{
        if ((int)ob->query("newbie")!=1) return 0;
        return 1;
}
