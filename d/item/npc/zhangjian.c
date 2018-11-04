// zhangjian.c  �ƽ�ͯ��
// Written by Doing Lu  1998/11/2

// ����ԭ�����ϣ��������
// ���ô������������������
// material1  ԭ������
// mat_attr1  ԭ����Ч����
// material2  ��������
// mat_attr2  ���ϵı������� * 2
// weight     �������� = ԭ������ * 3 ( ������������ )

inherit NPC;

#include <ansi.h>

int	ask_me(object me);
int	do_start();
int	item_temp_make(object me);

void create()
{
	set_name("�ƽ�ͯ��", ({ "zhangjian tongzi", "tongzi", "zhangjian" }));
	set("long", "���Ǹɽ��Ĵ���ӣ�ר�����콣����\n" );

	set("gender", "����");
	set("attitude", "friendly");

	set("age", 35);
	set("shen_type", 0);
	set("str", 500);	// ��ֹ�������࣬��������
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("combat_exp", 5000);

	set("inquiry", ([
		"����" : (: ask_me, this_player() :),
		"����" : (: ask_me, this_player() :),
		"����" : (: ask_me, this_player() :),
	]));

        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_start", "��ʼ");
	add_action("do_start", "start");

	remove_call_out("greeting");
	call_out("greeting", 1, this_player());
}

void greeting(object me)
{
	message_vision("�ƽ�ͯ�ӿ��˿�$N˵����������\n");
}

// �����æ��ѯ����Ϣ����ʾ�����ż�
int ask_me(object me)
{
	if (this_object()->query_temp("item/������"))
	{
		message_vision("�ƽ�ͯ�Ӳ��ͷ��Ķ�$N˵��û������æ����ô��ʲô�µȻ���˵��\n", me);
		return 1;
	}
	message_vision("�ƽ�ͯ����$N�����������ʦ�����ż�ô��û��ʦ���������Ҳ���Ϊ�����졣\n", me);
	return 1;
}

// ������Ʒ��
// ����������죬��������Ʒ
// ������ż��������ñ�־item/step Ϊ ����ԭ�ϣ�����ʾ����ԭ�Ϻ�����
// ����Ѿ�������item/step Ϊ ����ԭ�ϣ����ҽ��ܵ���ԭ��/���ϣ���¼������ʾ�Ƿ񽻸���
int accept_object(object me, object ob)
{
	if (this_object()->query_temp("item/������"))
	{
		message_vision("�ƽ�ͯ�Ӳ��ͷ��Ķ�$N˵��������æ�������ҡ�\n", me);
		return 0;
	}

	switch (ob->query("id"))
	{
		// �����ż�
		case "item permit":
		if (me->query_temp("item/step") == "����ԭ��")
		{
			message_vision("�ƽ�ͯ�������ɻ�Ķ�$N˵������ô����ô��ʦ�����Ű���\n", me);
		} else
		{
			me->set_temp("item/step", "����ԭ��");
			message_vision("�ƽ�ͯ�Ӷ�$N˵�����ԭ�Ϻ����ϸ��ң����׼�����ˣ����ǾͿ�ʼ(start)�ɡ�\n", me);
		}
		return 1;

		default:
		if (me->query_temp("item/step") != "����ԭ��")
		{
			message_vision("�ƽ�ͯ�Ӷ�$N˵�����Բ���ʦ�������ǲ�Ҫ���Ҫ���˵Ķ�����\n", me);
			return 0;
		}
		// ��������ԭ��
		if (ob->query("material_attrib") == "x")
		{
			if (me->query_temp("item/material1"))
			{
				message_vision("�ƽ�ͯ��ҡҡͷ˵�������û����" + 
					me->query_temp("item/material1") + "����һ�����ġ�\n", me);
				return 0;
			}
			if (me->query_temp("item/material2"))
			{
				message_vision("�ƽ�ͯ��˵�����ܺã�ԭ�����϶����ˣ������ǲ��ǾͿ�ʼ����\n", me);
			} else
			{
				message_vision("�ƽ�ͯ�ӿ��˿�˵�����ܺã�����û�����ϰ���Ҫ��û�С����ǾͿ�ʼ�ɡ�\n", me);
			}
			me->set_temp("item/material1", ob->query("name"));
			me->set_temp("item/mat_attr1", ob->query("power_point"));
			me->set_temp("item/mat_id1", ob->query("id"));
			me->set_temp("item/item_weight", ob->query_weight() * 3);
			return 1;
		}
		// ������������
		if (ob->query("material_attrib") == "z")
		{
			if (me->query_temp("item/material2"))
			{
				message_vision("�ƽ�ͯ��ҡҡͷ˵������ֻ�������ϣ���ø���ԭ�ϰ���\n", me);
				return 0;
			}
			if (me->query_temp("item/material1"))
			{
				message_vision("�ƽ�ͯ��˵�����ܺã�ԭ�����϶����ˣ������ǲ��ǿ�ʼ����\n", me);
			} else
			{
				message_vision("�ƽ�ͯ�ӿ��˿�˵�����ܺã������ԭ�ϸ��Ұɡ�\n", me);
			}
			me->set_temp("item/material2", ob->query("name"));
			me->set_temp("item/mat_attr2", ob->query("scale"));
			me->set_temp("item/mat_id2", ob->query("id"));
			return 1;
		}
		// ����ʹ�õ�ԭ��
		command("kick " + me->query("id"));
		message_vision("�ƽ�ͯ��˵���ⶫ��Ҳ���������ҹ�ª���ţ�������߾Ͱɡ�\n", me);
		return 0;
	}
}

