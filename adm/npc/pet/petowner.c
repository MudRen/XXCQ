// ���۳����С�� NPC
// By ɽèAdx @ snow 99-12-12

#include <ansi.h>
inherit NPC;

int do_answer(string arg);
int pet_type(object me, string arg);
int pet_gender(object me, string arg);

void create()
{
        set_name("С��", ({ "xiaofan" }) );
        set("gender", "����" );
        set("age", 32);
        set("long","һ��ר���������С��\n");
        set("combat_exp", 5);
        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_answer","answer");
}

void greeting(object ob)
{
	object obj;
        if( !ob || environment(ob) != environment() ) return;

	if(!ob->query("pet") && !present("pet book",ob)) {
		obj=new(__DIR__"petbook");
		obj->move(ob);
		message_vision("$N����$nһ�������������\n",this_object(),ob);
	}
        switch( random(3) ) {
                case 0:
			command("say ��λ"+RANK_D->query_respect(ob)
                                + "��Ҫ��ֻ����ô��ÿֻһ�����ƽ�");
                        break;
                case 1:
			command("say ���۳���������Сè��С����"
				+"С��С�����Сӥ��ÿֻһ�����ƽ�");
                        break;
                case 2:
			command("say ��λ"+RANK_D->query_respect(ob)
                                + "����ֻ����ɣ�ÿֻһ�����ƽ�");
                        break;
        }
}

int accept_object(object me, object ob)
{
	command("xixi");
	command("say �Ǻǣ���л��λ" + RANK_D->query_respect(me) + " ��");
    if(me->query("combat_exp")<100000||me->query("wizsong")==1)
		return notify_fail("���ʵս���鲻����ר�������Ժ���������ɣ�\n");
	if( ob->query("money_id"))
	{
		if(me->query("pet"))
		{
			command("say "+me->query("name")+ 
				"�㲻���Ѿ��г���������ô��ϲ����");
			return 0;
		}
		if(ob->value() < 1000000)
		{
			command("say ��λ����δ�����˵㣡ÿֻ����Ҫһ�����ƽ�");
			return 0;
		}
		else
		{
			me->set("pet/money",1);
			command("say ���������ˣ�");
			command("say "+me->query("name")
				+"�����������У�Сè��С����С��С�Сӥ�⼸�ֳ��");
			command("say ��ѡ����Ҫ�Ķ��� answer <type>");
			return 1;
		}
	}
	return 1;
}

int do_answer(string arg)
{
	object me=this_player();
	int i=me->query("pet/money");

	if (! arg || arg == "")
	{
		command("say ��λ"+RANK_D->query_respect(me)+"��ÿֻ����һ�����ƽ�");
		return 0;
	}

	switch(i) {
	case 1 : pet_type(me, arg); break;
	case 2 : pet_gender(me, arg); break;
	default: command("say ��λ"+RANK_D->query_respect(me)+"��ÿֻ����һ�����ƽ�");
	}
	return 1;
}

int pet_type(object me, string arg)
{
	string msg, msgid;
	msg=me->query("name")+"�ĳ���";
	msgid=me->query("id")+"'s ";

        switch( arg ) {
                case "Сè":
			me->set("pet/type", "cat");
			me->set("pet/name",(msg+"è"));
			me->set("pet/id",(msgid+"cat"));
			break;
                case "С��":
			me->set("pet/type", "dog");
			me->set("pet/name",(msg+"��"));
			me->set("pet/id",(msgid+"dog"));
			break;
                case "С��":
			me->set("pet/type", "pig");
			me->set("pet/name",(msg+"��"));
			me->set("pet/id",(msgid+"pig"));
			break;
                case "С��":
			me->set("pet/type", "monkey");
			me->set("pet/name",(msg+"��"));
			me->set("pet/id",(msgid+"monkey"));
			break;
                case "Сӥ":
			me->set("pet/type", "hwak");
			me->set("pet/name",(msg+"ӥ"));
			me->set("pet/id",(msgid+"hawk"));
			break;
		default:
			command("say "+me->query("name")
				+"������ֻ�У�Сè��С����С��С�Сӥ�⼸�ֳ��");
			break;
	}
	me->set("pet/money", 2);
	command("say Ŷ��"+me->query("name")+"����Ҫֻ"+arg+"��");
	command("say ���ѡ����ĳ����Ա�answer <����> or <����>");
	return 1;
}

int pet_gender(object me, string arg)
{
        switch( arg ) {
                case "����":
			me->set("pet/gender", arg);
			command("say Ŷ��"+me->query("name")+"����Ҫ���Եĳ��");
			break;
                case "����":
			me->set("pet/gender", arg);
			command("say Ŷ��"+me->query("name")+"����Ҫ���Եĳ��");
			break;
		default:
			command("say ���ѡ����ĳ����Ա�answer <����> or <����>");
			break;
	}
        me->start_busy(2);
	me->set("pet/path",("/data/pet/"+me->query("id")+".o"));
	me->set("pet/money", 3);
	call_out("grow", 1, me);
	return 1;
}

int grow(object me)
{
	object newpet;
	if (me->query("pet/money")!=3) return 1;
	me->set("pet/money","ok");
	seteuid(ROOT_UID);
	newpet = new("/adm/npc/pet/pet");
	newpet->set("owner",me->query("id"));
	newpet->set("possessed",me);
	newpet->set("name",me->query("pet/name"));
	newpet->set("id",me->query("pet/id"));
	newpet->set("gender",me->query("pet/genter"));

        switch( me->query("pet/type") ) {
                case "cat":
			newpet->set("str",random(20)+10);
			newpet->set("int",random(20)+10);
			newpet->set("con",random(20)+10);
			newpet->set("dex",random(20)+10);
			newpet->set("kar",random(40)+10);
			break;
                case "dog":
			newpet->set("int",random(20)+10);
			newpet->set("con",random(20)+10);
			newpet->set("dex",random(20)+10);
			newpet->set("kar",random(20)+10);
			newpet->set("str",random(40)+10);
			break;
                case "pig":
			newpet->set("str",random(20)+10);
			newpet->set("int",random(20)+10);
			newpet->set("dex",random(20)+10);
			newpet->set("kar",random(20)+10);
			newpet->set("con",random(40)+10);
			break;
                case "monkey":
			newpet->set("str",random(20)+10);
			newpet->set("con",random(20)+10);
			newpet->set("dex",random(20)+10);
			newpet->set("kar",random(20)+10);
			newpet->set("int",random(40)+10);
			break;
                case "hwak":
			newpet->set("str",random(20)+10);
			newpet->set("int",random(20)+10);
			newpet->set("con",random(20)+10);
			newpet->set("kar",random(20)+10);
			newpet->set("dex",random(40)+10);
			break;
	}
        switch( me->query("pet/gender") ) {
                case "����":
			newpet->set("max_jingli",(random(100)+100));
			newpet->set("max_qi",(random(100)+100));
			newpet->set("xing",(random(500)+100));
			newpet->set("kill",random(500));
			break;
                case "����":
			newpet->set("max_jingli",(random(200)+100));
			newpet->set("max_qi",(random(200)+100));
			newpet->set("xing",(random(500)+300));
			newpet->set("kill",random(1000));
			break;
	}
	newpet->save();
	destruct(newpet);
	command("say ����Դ��������ٻ���ĳ��<whistle>\n");
        seteuid(getuid());
	return 1;
}
