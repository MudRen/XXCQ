// moye.c  Īа
// Written by Doing Lu  1998/11/2

// Īа���Իش� player һЩ���⣬���ڽ��ܶ���󽻸� player һ���ż� /d/item/obj/letter
// ÿ�μ�����Ҫ���ѯ�ʹ��ı�־�����playerû��ѯ�ʹ��۸񣬲��ܽ������������û����������
// ��û������֧�����˷���ԭ��

// ��� player ����Īа���ߴ�����Īа��ʾ�㽻Ǯ�����û���㹻��Ǯ���Ͱѵ��ߴ����˸���
// ����ڼ� player ������ʱ���� item/�������� = 1, item/value = ���߼۸�
// Īа������ʱ���� item/�����˴��� = 1��item/������ID = ������ID��item/���� = ��������

// ��� player �������㹻��Ǯ������ɵ� item, �������� item/׼������ = 1
// Īа�����ʱ���� item���������������ɽ����ɸɽ�����Īа�ı��� item/�������� = 1

// �ɽ���������ߺ󣬵ȴ��û�����һЩ��Ϣ���ڴ��ڼ䣬����û�����ʱ���� item
// ��Ϊ������ʱ���� item/������Ϣ = 1
// ͬʱ���Īа����ʱ���� item/�������ƣ���Ϊ����Īа����ʱ���� item/���ڵȺ� = 1
// ֱ���û�������ϻ��������ֹ�����Īа����ʱ���� item

// ��Īа��������ʱ���� item/�������� �� item/���ڵȺ� ʱ�������� player ����Ʒ

// ���߼۸�power_point * scale / 2 * 5
// ������Ч������power_point * scale / 2���൱�ڵ��߼۸� / 5
// �˺��� = ��Ч���� * (70 - 120)%�����������ߵĺķѵ������й�

inherit NPC;

#include <ansi.h>

int	ask_me();
int	no_money();

void create()
{
	set_name("Īа", ({ "moye", "mo" }));
	set("long", "����������������һ����ʳ�˼��̻��ģ����������������ʦ�ɽ������ӡ�\n" );

	set("nickname", HIY "����" NOR);
	set("gender", "Ů��");
	set("attitude", "friendly");

	set("age", 1525);
	set("shen_type", 0);
	
	set("str", 1000);			// ��֤������Ϊ���ɹ�������ܲ��˶���

	set("inquiry", ([
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"װ��" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"װ��" : (: ask_me :),
		
		"ûǮ" : (: no_money :),
		"Ǯ����":(: no_money :),
		"�Ȼ�" : (: no_money :),

		"ԭ��" : "���Ƶ��߿ɲ���û��ԭ�ϰ���Ҫ�����������͵�������ʯһ��Ķ�����\n          Ҫ�����Ʒ��߾͵������˿��Щ��������Щԭ�Ϻ����ң����������󰡣�\n",
		"����" : "����ԭ�ϻ����첻����õĵ��ߣ������������֮Ѫ�������ϾͿ��Դ�󼤷�ԭ�ϵ�Ǳ����\n          ��Ȼ�ˣ��������������Ķ����������Ҳ����ġ���ʵ��Ѫ��һ��Ķ���Ҳ�ǿ��Ե�Ŷ��\n",
		"����" : "������٣�ֻ��Ҫ�����ƽ���������������ǰ�����ҿ���(show)���ϣ�Ҳ�ö���Ŷ��\n",
		"�۸�" : "���ԭ�Ϻ����ϸ��ҿ���(show)���Ҿ��ܹ�����һ����Ǯ��",
	]));

        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	// ���ѯ�ʱ�־
	this_player()->delete_temp("query_moye");

	add_action("do_show", "show");
	if (! this_player()->query_temp("item/��������"))
	{
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	} else
	{
		remove_call_out("greeting2");
		call_out("greeting2", 1, this_player());
	}
}

void greeting(object me)
{
	if (objectp(present(me, environment())))
	{
		message_vision("ĪаЦ�Ŷ�$N˵����ã���������������Ҫ�������˴����뽻���ҡ�\n", me);
	}
}

void greeting2(object me)
{
	if (objectp(present(me, environment())))
	{
		message_vision("Īа��$N˵����㽻Ǯ����Ҫ��û�о���˵ûǮ�\n", me);
	}
}

