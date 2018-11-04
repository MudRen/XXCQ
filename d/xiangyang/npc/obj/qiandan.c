// liangong-fu.c

inherit ITEM;
#include <ansi.h>
int do_shouzhang();
int consider_lv(object ob,int a);

void create()
{
	set_name("Ƿ��", ({ "dan"}));
	set("long", "������\n");
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "paper");
		set("value", 60);
		set("unit", "��");
	}
	setup();
}

void init()
{
	add_action("do_shouzhang","shouzhang");
}

int do_shouzhang()
{
	object ob, me;
	string arg;

	me = this_player();
	arg = me->query_temp("subject");

	if (me->query_temp("qljob")!=1)
		return notify_fail("�㲻���������˵�ȥ���ʡ�\n");

	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("��Ҫ��ծ���˲������\n");

	me->set_temp("qljob",2);
	me->apply_condition("jyfail",30);
	message_vision(HIW"\n$N�������ͳ�һ��Ƿ�����͵�һ���������ȵ�����"+ob->query("name")+
		"����Ƿ����Ǯׯ��"+chinese_number(me->query_temp("money"))+
		"������Ҳ�û��˰ɣ���\n"NOR,me);
	call_out("qljob_1", 3, me, ob);
	return 1;
}

int qljob_1(object me,object ob)
{
	object to_ob;

	to_ob = present("silver_money", me);

	if (environment(me)==environment(ob))
	{
		if (random(100) > 75)
		{
			message_vision("\n" + HIW + ob->query("name")+"���ŵô���һ�����£�æ�������ĵ�������������������\n"NOR,me);
			message_vision("\n" + HIW + ob->query("name")+"����ææ���½����ͳ�һ��СǮ�����ó���һЩ�����Ӹ���$N\n"NOR,me);
			if( !to_ob ) {
				to_ob = new("/clone/money/silver");
				to_ob->move(this_player());
				to_ob->set_amount(me->query_temp("money"));
			} else
				to_ob->add_amount(me->query_temp("money"));
			message_vision("\n" + HIW + "$N���˵�ͷ�������������ã����Ҷ��ð��¡�����˵�꽫Ƿ�˵�˺���ˡ�\n\n"NOR, me);
			me->set_temp("qljob",3);
			me->apply_condition("jyfail",0);
			destruct(this_object());
			return 1;
		}
		else
		{
			message_vision("\n" + HIW + ob->query("name")+"��¶��ɫ��С����������Ц�����������������ûǮ�������ܲ��ܿ��޼��죿��\n"NOR, me);
			message_vision("\n" + HIW + "$N������üͷ����ʲô��ûǮ������\n"NOR, me);
			write(HIR"\n�Ƿ�ɱ��"+ob->query("name")+"(ɱ(Y)����ɱ(N))��"NOR);
			me->set_temp("block_msg/all");
			input_to("qljob_2", me, ob);
			return 1;
		}
	}

	write("���������ʵĶ�������ˣ�Ǯ���ղ����ˡ�\n");
	return 1;
}

void qljob_2(string sel,object me,object ob)
{
	me->delete_temp("block_msg/all");

	if (sel=="Y"||sel=="y")
	{
		message_vision("\n" + HIY + "$N�İ�����Ŀ¶�׹�ŭ������ûǮ���ҿ����ǳ��ĵ��ң�������������\n\n"NOR ,me);
		me->kill_ob(ob);
		ob->kill_ob(me);
		call_out("qljob_3",4+random(8),me);
		return;
	}
	else if(sel=="N"||sel=="n")
	{
		message_vision("\n" + HIG + "$N̾�˿������������ˣ�������Ұ��㻹�ϰɡ�����˵�հ�Ƿ�˵�˺�˷��顣\n"NOR,me);
		message_vision("\n" + HIG + "$n�м��ü�ֱ��֪����˵Щʲô�ˡ�"NOR,me,ob);
		me->set_temp("qljob",5);
		destruct(this_object());
		return;
	}
	else{
		write(HIR"��ѡ��N or Y��"NOR);
		input_to("qljob_2", me, ob);
	}
	return;
}

void qljob_3(object me)
{
	object ob;

	ob = new("/d/xiangyang/npc/xiashi");
	ob->set("combat_exp",me->query("combat_exp") * 4 / 5);
	ob->set("max_qi",me->query("max_qi"));
	ob->set("eff_qi",me->query("max_qi"));
	ob->set("qi",me->query("max_qi"));
	ob->set("max_jingli",me->query("max_jingli"));
	ob->set("eff_jingli",me->query("max_jingli"));
	ob->set("jingli",me->query("max_jingli"));
	ob->set("max_neili",me->query("max_neili"));
	ob->set("neili",me->query("max_neili"));
	ob->set_skill("force", consider_lv(ob, 7));
	ob->set_skill("jiuqu-xinfa", consider_lv(ob, 5));
	ob->set_skill("huanhua-shenfa", consider_lv(ob, 5));
	ob->set_skill("strike", consider_lv(ob, 7));
	ob->set_skill("feixu-zhang",consider_lv(ob, 5));
	ob->set_skill("dodge", consider_lv(ob, 7)); 
	ob->set_skill("sword", consider_lv(ob, 7)); 
	ob->set_skill("huanhua-jian", consider_lv(ob, 5)); 
	ob->set_skill("parry", consider_lv(ob, 7)); 
	ob->set_skill("literate", consider_lv(ob, 7));
	ob->set("shen",(me->query("combat_exp")/20));
	ob->move(environment(me));
	message_vision("\n" + HIW + "ͻȻһ����Ӱ��$N���˹�����\n"NOR, me);
	message_vision("\n" + HIR + "$n��$N���һ�����������Ȩ������߹���������������\n"NOR, me, ob);
	me->kill_ob(ob);
	ob->kill_ob(me);
	destruct(this_object());
}

int consider_lv(object ob,int a)
{
	int level; 
	float exper;

	exper = to_float(ob->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333) );

	level = level * a / 10;

	return level;
}