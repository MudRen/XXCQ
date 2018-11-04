//shuding.c  by winder

#include <room.h>
#include <skill.h>
#include <ansi.h>

inherit ROOM;

void create()
{	
	seteuid(getuid());
	set("short", "����");
	set("long", @LONG
����������ɵ�������������ʦү���������������չ��ƶ���ҹ
���Ǳ䣬��������ˣ������������ž�ѧ����˺ܶ���ӳ���������
��ҹ������
LONG);	
	set("item_desc", ([
		"down" : "һ����ȥֻ������ƬƬ���������������ᣬ����ɽ��Ʈ��Ʈȥ��\n",
	]));

	set("area", "����");
	setup();
}

void init()
{
	add_action("do_wu","lingwu");
	add_action("do_climb","climb");
	add_action("do_climb","pa");
}

int do_wu(string arg)
{
	object me;
	int cost;

	me = this_player();
	cost = 15 + ( 30 - (int)me->query_int() ) / 2;

        if ( cost < 1)
		cost = 0;

        if ( 25 - (int)me->query_int() > 0 )
             return notify_fail("����Ŀǰ�����ԣ����²�������ʲô��\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

        if ( me->is_busy() )
                return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("���޷���ս���о�������\n");
/*
	if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			printf("�㾲����䣬������ʵս���鲻��û������ʲô��\n��\n", ob->name());

	if( (int)me->query("combat_exp") < skill["exp_required"] )
	{
		write("�㾲����䣬������ʵս���鲻��û������ʲô��\n");
		return 1;
	}
*/
	if ( arg == "yun")
	{
		if( (int)me->query_skill("dodge", 1) < 51 )
			return notify_fail("���չ��Ʊ䣬����ȴ�޷���������ʲô��\n");

		if( (int)me->query_skill("dodge", 1) > 201 )
			return notify_fail("���չ��Ʊ䣬�Ծ�һ�б仯����������ġ�\n");

		if ( (int)me->query("jingli") > cost )
		{
			tell_object(me, "����ϥ���¾���ͷ���������Ʈ���������ټ���Ѱ��\n��Ի��������˽�һ����ʶ��\n");
			me->improve_skill("dodge", random( (int)me->query_skill("literate", 1) / 2 ) + 20 );
			me->receive_damage("jingli", cost );
		}
		else
		{
			if ( (int)me->query("jingli") <= cost )
				write("�����ڹ���ƣ�룬�޷�������������\n");
		}
		return 1;
	}
	else
		if ( arg == "xing")
		{
			if( (int)me->query_skill("finger", 1) < 51 )
				return notify_fail("��ҹ���Ǳ䣬����ȴ�޷���������ʲô��\n");
	
			if( (int)me->query_skill("finger", 1) > 201 )
				return notify_fail("��ҹ���Ǳ䣬�Ծ�һ�б仯����������ġ�\n");
	
			if ( (int)me->query("jingli") > cost )
			{
				tell_object(me, "����ϥ���¾���ͷ��������˸������������\n��Ի����ַ����˽�һ����ʶ��\n");
				me->improve_skill("finger", random( (int)me->query_skill("literate", 1) / 2 ) + 20 );
				me->receive_damage("jingli", cost );
			}
			else
			{
				if ( (int)me->query("jingli") <= cost )
					write("�����ڹ���ƣ�룬�޷�������������\n");
			}
			return 1;
		}
		else
			return 0;
}

int do_climb(string arg)
{
	object ob;
	ob = this_player();

	if ( arg && arg == "down" )
	{
		message_vision(HIC "$N���ŷ�ï����֦һ����������ȥ��\n" NOR, ob);
		ob->move(__DIR__"shugan3");
		return 1;
	}
	else
		return notify_fail("��Ҫ����������\n");
}