int do_show(string arg)
{
	object	me;
	object	ob1, ob2;
	string	mat1, mat2;
	string	msg;
	int	power_point, scale;
	int	value;
	int	n;

	me = this_player();
	if (!arg) return notify_fail("�����ʲô����Ҫ������ô��\n");

	// ȡԭ�ϣ�����
	n = sscanf(arg, "%s %s", mat1, mat2);
	if (!n)
	{
		mat1 = arg;
		n = 1;
	}
	power_point = 0;
	scale = 0;

	// ȡobject1
	if (!objectp(ob1 = present(mat1, me)))
		return notify_fail("���˰ɣ�������û�� " + mat1 + " ���ֶ�����\n");
	if (! ob1->query("material_attrib"))
	{
		message_vision("Īаһ㶣���$N˵�������ֶ���Ҳ���������ƣ���û��˵����\n", me);
	}
	if (ob1->query("material_attrib") != "z")
	{
		// ��������
		power_point = ob1->query("power_point");
	} else
	{
		// ������
		scale = ob1->query("scale");
	}

	if (n == 2)
	{
		// ȡobject2
		if (!objectp(ob2 = present(mat2, me)))
			return notify_fail("���˰ɣ�������û�� " + mat2 + " ���ֶ�����\n");
		if (! ob2->query("material_attrib"))
		{
			message_vision("Īаһ㶣���$N˵�������ֶ���Ҳ���������ƣ���û��˵����\n", me);
			return 1;
		}
		if (ob2->query("material_attrib") != "z")
		{
			// ��������
			if (power_point !=0)
			{
				message_vision("Īаҡͷ��$N�����Բ�������û����������ԭ�ϻ�������Ӧ��������������\n", me);
				return 1;
			}
			power_point = ob2->query("power_point");
		} else
		{
			// ������
			if (scale !=0)
			{
				message_vision("Īаҡͷ��$N�����Բ�������û�������������ϻ������������ԭ������\n", me);
				return 1;
			}
			scale = ob2->query("scale");
		}
	} else
	{
		// ���û�����ϣ�scale���ó�1 (�൱�ڱ�����0.5)
		scale = 1;
	}

	if (power_point == 0)
	{
		message_vision("Īа��ϸ�Ŀ��˿�$N�ó������ϣ�˵����ֻ�������Ǵ��첻�˵��ߵġ�\n", me);
		return 1;
	}
	value = scale * power_point * 5 / 2;
	if (n == 2)
		msg = sprintf("Īа��ϸ�Ŀ��˿�$N�ó���ԭ�Ϻ����ϣ�˵�������Ҫ������ԭ�Ϻ����ϴ��������\n" +
			"ֻ��Ҫ%s���ƽ���ô�������Ǽ۸�ܺ���ɡ�Ҫ��û���⣬�븶�����ƽ�������\n",
			chinese_number(value));
	else
		msg = sprintf("Īа��ϸ���˿�$N�ó���ԭ�ϣ�˵�������û�����ϣ�ֻ������ԭ�ϴ�����ߣ�\n" +
			"ֻ��Ҫ%s���ƽ���ô�������Ǽ۸�ܺ���ɡ�Ҫ��û���⣬�븶�����ƽ�������\n",
			chinese_number(value));
	message_vision(msg, me);
	me->set_temp("query_moye", 1);

	return 1;
}

// ������ʾ��Ϣ
int ask_me()
{
	message_vision("Īа��$N˵����" 
		"����Ҫ�����Լ��ĵ�����\n"
		"�����������Ϊ�����������������������������ޡ��Ⱥͻ��ף����ǵ�һ���ġ�\n"
		"���Ȱ�ԭ�����ϸ��ҿ���(show)�����ȹ���һ�¼�Ǯ��Ȼ���㽻������ң��Ҿ���\n"
		"��ȥ���ǵ��������ȴ��������Ȼ�������Ǯ���������Ǿ��ƣ�һ������������ġ�\n"
		"��Ȼ�ˣ����ǿɲ����������ԭ��Ŷ��ֻ�����Լ����������ˡ�\n", this_player());
	return 1;
}

int no_money()
{
	object ob;
	object me;
	
	me = this_player();
	if (! this_object()->query_temp("item/�����˴���") ||
	      this_object()->query_temp("item/������ID") != me->query("id"))
	{
		message_vision("Īа�۾�һ�ɣ���$N˵����ûǮ����ûǮ����ɶ�£����ֲ��ǲ���ү��\n", me);
		return 1;
	}
	me->delete_temp("item");
	if (! objectp(ob = present(this_object()->query_temp("item/����"), this_object())))
	{
		// ������ߴ��������ڣ�������ϵͳ����
		message_vision("Īа��$N˵�����Բ�����ĵ��ߴ�������Ū����...��Ǹ����...\n", me);
		this_object()->delete_temp("item");
		return 1;
	}
	this_object()->delete_temp("item");
	// �������ߴ���
	message_vision("Īа��$N˵������û��Ǯ���Ǿ����ˣ������Ȼ�����ɣ����������������ò��˵�...\n"
		       "Īа�Ѵ���������$N��\n", me);
	ob->move(me);
	return 1;
}

