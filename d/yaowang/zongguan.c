// NPC ҩ���� �ܹ�
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
#ifndef NPCDATA
#define NPCDATA "/d/yaowang/npc/"
#endif
#define MENGZHU NPCDATA + "zongguan"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
inherit F_SAVE;

string query_save_file()
{
	return MENGZHU;
}

void create()
{
	seteuid(getuid());

	if (!restore()) {
	set_name("�ܹ�", ({ "zongguan", "zong", "guan" }) );
	set("title", HIB"ҩ����"NOR+HIW"�ܹ�"NOR);
	set("gender", "����" );
	set("age", 40);
	set("attitude", "heroism");
	set("generation",0);
	set("winner","NONE");

	set("no_clean_up",1);

	set_skill("healing", 100);
	setup();
	carry_object("/clone/misc/cloth")->wear();        
	}
	else {
		set("id", "zongguan");
		set_name(query("name"), ({  "zongguan", "zong", "guan" }));
        setup();
        if( this_object()->query("my_weapon") )
		carry_object(this_object()->query("my_weapon"))->wield();
        if( this_object()->query("my_armor") )
		carry_object(this_object()->query("my_armor"))->wear();        
	}
}

void init()
{
	object me, ob;
	mapping party;
	me = this_player();
	ob = this_object();

	if( ob->query_skill("healing", 1) < me->query_skill("healing", 1)
		&& me->query("party/party_name")==HIB"ҩ����"NOR
		&& me->query("party/level")>=6 )
	{
		party = allocate_mapping(4);
		party["party_name"] = HIB"ҩ����"NOR;
		party["rank"] = HIW"�ܹ�"NOR;
		party["level"] = 8;
		party["enter_time"] = time();
		me->set("party", party);

		remove_call_out("checking");
		call_out("checking", 1, me, ob);
	}
	else if(me->query("party/party_name")==HIB"ҩ����"NOR
		&& me->query("party/rank")==HIW"�ܹ�"NOR
		&& ob->query("zongguan_id")!=me->query("id") )
	{
		party = allocate_mapping(4);
		party["party_name"] = HIB"ҩ����"NOR;
		party["rank"] = HIG"����"NOR;
		party["level"] = 6;
		party["enter_time"] = time();
		me->set("party", party);
	}
//	add_action("do_ren", "����");
	add_action("do_jinzhi", "��ֹ");
	add_action("do_unjinzhi", "ͬ��");
	add_action("do_kaichu", "����");
	add_action("do_unjoin","unjoin");
}

int checking(object me, object ob)
{
	if( ob->query("zongguan_id")!=me->query("id")
		&&ob->query("name")!=me->query("name") )
		command("say ��ϲ���Ϊҩ�����ܹܣ�\n");

	ob->set_skill("healing", (me->query_skill("healing", 1)) );
	ob->set("name", (me->query("name")) );
	ob->set("zongguan_id", (me->query("id")) );
	ob->set("per", (me->query("per")) );
	ob->set("party", (me->query("party")) );
	ob->set("title", (me->query("title")) );
	save();
	return 1;
}

int do_jinzhi(string arg)
{
	object me, ob;
	mapping party;
	me = this_player();

	if( (!party=me->query("party"))
		|| (party["party_name"]!=HIB"ҩ����"NOR)
		|| this_object()->query("zongguan_id")!=me->query("id") )
		return notify_fail("����Ȩ���д˲�����\n");

	if( !arg ) return notify_fail("ָ���ʽ����ֹ <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob) return notify_fail("����û����ˡ�\n");

	if (ob==me) return notify_fail("��Ҫ��ʲô������\n");

	if(ob->query("party/party_name") == HIB"ҩ����"NOR)
		return notify_fail("�Է���ҩ�������ˣ�Ҫ�ȿ������ܽ�ֹ�����롣\n");

	if(ob->query("yaowang"))
		return notify_fail("���Ѿ�����ֹ����ҩ�����ˡ�\n");

	ob->set("yaowang",1);
	message_vision(YEL"$N������Զ��ֹ$n����ҩ���ȡ�\n"NOR, me, ob);
	return 1;
}

int do_unjinzhi(string arg)
{
	object me, ob;
	mapping party;
	me = this_player();

	if( (!party=me->query("party"))
		|| (party["party_name"]!=HIB"ҩ����"NOR)
		|| this_object()->query("zongguan_id")!=me->query("id") )
		return notify_fail("����Ȩ���д˲�����\n");

	if( !arg ) return notify_fail("ָ���ʽ��ͬ�� <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob) return notify_fail("����û����ˡ�\n");

	if(!ob->query("yaowang"))
		return notify_fail("��û�б���ֹ����ҩ���ȡ�\n");

	if(ob->query("party/party_name") == HIB"ҩ����"NOR)
		return notify_fail("�Է��Ѿ���ҩ���������ˡ�\n");

	ob->delete("yaowang");
	message_vision(YEL"$N��������$n����ҩ���ȡ�\n"NOR, me, ob);
	return 1;
}

int do_kaichu(string arg)
{
	object me, ob;
	mapping party;
	me = this_player();

	if( (!party=me->query("party"))
		|| (party["party_name"]!=HIB"ҩ����"NOR)
		|| this_object()->query("zongguan_id")!=me->query("id") )
		return notify_fail("����Ȩ���д˲�����\n");

	if( !arg ) return notify_fail("ָ���ʽ������ <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob) return notify_fail("����û����ˡ�\n");

	if (ob==me) return notify_fail("Ҫ�����Լ�����������ɵ����ɰ���\n");

	if(ob->query("party/party_name") != HIB"ҩ����"NOR)
		return notify_fail("���涺���Է��ֲ���ҩ�������ˣ���ô������\n");

	ob->delete("party");
	ob->set("yaowang",1);
	message_vision(YEL"$N���$n�����ҩ���ȣ�������Զ��ֹ$n�ټ��롣\n"NOR, me, ob);
	return 1;
}

int do_unjoin(string arg)
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if( !arg || arg!="ҩ����" )
		return notify_fail("��Ҫ�˳�ʲô��ָ���ʽ��unjoin ҩ����\n");

	if( ob->query("party/party_name") != HIB"ҩ����"NOR )
	{
		message_vision(CYN"$N��$n˵�����㲻����ҩ���ȵ��˲����˳���\n"NOR,me,ob);
		return 1;
	}
		ob->delete("party");
		command("sigh "+ob->query("id"));
		command("say �ðɣ�"+ob->query("name")+"�˳���ҩ���ȣ�");
		return 1;
}
