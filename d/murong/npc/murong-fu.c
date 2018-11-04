// murong-fu.c  Ľ�ݸ�
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "skill.h"
int ask_fuming(string arg);
string ask_bo();
string ask_skill();
string ask_wang();
string ask_learn();
string ask_ge();
string ask_sword();
void create()
{
        set_name("Ľ�ݸ�",({"murong fu","murong","fu"}));
        set("title",HIC"�Ա�֮�� ��ʩ����"NOR);
        set("long",
              "���������ºų��Ա�֮��������֮��Ĺ���Ľ�ݸ���\n"
              "�����ϴ��Ų���һ����Ц�ݡ�\n");
        set("age", 27);
        set("attitude", "friendly");
        set("shen_type", 0);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
	set("per", 30);

        set("max_qi", 3500);
        set("max_jing", 3000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 0);
        set("combat_exp", 1000000);
        set("score", 50000);
        set("chat_msg_combat", ({
        (: perform_action, "parry.xingyi" :)
}));
        set_skill("strike",170);
        set_skill("finger",170);
        set_skill("dodge",180);
        set_skill("force", 170);
        set_skill("canhe-zhi", 160);
        set_skill("murong-jianfa",160);
        set_skill("shenyuan-gong", 160);
        set_skill("yanling-shenfa", 160);
        set_skill("xingyi-zhang",170);
        set_skill("douzhuan-xingyi", 180);
        set_skill("parry", 180);
        set_skill("sword", 160);
        set_skill("literate", 170);
        set_skill("murong-daofa", 160);
        set_skill("blade",160);

        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "yanling-shenfa");
        map_skill("strike", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
        map_skill("sword", "murong-jianfa");

        prepare_skill("finger","canhe-zhi");
        prepare_skill("strike","xingyi-zhang");

        create_family("����Ľ��",2,"����");

        set("inquiry",
                ([
                        "name" : "�����Ҿ������������ġ���Ľ�ݡ�����Ľ�ݸ���\n",
                        "here" : "�����������룬����Ľ��������ס�ڴˡ�\n",
                        "rumors" : "�Ҹ�ͻȾ�񼲣����������˼����һ�涼û���������¶������Σ�\n",
                        "����" : "�ҵĹ���ס����٢��ɽׯ�������񶴵���ѧ���龹���������ǻ�ʩˮ��\n",
                        "��ʩˮ��" : (: ask_ge :),
                        "Ľ�ݲ�" : (: ask_bo :),
                        "��ү��" : (: ask_bo :),
                        "������" : (: ask_wang :),
                        "����" : (: ask_sword :),
                        "��ѧ" : (: ask_learn :),
                        "����" : (: ask_fuming :),
                ]));
        setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_jiaoliang", "jiaoliang");
}
void attempt_apprentice(object ob)
{
        if (ob->query_skill("parry", 1) < 120)
        {
                command("say �ҹ���Ľ���Ա�֮������ʩ������м�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
		command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
                return;
        }

        if (ob->query_skill("shenyuan-gong", 1) < 100)
        {
                command("say �ҹ���Ľ���Ա�֮������ʩ������ڹ��ķ�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
		command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
                return;
        }
	if( ob->query("gender") == "����")
	{
		command("say ��������ľ��ǲ��в�Ů֮�ˡ�");
		return;
	}

	command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say �������ϣ����ҹ���Ľ���ֵ�һ���ģ�Ϊ�����Ҵ������һ��������");
        command("say ����˵��������������һ���ģ������˸�ָ�տɴ�����");
        command("say haha");
        command("recruit " + ob->query("id"));
        ob->set("title","����Ľ�ݵ���������");
}

string ask_wang()
{
	mapping fam;
	object ob;
        if (!fam = this_player()->query("family") || fam["family_name"] !="����Ľ��")
        return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        return "�������ұ��ã�����������ʩˮ������ϰ������ѧ��\n";
}


string ask_ge()
{
	mapping fam;
        object ob;
        if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
                return "��ʩˮ������Ľ���ղ������ؼ�֮���ڡ�\n";
}

string ask_sword()
{
	mapping fam;
        object ob;
        if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
                return "��������ү�����ź��������ð�������������úñ��ܣ�\n";
}

string ask_bo()
{
        mapping fam;
        if(!(fam = this_player()->query("family"))
        || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        	return "��ү����Ȼ�����ˣ���ÿ�������͵˴��������˼�ɨĹ��\n";
}

string ask_learn()
{
	object *ob;
	mapping skills = skills[random(sizeof(skills))];
	mapping fam;
	int i;
	i = 10+random(5);
	ob = all_inventory(environment(this_player()));
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��") // ������Ľ���ɵ���
		return RANK_D->query_respect(this_player()) +
		"�뱾��������������֪�˻��Ӻ�̸��";
	if( (int)this_player()->query_skill("parry", 1) < 100 ) // �мܱ�����ڵ���100��
		return RANK_D->query_respect(this_player()) +
		"�ڱ�����ѧ�в����������磬���̸������֮��ѧ��";
	if( (int)this_player()->query_skill("douzhuan-xingyi", 1) < 100 )  // ��ת���Ʊ�����ڵ���100��
		return RANK_D->query_respect(this_player()) +
		"�ڱ�����ѧ�в����������磬���̸������֮��ѧ��";
	if( this_player()->query_condition("mr_job") )
		return RANK_D->query_respect(this_player()) +
		"��û����ҽ�����������ء�";
	if( this_object()->is_fighting())
		return "��ʲô�£�û����������æ������";
	if( (int)this_player()->query_condition("wait_mr_job", 1) > 0)
		return RANK_D->query_respect(this_player()) +
		"�ȵȵȰɣ�������û��ʲô����Ȥ���书��ѧ��";
	if( this_player()->query("gender") == "����")
		return "�����������᲻�в�Ů֮�ˡ�";
	if( sizeof(ob) > 3 )
		return "����������������͵ѧ����֮��ѧ��������޺ô���";

	this_player()->set_temp("skill_target", skills["skill_name"]);  // �˱�Ǳ����˴�͵ѧĿ�꼼�ܵ���������
	this_player()->set_temp("skill_id", skills["skill_id"]); // �˱�Ǳ����˴�͵ѧĿ�꼼�ܵ�Ӣ������
	this_player()->set_temp("skill_type", skills["skill_type"]); // �˱�Ǳ����˴�͵ѧĿ�꼼�ܵ�Ӣ������
	this_player()->set_temp("skill_lvl", i); // �˱�Ǳ����˴�͵ѧĿ�꼼������Ҫ�ļ���
	this_player()->apply_condition("mr_job", 50); // ���ô˴��������������ʱ�������
        message_vision(HIG"$N���Ա��������֡�\n"NOR, this_object());
        message_vision(HIG"$N�ĵ������˹�����\n"NOR, this_player());
        message_vision(CYN"$N˵�����ҹ���Ľ�ݰ������������书����Ҳ����Ϊ֮��Ľ�ġ�\n"NOR, this_object());
        message_vision(CYN"$N����"+this_player()->name()+"�ĵ���˵��������Ҳ��ȥ��ʶ��ʶ��\n"NOR, this_object());
        new(__DIR__"job-dizi")->move(environment(this_player()));
	return "�ðɣ�"HIY+"��"+skills["skill_name"]+"��"HIR"��"+skills["skill_id"]+"��"CYN"�Ҵ����Ѿã����ǰ���ѧ�������Ҵ������͡�\n";

}

int ask_fuming(string arg)
{
       	object me, ob, obj;
	me = this_player();
	ob = this_object();
	if( !arg)
	{
        	command("say ��Ҫչʾʲô��");
        	return 1;
        }

	if( !me->query_condition("mr_job"))
	{
		command("say ������û������ɣ�");
		return 1;
	}

	if( !objectp(obj = present("dizi", environment(ob))))
	{
		command("say ��ĵ����أ�");
		return 1;
	}

	if( objectp(obj = present("dizi", environment(ob))) && obj->query("family/master_id") != me->query("id"))
	{
		command("say ������Ӻ�������İɣ�");
		return 1;
	}

	if( me->is_busy())
	{
		command("say ����æ���أ���ʲô���������˵��");
		return 1;
        }

	if( me->is_fighting())
	{
		command("say ��������أ���ʲô���������˵��");
		return 1;
        }
	if( (int)obj->query_skill(obj->query_temp("skill_id"), 1) < (int)obj->query_temp("skill_lvl") )
        {
                command("say ��ѧ��ʲô�����ˣ��������һ�����");
                return 1;
        }
       	if( this_object()->is_fighting())
	{
		command("say ��ʲô�£�û����������æ������");
		return 1;
	}

        if( obj->query("id") == "dizi" && obj->query("family/master_id") == me->query("id"))
        {
        	me->start_busy(21);
         	ob->fight_ob(obj);
		message_vision("\n$N����$n�ĵ���˵������Ȼ���ǻ����ˣ��������ɣ����ù����ҿ����ɣ� "
			+ RANK_D->query_self(ob)
			+ ob->name() + "����"
			+ RANK_D->query_respect(obj) + "�ֽ̼��У�\n\n", ob, me);
		obj->fight_ob(ob);
		message_vision("\n$N�ĵ��Ӷ���$n˵�������Ӳ��ң�Ȼ���һ����ʽ��"
			+ RANK_D->query_self(obj)
			+ "����̹��Ӹ��У�\n\n", me, ob);

	        call_out("halt", 20, ob);
        	return 1;
        }
}

int halt()
{
	object me, ob;
	me = this_player();
	ob = this_object();
	command("halt");
        message_vision(CYN"\nĽ�ݸ�������Ц������\n\n"NOR, me);
	call_out("confirm", 1, me);
	return 1;
}

int confirm()
{
	object obj, me, ob;
	string name;
	int bouns;
	me = this_player();
	ob = this_object();
	obj = present("dizi", environment(ob));
	name = obj->query_temp("skill_target");
	bouns = (int)me->query_temp("skill_lvl")*5/2;
	bouns = bouns + (int)me->query_skill("douzhuan-xingyi", 1)/2;
	bouns = bouns + (int)me->query_int();
	message_vision(CYN"Ľ�ݸ���������һ�����鲻�Խ���˵������һ��"+name+"��\n"NOR, me);
	message_vision(CYN"Ľ�ݸ�������$N��ͷ����$N˵�����������ˣ���ȥ��Ϣ�ɡ�\n"NOR, me);
	me->add("combat_exp", (int)bouns*3/2);
	me->improve_skill("douzhuan-xingyi", me->query_int()*4);
	if( ((int)me->query("potential", 1)+bouns) >= (int)me->query("max_pot", 1))
	{
		me->set("potential", (int)me->query("max_pot"));
	}
        if( ((int)me->query("potential", 1)+bouns) < (int)me->query("max_pot", 1))
        {
	  	me->add("potential", bouns);
        }
	if( objectp( obj = present("dizi", environment(ob))))
  	{
  		message_vision(CYN"\nĽ�ݸ�����$N�ĵ���˵������Ҳ�����ˣ���ȥ��Ϣ�ɡ�\n\n"NOR, me);
  		message_vision(CYN"\n$N�ĵ�������һ�ݣ�˵����л��ׯ����ʦ����\n\n"NOR, me);
	     	destruct(obj);
	}
	log_file("static/TOUXUE",
        sprintf("%s %s(%s) touxue %s(%s) on %s��\n",
	this_player()->query("title"), this_player()->name(1), geteuid(this_player()),
	this_player()->query_temp("skill_target"), this_player()->query_temp("skill_id"), ctime(time()) ));
	me->delete_temp("skill_target");
        me->delete_temp("skill_id");
        me->delete_temp("skill_type");
        me->delete_temp("skill_lvl");
        me->clear_condition("mr_job");
        me->apply_condition("wait_mr_job", 5);
        return 1;
}
/*
void relay_message(string msgclass, string msg)
{
        object room;
        string *ary;
        int i;

        msg = "1\n" + msg;
        ary = explode(msg, "\n");
        room = load_object(environment(this_object())->query("dest_room"));
        for (i=1;i<sizeof(ary);i++)
        if (room) message("vision", HIY"�������롿"NOR+ary[i]+NOR+"\n", room);
}
  */