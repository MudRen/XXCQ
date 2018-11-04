// ding.c �Ҷ�

inherit NPC;
#include <ansi.h>
int accept_object(object who, object ob);
int ask_job();
int ask_enter();

void create()
{
	set_name("���ϰ�", ({ "cheng laoban", "cheng", "laoban" }));
	set("age", 25);
	set("gender", "����");
	set("nickname", HIY"��ǧ��"NOR);
	set("title","����Ǯׯ�ƹ�");
	set("long", "����һ�������������ˣ���������¶��ȴ�������ǽƻ������Ǵ�����\n");
	set("attitude", "peaceful");
	set("combat_exp", 20000);
	set("shen", -5000);

	set("str", 20);
	set("int", 12);
	set("con", 24);
	set("dex", 24);
	set("bac", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jingli", 600);
	set("max_jingli", 600);
	set("neili", 500);
	set("max_neili", 500);
	set("rank", "����");

	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60); 
	set_skill("parry", 60); 
	set_skill("stick", 60); 
	set_skill("confu", 30); 
	set_skill("literate", 90); 

    create_party("Ȩ����","����",1);

//	carry_object("/clone/misc/cloth")->wear();
//	carry_object(__DIR__"obj/tiecheng")->wield();

        set("inquiry", ([
                "job" : (: ask_job :),
        ]) );

        set("inquiry", ([
                "enter" : (: ask_enter :),
                "job" : (: ask_job :),
                "����" : (: ask_enter :),
        ]) );
	setup();
}

void attempt_join(object ob)
{
	if (ob->query("family")&&ob->query("family/family_name")=="佻�����")
	{
		command("say �Ǻǣ����˸���Ͷ�����ģ�����������");
		this_object()->kill_ob(ob);
		ob->kill_ob(this_object());
		return;
	}
	if (ob->query("shen")>0)
	{
		command("hmm");
		command("say ��������������ʿ����μӱ��Ī���������Ե͵İɣ�");
		return;
	}
	else if (ob->query("combat_exp")<10000)
	{
		command("shake");
		command("say �㹦����ô���ôΪ����Ч��?�������˰ɡ�");
		return;
	}
        else if (ob->query("party"))
        {
            command("say ���Ѿ��а����ˣ����������㰡!\n");
            return;
        }
    else if (ob->query("kill")<0)
	{
		command("say ��˹˹���ģ���ô�������ɱɱ�Ĺ������������˰ɡ�");
		return;
	}

	command("say �ðɣ�" + RANK_D->query_respect(ob) +"��ȻԸ�⣬�Ҿ��汾���������ˡ�");
	command("nodjoin " + ob->query("id"));

	return;
}

