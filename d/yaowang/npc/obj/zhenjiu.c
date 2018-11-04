// ��ĺ� ҩ��ׯҽ��ʩ���ĵ��ߡ�
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( CYN "��ĺ�" NOR , ({"zhenjiu he", "zhenjiu", "box"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", CYN"����һ����ĺУ���ҩ���ȵ���ҽ�ƺ�ʩ���Ĺ��ߡ�\n"
				"	xiadu	�¶�\n"
				"	heal	����\n"
				"	jiedu	�ⶾ\n"NOR);
		set("unit", "��");
		set("nopwan", 1);
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("value", 0);
		set("weight", 100);
	}
}

void init()
{
	add_action("do_xiadu", "xiadu"); //�¶�
	add_action("do_heal", "heal"); //����
	add_action("do_jiedu", "jiedu"); //�ⶾ
}

int do_heal(string arg)
{
	object me, ob;
	int i;
	me=this_player();
	i=( 100 - (int)me->query_skill("healing",1) );

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
		|| me->query("party/level")<5 )
		return notify_fail("�㲻��ʹ�������ĺУ�\n");

	if( me->query("shen")<0 )
		return notify_fail("�㲻��ʹ������ܣ�\n");

	if( !arg )
		return notify_fail("ָ���ʽ��heal <ID> \n");

	if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("����û������ˣ�\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ���أ�\n");

        if( ob->is_fighting() || ob->is_busy() )
                return notify_fail("����æ���أ�\n");

	if( me->query("shen")<0 )
		return notify_fail("�㲻��ʹ������ܣ�\n");

	if( i<5 ) i=5;
	if( i>80 ) i=80;
	if(me->query("jingli")<=i)
		return notify_fail("��̫���ˣ�����Ϣһ�°ɣ�\n");

	if( ob->query("max_qi")>=(ob->query("eff_qi")+(i*2)) ) {
		ob->set("max_qi",(ob->query("eff_qi")+(i*2)));
	} else { ob->set("eff_qi",(ob->query("max_qi"))); }

	message_vision(CYN"$N����ĺ����ó�һ��������$nѨλ�����˼��¡�\n"NOR, me, ob);
	message_vision(WHT"$N�³�һ����Ѫ����ɫ�������ö��ˡ�\n"NOR, ob);
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
	me->add("jingli", -i);
	me->start_busy(3);
	return 1;
}

int do_xiadu(string arg)
{
	object me, ob;
	int i;
	me=this_player();
	i=( 100 - (int)me->query_skill("healing",1) );

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
		|| me->query("party/level")<5 )
		return notify_fail("�㲻��ʹ�������ĺУ�\n");

	if( me->query("shen")>0 )
		return notify_fail("�㲻��ʹ������ܣ�\n");

	if( (environment(me))->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if( !arg )
		return notify_fail("ָ���ʽ��xiadu <ID> \n");

	if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("����û������ˣ�\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ���أ�\n");

	if( i<5 ) i=5;
	if( i>80 ) i=80;
	if(me->query("jingli")<=i)
		return notify_fail("��̫���ˣ�����Ϣһ�°ɣ�\n");

	message_vision(HIR"$N���ᰴ��һ����ĺС�ͻȻ�Ӻ��������֧"
		HIW"����"HIR"��������$n���ϡ�\n"NOR, me, ob);
	ob->receive_damage("qi",(int)me->query_skill("healing",1));
		if(random(10)<5) {
	ob->apply_condition("yao1_poison", ((int)me->query_condition("yao1_poison")+i));
		} else {
	ob->apply_condition("yao1_poison", ((int)me->query_condition("yao2_poison")+(i*10)));
		}
	ob->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
	me->add("jingli", -i);
	me->start_busy(3);
		if(random(me->query_skill("healing",1))<50) {
			ob->kill_ob(me); }
	return 1;
}

int do_jiedu(string arg)
{
	object me, ob;
	int i;
	me=this_player();
	i=( 100 - (int)me->query_skill("healing",1) );

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
		|| me->query("party/level")<5 )
		return notify_fail("�㲻��ʹ�������ĺУ�\n");

	if( me->query("shen")>0 )
		return notify_fail("�㲻��ʹ������ܣ�\n");

	if( !arg )
		return notify_fail("ָ���ʽ��jiedu <ID> \n");

	if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("����û������ˣ�\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ���أ�\n");

        if( ob->is_fighting() || ob->is_busy() )
                return notify_fail("����æ���أ�\n");

	if( i<5 ) i=5;
	if( i>80 ) i=80;
	if(me->query("jingli")<=i)
		return notify_fail("��̫���ˣ�����Ϣһ�°ɣ�\n");

	message_vision(CYN"$N����ĺ����ó�һ��������$nѨλ�����˼��¡�\n"NOR, me, ob);