int	do_start()
{
	object me;
	me = this_player();
	switch (me->query_temp("item/step"))
	{
		case "����ԭ��":
		if (me->query_temp("item/material1"))
		{
			message_vision("�ƽ�ͯ��˵�����ã��ҿ�ʼ�����ˣ�\n", me);
			item_temp_make(me);
			break;
		}
		message_vision("�ƽ�ͯ���۾�һ�ɣ�˵������ʼʲô����������ʲô��������\n", me);
		break;

		default:
		message_vision("�ƽ�ͯ����$N����ʲô�����ǲ��������ҺȾƣ�\n", me);
		break;
	}
	return 1;
}

int item_temp_make(object me)
{
	me->set_temp("item/step", "�������");
	this_object()->set_temp("item/������", 1);
	this_object()->set_temp("item/material1", me->query_temp("item/material1"));
	this_object()->set_temp("item/mat_id1", me->query_temp("item/mat_id1"));
	if (me->query_temp("item/material2"))
	{
		this_object()->set_temp("item/material2", me->query_temp("item/material2"));
		this_object()->set_temp("item/mat_id2", me->query_temp("item/mat_id2"));
	}
	remove_call_out("work_step_1");
	call_out("work_step_1", 3, me);
	return 1;
}

int work_step_1(object me)
{
	object ob;
	if (objectp(ob = present(this_object()->query_temp("item/mat_id1"), this_object())))
	{
		destruct(ob);
	}
	message_vision(HIY "\n�ƽ�ͯ�Ӱ�" + this_object()->query_temp("item/material1") + HIY "�Ž��˻�¯��" +
			"Ȼ��������¯�ţ��������̿���𽥽�������������\n\n" NOR, this_object());
	remove_call_out("work_step_2");
	call_out("work_step_2", 4, me);
	return 1;
}

int work_step_2(object me)
{
	message_vision(HIR "�ƽ�ͯ�Ӻ����Ķ��ŷ����������һЩ��̿�����Խ��Խ����\n\n" NOR, this_object());
	remove_call_out("work_step_3");
	call_out("work_step_3", 3, me);
	return 1;
}

int work_step_3(object me)
{
	object ob;
	message_vision(HIW "һ�ɷ�������ˮ��¯�����˳�����������һ�Ե�ģ���С�\n\n" NOR, this_object());
	if (this_object()->query_temp("item/mat_id2"))
	{
		message_vision(HIW "�ƽ�ͯ��æ��" + this_object()->query_temp("item/material2") + HIW "����ˮ�У�"
				+ "ֻ����Ȼһ�������ȵ���Һ��ҫ������Ĺ�â��\n\n" NOR, this_object());
		// �õ�����
		if (objectp(ob = present(this_object()->query_temp("item/mat_id2"), this_object())))
		{
			destruct(ob);
		}
	} else
	{
		message_vision(HIW "�ƽ�ͯ��̾�˿���������ϧû�����ϡ�\n\n" NOR, this_object());
	}
	message_vision(HIW "�ƽ�ͯ�ӺϺ�ģ�ߣ���һ��С�ĵĶ��š�\n\n" NOR, this_object());
	remove_call_out("work_step_4");
	call_out("work_step_4", 5, me);
	return 1;
}

int work_step_4(object me)
{
	object ob;
	if (! objectp(me) || ! objectp(present(me, environment())))
	{
		message_vision(HIW "�ƽ�ͯ��С������Ĵ���ģ�ߣ����˿������˵�˵�����˺��ˣ�\n\n" NOR, this_object());
		command("say �ף����أ���ô������ˣ���������Ҫ�ˡ�\n");		
		this_object()->delete_temp("item");
		if (objectp(me)) me->delete_temp("item");
		return 1;
	}
	message_vision(HIW "�ƽ�ͯ��С������Ĵ���ģ�ߣ����˿������˵�˵�����˺��ˣ�����ȥ����ʦ�������ɡ�\n\n" NOR, me);
	// ���ɴ���
	ob = new("/d/item/obj/sword_origin");
	ob->set("material1", me->query_temp("item/material1"));
	ob->set("mat_attr1", me->query_temp("item/mat_attr1"));
	ob->move(me);
	if (me->query_temp("item/material2"))
	{
		ob->set("material2", me->query_temp("item/material2"));
		ob->set("mat_attr2", me->query_temp("item/mat_attr2"));
	} else
	{
		ob->delete("material2");
		ob->set("mat_attr2", 5);
	}
	ob->set_weight(me->query_temp("item/item_weight"));
	me->delete_temp("item");
	this_object()->delete_temp("item");
	message_vision("�ƽ�ͯ�Ӱѽ���������$N��\n", me);
	return 1;
}

