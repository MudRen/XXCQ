// liu.c ���Ǹ� 

#include <ansi.h>

inherit F_PAWN;

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

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}

int accept_object(object who, object ob)
{
	object obj, sil;
	obj = this_object();

	if ((string)ob->query("id") == "dan") 
	{
		message_vision("$N�ѵ��ӵݸ�"+obj->query("name")+"���顣\n", who);
		if ((string)who->query_temp("goods") != obj->query("name"))
		{
			command("? "+who->query("id"));
			command("say ���"+ob->query("name")+"�������������ѽ��");
			command("say �㻹�ǵ���ĵط�ȥ���Ұɡ�");
			command("give dan to "+who->query("id"));
			return 0;
		}
		else if (!(string)who->query_temp("buygoods") || (string)who->query_temp("buygoods") != "begin")
		{
			command("? "+who->query("id"));
			command("say ����Ȼ����������ģ����ǡ�������Ų������İɡ�");
			command("say ���ŵ��������������ˣ�ʡ�ù˿�����ʧ��лл���ˡ�");
			return 1;
		}
		else
		{
			command("say ̫���ˣ�̫���ˣ����������ˣ�");
			message_vision(obj->query("name")+"�ù�һ�������˵��ϻ������£�Ȼ������������\n", who);
			message_vision(obj->query("name")+"ת�˽�ȥ��һ�����һ����ƿ�����һ���������\n", who);
			message_vision(obj->query("name")+"Ц��Ц˵����������ǽ�®�Ļ������պá�\n", who);
			sil = new("/d/huanhua/npc/obj/huo");
			sil->set("name", "�䵱Ʒ");
			sil->set("long", "���Ǵӱ���������صĵ䵱Ʒ��");
			sil->move(who);
			who->set_temp("buygoods", "over");
			return 1;
		}
	}
	else
	{
		command("say ����������ʲô?");
		return 0;
	}
}