//�� �嶾֮��
	if( (int)me->query_condition("yao1_poison")>=1 ) {
		if ((int)me->query_condition("yao1_poison") <= 10 ) {
			me->apply_condition("yao1_poison", 0);
	message_vision(YEL"$N���ϵ�"HIB"�嶾֮��"NOR+YEL"���ˣ���ɫ����ȥ�ö��ˡ�\n"NOR, me); 
	} else {
	message_vision(YEL"$N���ϵ�"HIB"�嶾֮��"NOR+YEL"��ȥһЩ��ɫ��������������\n"NOR, me);
	me->apply_condition("yao1_poison", (int)me->query_condition("yao1_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//�� С�嶾֮��
	if( (int)me->query_condition("yao2_poison")>=1 ) {
		if ((int)me->query_condition("yao2_poison") <= 10 ) {
			me->apply_condition("yao2_poison", 0);
	message_vision(YEL"$N���ϵ�"HIB"С�嶾֮��"NOR+YEL"���ˣ���ɫ����ȥ�ö��ˡ�\n"NOR, me); 
	} else {
	message_vision(YEL"$N���ϵ�"HIB"С�嶾֮��"NOR+YEL"��ȥһЩ��ɫ��������������\n"NOR, me);
	me->apply_condition("yao2_poison", (int)me->query_condition("yao2_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//�� ����֮��
	if( (int)me->query_condition("feixing_poison")>=1 ) {
		if ((int)me->query_condition("feixing_poison") <= 10 ) {
			me->apply_condition("feixing_poison", 0);
	message_vision(YEL"$N���ϵ�"HIB"����֮��"NOR+YEL"���ˣ���ɫ����ȥ�ö��ˡ�\n"NOR, me); 
	} else {
	message_vision(YEL"$N���ϵ�"HIB"����֮��"NOR+YEL"��ȥһЩ��ɫ��������������\n"NOR, me);
	me->apply_condition("feixing_poison", (int)me->query_condition("feixing_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//�� ��ڤ����֮��
	if( (int)me->query_condition("hx_poison")>=1 ) {
		if ((int)me->query_condition("hx_poison") <= 10 ) {
			me->apply_condition("hx_poison", 0);
	message_vision(YEL"$N���ϵ�"HIB"��ڤ����֮��"NOR+YEL"���ˣ���ɫ����ȥ�ö��ˡ�\n"NOR, me); 
	} else {
	message_vision(YEL"$N���ϵ�"HIB"��ڤ����֮��"NOR+YEL"��ȥһЩ��ɫ��������������\n"NOR, me);
	me->apply_condition("hx_poison", (int)me->query_condition("hx_poison") -10);
        }
		me->improve_skill("healing", (i/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//�� ����
	if( (int)me->query_condition("shengdu_poison")>=1 ) {
		if ((int)me->query_condition("shengdu_poison") <= 10 ) {
			me->apply_condition("shengdu_poison", 0);
	message_vision(YEL"$N���ϵ�"HIB"����"NOR+YEL"���ˣ���ɫ����ȥ�ö��ˡ�\n"NOR, me); 
	} else {
	message_vision(YEL"$N���ϵ�"HIB"����"NOR+YEL"��ȥһЩ��ɫ��������������\n"NOR, me);
	me->apply_condition("shengdu_poison", (int)me->query_condition("shengdu_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//�� �߶�
	if( (int)me->query_condition("snake_poison")>=1 ) {
		if ((int)me->query_condition("snake_poison") <= 10 ) {
			me->apply_condition("snake_poison", 0);
	message_vision(YEL"$N���ϵ�"HIB"�߶�"NOR+YEL"���ˣ���ɫ����ȥ�ö��ˡ�\n"NOR, me); 
	} else {
	message_vision(YEL"$N���ϵ�"HIB"�߶�"NOR+YEL"��ȥһЩ��ɫ��������������\n"NOR, me);
	me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//�� ��ʶ������
	if( (int)me->query_condition("xiangshi_poison")>=1 ) {
		if ((int)me->query_condition("xiangshi_poison") <= 10 ) {
			me->apply_condition("xiangshi_poison", 0);
	message_vision(YEL"$N���ϵ�"HIB"��ʶ������֮��"NOR+YEL"���ˣ���ɫ����ȥ�ö��ˡ�\n"NOR, me); 
	} else {
	message_vision(YEL"$N���ϵ�"HIB"��ʶ������֮��"NOR+YEL"��ȥһЩ��ɫ��������������\n"NOR, me);
	me->apply_condition("xiangshi_poison", (int)me->query_condition("xiangshi_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//�� Ы��
	if( (int)me->query_condition("xie_poison")>=1 ) {
		if ((int)me->query_condition("xie_poison") <= 10 ) {
			me->apply_condition("xie_poison", 0);
	message_vision(YEL"$N���ϵ�"HIB"Ы��"NOR+YEL"���ˣ���ɫ����ȥ�ö��ˡ�\n"NOR, me); 
	} else {
	message_vision(YEL"$N���ϵ�"HIB"Ы��"NOR+YEL"��ȥһЩ��ɫ��������������\n"NOR, me);
	me->apply_condition("xie_poison", (int)me->query_condition("xie_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//�� ����֮��
	if( (int)me->query_condition("xisui_poison")>=1 ) {
		if ((int)me->query_condition("xisui_poison") <= 10 ) {
			me->apply_condition("xisui_poison", 0);
	message_vision(YEL"$N���ϵ�"HIB"����֮��"NOR+YEL"���ˣ���ɫ����ȥ�ö��ˡ�\n"NOR, me); 
	} else {
	message_vision(YEL"$N���ϵ�"HIB"����֮��"NOR+YEL"��ȥһЩ��ɫ��������������\n"NOR, me);
	me->apply_condition("xisui_poison", (int)me->query_condition("xisui_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//�� ��
	if( (int)me->query_condition("yangdu_poison")>=1 ) {
		if ((int)me->query_condition("yangdu_poison") <= 10 ) {
			me->apply_condition("yangdu_poison", 0);
	message_vision(YEL"$N���ϵ�"HIB"��"NOR+YEL"���ˣ���ɫ����ȥ�ö��ˡ�\n"NOR, me); 
	} else {
	message_vision(YEL"$N���ϵ�"HIB"��"NOR+YEL"��ȥһЩ��ɫ��������������\n"NOR, me);
	me->apply_condition("yangdu_poison", (int)me->query_condition("yangdu_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}
	else {
		message_vision(CYN"����$N��û���ж�����\n"NOR, ob);
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}
}