int ask_job()
{
    mapping quest;
	object me, ob;

	me = this_player();
	quest = __DIR__"quest/jyquest"->query_quest();

    if ( !((mapping)me->query("party")) || (string)me->query("party/party_name") != "Ȩ����" )
	{
		command("look "+me->query("id"));
		command("say ��ʲô��˼�����ǲ����뵽�����������ң�");
		return 1;
	}

	else if (me->query_temp("qljob") && me->query_temp("qljob") == 1)
	{
		command("hmm");
		command("say �ǲ��Ƕ԰��ɸ���Ĺ��������⣿�ߣ�");
		return 1;
	}

        else if ( me->query_condition("jyfail") )
        {
                command("say ����Ҫ���ʶ�Ҫ�������ֲ���ɱ�ˣ��һ���ô�������£�");
                command("say �㻹��ȥ�ɣ�ʡ�����ǽ���ɽׯ���������㶪���ˣ�");
                me->delete_temp("qljob");
                me->delete_temp("money");
                me->delete_temp("subject");
                return 1;
        }
	else if (me->query_temp("qljob") && me->query_temp("qljob") == 4)
	{
		command("jump");
		command("say �ɵĺã���������Ǯׯ�����磬��ȥЪЪ�ɣ�");
		me->add("potential", 80+random(80));
		me->add("combat_exp", 100+random(100));
		me->add("party/tasks", 2);
		me->delete_temp("qljob");
		me->delete_temp("subject");
		me->delete_temp("money");
		return 1;
	}

	else if ( me->query_condition("jyfail") )
	{
		command("say ����Ҫ���ʶ�Ҫ�������ֲ���ɱ�ˣ��һ���ô�������£�");
		command("say �㻹��ȥ�ɣ�ʡ�����ǽ���ɽׯ���������㶪���ˣ�");
		me->delete_temp("qljob");
		me->delete_temp("subject");
		me->delete_temp("money");
		return 1;
	}
	else if ( me->query_temp("qljob"))
	{
		command("say �����ʲ���Ǯ���ǲ���������ѽ��");
		return 1;
	}

	command("say " + quest["quest_1"] + "Ƿ����Ǯׯ" + chinese_number(quest["quest_2"]) + "�����ӣ���ȥҪ�����ɡ�");
	command("say ����Ƿ�����ã����Ǳ·ϻ���ֱ������(shouzhang)��");
	command("say ���" + quest["quest_1"] + "���Ų�������ɱ��������������Ǯׯ�����硣");

	me->set_temp("qljob", 1);
	me->set_temp("subject", quest["quest_3"]);
	me->set_temp("money", quest["quest_2"]);
	ob = new("/d/quanli/npc/obj/qiandan");
	ob->set("long", "
	Ƿ��
" + quest["quest_1"] + "Ƿ����ɽׯ" + chinese_number(quest["quest_2"]) + "��������
��˵��ƾ������Ϊ֤��

	���Ϻ�������ɽׯ\n");
	ob->move(me);
	return 1;
}

int accept_object(object who, object ob)
{

	if (ob->query("money_id")) 
	{
		if (who->query_temp("qljob") && (who->query_temp("qljob") == 1))
		{
			command("say ���Ǯ�Ҿ������ˣ�������Ļ�ȴû�����꣡");
			command("say ������ȥ����");
			return 1;
		}
		else if (who->query_temp("qljob") && (who->query_temp("qljob") == 2 ||who->query_temp("qljob") == 5))
		{
			command("say �Լ��ղ����ʻ������ң��㵱����˭��");
			command("say ���Ǯ������Т���ҵģ����������ٽ��㡣");
			who->delete_temp("qljob");
			who->delete_temp("subject");
			who->delete_temp("money");
			return 1;
		}
		else if (who->query_temp("qljob") && who->query_temp("qljob") == 3 && ob->value() >= (100 * who->query_temp("money")))
		{
			command("say �������ɵ�ȷʵ������ȥ��Ϣ�ɡ�");
			message_vision("���ϰ����ʵ��ϼ���һ�ʣ�Ȼ���Ǯ�Ž���Ǯ��\n", who);
			who->add("potential", 60+random(60));
			who->add("combat_exp", 80+random(80));
			who->add("party/tasks", 1);
			who->delete_temp("qljob");
			who->delete_temp("subject");
			who->delete_temp("money");
			return 1;
		}
		else if (who->query_temp("qljob") && who->query_temp("qljob") == 3 && ob->value() < (100 * who->query_temp("money")))
		{
			command("say ��������ôһ��Ǯ�����������Ǯ�����˰ɣ�");
			command("say �������ǻ�Ĳ��ͷ��ˡ�");
			return 1;
		}
		else return notify_fail("��������ʦû���뵽���������֪ͨ��ʦ�ɡ�\n");
	}
	else
	{
		return notify_fail("����������ʲô?\n");
	}
}
int ask_enter()
{
object me = this_player();
if(me->query("party/party_name") == "Ȩ����")
{
    command("say ��Ȼ�Ǳ�����������!\n");
    me->move("/d/quanli/damen");
  return 1;
}
command("say �㲻�Ǳ�����˾Ͳ��ܽ�ȥ!\n");
command("heng");
return 1;
}
