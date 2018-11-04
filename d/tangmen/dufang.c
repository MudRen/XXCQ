//dufang.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>

inherit ROOM;

int do_putin(object me, object obj);

void create()
{
	set("short", "������");
	set("long", @LONG
���������ŵ�������������û��ʲô���裬ֻ�ǿ�ǽ��������ľ
�ܣ������ϰ�����ҩƿҩ�ޣ������������Ϻõ���ʯ�ݳ���һ����̨
һ������ǧ���ص���ͭҩ¯���ص�ѹ�����棬������ֵ������ɼ���
�������ﾹû��һ��������
LONG);
	set("exits", ([
			"southeast" : __DIR__"houroad4",
	]));
	set("objects", ([__DIR__"npc/tangdu" : 1,]));
	set("area", "����");
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_put","put");
}

int do_put(string arg)
{
	object obj, obj2, me, *inv;
	string item;
	int amount, i;

	me = this_player();

	if (!arg) return 0;

	if( sscanf(arg, "%s in yaolu", item) == 1 );
	else 
		return notify_fail("��Ҫ��ʲô������\n");

	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else 
			if( amount == (int)obj->query_amount() )
				return do_putin(me, obj2);
			else
			{
				obj->set_amount( (int)obj->query_amount() - amount );
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				if (do_putin(me, obj2))
					return 1;
				else
				{
					obj->set_amount((int)obj->query_amount() + amount);
					return 0;
				}
			}
	}

	if(arg=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			do_putin(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_putin(me, obj);
}

int do_putin(object me, object obj)
{
	string tar, targ;
	int tarm;
	string *duwu = ({
		"","���","��Ы��","��Ҷ��","����","����","ǧ�궾��",
	});

	tar = (string)obj->query("name");
	tarm = (int)me->query_temp("duyao");
	targ = (string)duwu[tarm];

	printf("1%s1 == 1%s1 == %d/%d\n",tar,targ,tarm,sizeof(duwu));

	if ( !(int)me->query_temp("duyao"))
	{
		message_vision("�ƶ�һ���ִ�����$N���ϵ�" + obj->name() + "���е�����ʲô��������ҩ¯��š���\n", me);
		obj->move(this_object());
		return 1;
	}	

	if ( (tar == targ) && objectp(obj) )
	{
		message_vision("$N�ó�" + obj->name() + "�Ž�ҩ¯��\n", me);
		destruct(obj);
		message_vision("�ƶ�����$N���˵�ͷ��˵�������ã���ɵĺܺã���ȥ��Ϣ�ɡ���\n", me);
		me->delete_temp("tangmen");
		me->delete_temp("duyao");
		me->add("combat_exp", 150 + random(150));

//		if( (int)me->query("potential") > (int)me->query("learned_points"))
//			me->add("potential", ((int)me->query("learned_points") - (int)me->query("potential"))/2 );

		me->add("potential", 80 + random(30));
		return 1;
	}
	else
	{
		message_vision("�ƶ�һ���ִ�����$N���ϵ�" + obj->name() + "���е�����ʲô��������ҩ¯��š���\n��ȥ��" + targ+ "������\n", me);
		obj->move(this_object());
//		destruct(obj);
		return 1;
	}
}