// ���ܶ���
int accept_object(object me, object ob)
{
	object letter;
	object ganjiang;
	object item_temp;
	string msg;
	int    val;
	if (this_object()->query_temp("item/��������"))
	{
		message_vision("Īа���ŵĶ�$N˵���𳳣��ɽ����ڸɻ��ء�\n", me);
		return 0;
	}
	if (this_object()->query_temp("item/���ڵȺ�"))
	{
		message_vision("Īа��$N˵���𳳣��ɽ����ں͹˿�̸���ء�\n", me);
		return 0;
	}
	
	if (ob->query("item_origin"))
	{
		// ���ܴ���
		if (this_object()->query_temp("item/�����˴���"))
		{
			// ����Ѿ�������һ���˵��ߴ�������ܾ�����
			message_vision("Īа��$N˵�����Բ������ȴ�������λ���˵�����˵��\n", me);
			return 0;
		}
		// �����ֵ
		val = ob->query("mat_attr1") * ob->query("mat_attr2") * 5 / 2;
		msg = sprintf("Īа��$N˵�����ܺã�����Ĳ���������Ǯ�ɣ���Ҫ%s���ƽ𣬽�Ǯ�ɡ�\n",
				chinese_number(val));
		message_vision(msg, me);
		ob->set("point", val / 5);
		ob->set("value", val * 10000);
		if (wizardp(me))
		{
			message_vision("Īа��ϸ���˿�$N��Ц��˵����ԭ������ʦ����ô����������ˡ�\n", me);
			val = 0;
		}
		me->set_temp("item/value", val * 10000);
		me->set_temp("item/��������", 1);
		this_object()->set_temp("item/�����˴���", 1);
		this_object()->set_temp("item/������ID", me->query("id"));
		this_object()->set_temp("item/����", ob->query("id"));
		// �����һ��ʱ��û�н�������ߴ���
		remove_call_out("time_out");
		call_out("time_out", 30, me, ob);
		return 1;
	}
	if (ob->query("money_id"))
	{
 		if (me->query_temp("item/��������"))
 		{
 			// ����ǽ����˴����ͽ���
 			if (this_object()->query_temp("item/������ID") != me->query("id"))
 			{
 				// �����˺͸����˶Բ��Ϻ�
 				message_vision("Īаһ���Ի�Ķ�$N˵��������ǰ��������ҵ��ߴ���������ô��һ��ӡ��û���ˣ�\n", me);
 				me->delete_temp("item");
 				return 0;
 			}
 			if (ob->value() < me->query_temp("item/value"))
 			{
	 			message_vision("Īа��$N˵���Բ��𣬱��꿪��һǧ��������û�д���ۿۡ�\n", me);
				return 0;
			}
			message_vision("Īа��$N˵�����ã���͸�������\n", me);
			this_object()->delete_temp("item/�����˴���");
			me->delete_temp("item");
			remove_call_out("time_out");
			// ����ɽ�����
			if (! objectp(ganjiang = present("ganjiang", environment())))
			{
				message_vision("Īа���˿����ܣ�����һ����˵�����ɽ��أ������ڣ�û�취����...����������ɡ�\n", me);
				command("give " + me->query("id") + this_object()->query_temp("item/����"));
				this_object()->delete_temp("item");
				me->delete_temp("item");
				return 0;
			}
			if (! objectp(item_temp = present(this_object()->query_temp("item/����"), this_object())))
			{
				message_vision("Īаһ������Ķ����أ�����ô�в����ˣ������ˡ�", me);
				this_object()->delete_temp("item");
				me->delete_temp("item");
				return 0;
			}
			// �������߸��ɽ����û�׼������
			me->set_temp("item/׼������", 1);
			message_vision("Īа��" + item_temp->query("name") + "�����˸ɽ���\n", me);
			item_temp->move(ganjiang);
			ganjiang->start_work(me, item_temp);
			return 1;
 		}
 		// ������
		if (! me->query_temp("query_moye"))
		{
			message_vision("Īа��$NЦ������ô���ͽ����𰡣������ҿ���(show)ԭ�����ϣ���Ȼ��ûǮ���ɾ��˷��ˡ�\n", me);
			return 0;
		}
 		if (ob->value() < 50000)
		{
			message_vision("Īа��$N˵���Բ��𣬶���Ҫ�����ƽ𣬱��꿪��һǧ��������û�д���ۿۡ�\n", me);
			return 0;
		}
		message_vision("Īа���˿�$N���Ķ��������˵�����ã����������ȥ�����ǵĵ��Ӵ�������ɡ�\n"
			       "Īа����$Nһ���š�\n", me);
		letter = new("/d/item/obj/letter");
		letter->move(me);
		return 1;
	} else
	{
		message_vision("Īа�۾�һ�ɣ���$N˵�����������Щ������ʲô���Ҳ�Ҫ��\n", me);
		return 0;
	}
}

int time_out(object me, object ob)
{
	// ����һ��ʱ�� player û�н���˻ش���
	if (! this_object()->query_temp("item/������ID")) return 1;
	me->delete_temp("item");
	this_object()->delete_temp("item");
	if (! objectp(me) || ! objectp(present(me, environment())))
	{
		// û����� player, ������� player ��������
		command("say ��֣��ղ���λ�����أ���ô������ˣ�\n");
		if (objectp(ob)) destruct(ob);
		return 1;
	}
	if (! objectp(ob) || ! objectp(present(ob, this_object())))
	{
		// ������ߴ��������ڣ�������ϵͳ����
		message_vision("Īа��$N˵�����Բ�����ĵ��ߴ�������Ū����...��Ǹ����...\n", me);
		return 1;
	}
	// �������ߴ���
	message_vision("Īа��$N˵������������û��Ǯ�ˣ������Ȼ�����ɣ����ǵģ����������ò��˵�...\n"
		       "Īа�Ѵ���������$N��\n", me);
	ob->move(me);
	return 1;
}
