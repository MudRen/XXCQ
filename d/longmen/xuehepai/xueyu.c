//xueyu��c  by baby

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "Ѫ��");
	set("long", @LONG
������Ѫ���ɵ�Ѫ�����������������������������ǽ��ǽ�����в�
�������鷨�������������ٵ���������ĥ��Щ�鷨�ͻ����˴���Ѫ��
���ã����ո�����أ������˵Ȼ���������ȥ�����ɾ�����
LONG);	
	set("valid_startroom",1);
	set("exits",([
		"east" : __DIR__"xueku",
		"west" : __DIR__"youmingge",
	]));
/*
	set("item_desc", ([
                "shufa" : "����һЩ��ƽ������ʫ�δʣ����ݽ����塣���ٵ���������(yin)��\n",
                "hua" : "����һ������ġ���ҵ��ֻ������ٵ����ڿ�(kan)��\n",
	]));
*/
        set("area", "����");
	setup();
            replace_program(ROOM);
}/*

void init()
{
	add_action("do_look","kan");
	add_action("do_du","yin");
}

int do_look(string arg)
{
	object me;
	int cost;

	me = this_player();
	cost = 10 + ( 20 - (int)me->query_int() ) / 2;

        if ( cost < 1) cost = 0;

        if ( me->is_busy() )
                return notify_fail("��������æ���ء�\n");

	if ( arg == "hua")
	{
		if( (int)me->query_skill("literate", 1) > 50 )
notify_fail("����Ż�����ϸ��Ħ��һ��������ִ����Ѿ�ѧ����ʲô�ˡ�\n");

		if ( (int)me->query("jingli") > cost && (int)me->query("potential") >= 1 )
		{
                        tell_object(me, "��ר�ĵ��ж�ǽ�ϵĻ�����ʱ�������ָ��ġһ����\n");
			me->improve_skill("literate", random( (int)me->query_skill("literate", 1) / 2 ) + 10 );
			me->receive_damage("jingli", cost );
			me->add("potential", -1 );
		}
		else
		{
			if ( (int)me->query("jingli") <= cost )
				write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");

			if ( (int)me->query("potential") <= 0 )
                                write("�㿴�Ż�������ĥ����û��һ˿�ĵá�\n");
		}
		return 1;
	}
	else
		return 0;
}

int do_du(string arg)
{
	object me;
	int cost;

	me = this_player();
	cost = 10 + ( 30 - (int)me->query_int() ) / 2;

        if ( cost < 1) cost = 0;

        if ( me->is_busy() )
                return notify_fail("��������æ���ء�\n");

        if ( arg == "shufa")
	{
		if( (int)me->query_skill("literate", 1) < 51 )
                        return notify_fail("����ĥ�˰����鷨�����־�ʲôҲ��������\n");

		if( (int)me->query_skill("literate", 1) > 101 )
                        return notify_fail("���ж���һ�ᣬ����û��ʲô��ѧ���ˡ�\n");

		if ( (int)me->query("jingli") > cost && (int)me->query("potential") >= 1 )
		{
                        tell_object(me, "��ר�ĵش�Ħǽ�ϵ��鷨����������ʱ������������\n");
			me->improve_skill("literate", random( (int)me->query_skill("literate", 1) / 2 ) + 20 );
			me->receive_damage("jingli", cost );
			me->add("potential", -1 );

		}
		else
		{
			if ( (int)me->query("jingli") <= cost )
				write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");

			if ( (int)me->query("potential") <= 0 )
                                write("�㿴��ʫ���鷨����Ĭ������û��һ˿�ĵá�\n");
		}
		return 1;
	}
	else
		return 0;
}
*/
