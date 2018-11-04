// liu.c ���Ǹ� 

#include <ansi.h>

inherit F_DEALER;

int redeem(string arg);

void create()
{
	set_name("���Ǹ�", ({ "liu yafu", "liu" }));
	set("title", "�����ϰ�");
	set("shen_type", 0);

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"����һ���ܺͰ�����������,��˵���ͽ����������еĽ�ʢ�ͺ��졣\n");
	set("no_get_from", 1);

	set_skill("strike", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
}

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}

int do_redeem(string target)
{
	object dest, *all;
    int i;

	all = users();

	if (!target)
		return notify_fail("������˭�� 1\n");

	for(i=0; i<sizeof(all); i++) 
	{
		if( target == (string)all[i]->id() || target == all[i]->name() )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("���Ǹ�˵���������ڲ�����Ϸ�У����������ɡ�\n");
	else if( !dest->query_temp("selled"))
		return notify_fail("���Ǹ���������ɱ����ݺ��ˣ�����ô��Ƿ���Ѻ����أ�\n");

        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	switch (MONEY_D->player_pay(this_player(), dest->query("per") * 700))
	{
	case 0:
		return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	case 2:
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
        	set_temp("busy", 1);
		message_vision("$N��$n���������һ" + dest->query("unit") + 
			dest->query("name") + "��\n", this_player(), this_object());
		dest->move("/d/city/kedian");
		dest->set("startroom","/d/city/kedian");
		dest->delete_temp("selled");
		message("vision",
			HIY "ֻ����ವ�һ����һ���������˵ļһ���컨���ϵ���������\n" NOR,
			environment(dest), dest);
		tell_object(dest, "�㱻" + this_player()->query("name") + "���˳�����\n");
	}
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

	return 1;
}

int accept_object(object who, object ob)
{
	object obj, sil;
	obj = this_object();

	if ((string)ob->query("id") == "dan") 
	{
		if ((string)who->query_temp("goods") != obj->query("name"))
		{
			message_vision("$N�ѵ��ӵݸ�"+obj->query("name")+"���顣\n", who);
			command("? "+who->query("id"));
			command("say ���"+ob->query("name")+"�������������ѽ��");
			command("say �㻹�ǵ���ĵط�ȥ���Ұɡ�");
			command("give dan to "+who->query("id"));
			return 1;
		}
		else if (!(string)who->query_temp("buygoods") || (string)who->query_temp("buygoods") != "begin")
		{
			message_vision("$N�ѵ��ӵݸ�"+obj->query("name")+"���顣\n", who);
			command("? "+who->query("id"));
			command("say ����Ȼ����������ģ����ǡ�������Ų������İɡ�");
			command("say ���ŵ��������������ˣ�ʡ�ù˿�����ʧ��лл���ˡ�");
  			destruct(ob);
			return 1;
		}
		else
		{
			message_vision("$N�ѵ��ӵݸ�"+obj->query("name")+"���顣\n", who);
			command("say ̫���ˣ�̫���ˣ����������ˣ�");
			message_vision(obj->query("name")+"�ù�һ�������˵��ϻ������£�Ȼ������������\n", who);
			message_vision(obj->query("name")+"ת�˽�ȥ��һ�����һ����ƿ�����һ���������\n", who);
			message_vision(obj->query("name")+"Ц��Ц˵����������ǽ�®�Ļ������պá�\n", who);
			sil = new("/d/huanhua/npc/obj/huo");
			sil->set("name", "�䵱Ʒ");
			sil->set("long", "���Ǵӱ���������صĵ䵱Ʒ��");
			sil->move(who);
			who->set_temp("buygoods", "over");
  			destruct(ob);
			return 1;
		}
	}
	else
	{
		command("say ����������ʲô?");
		return 0;
	}
	
}
