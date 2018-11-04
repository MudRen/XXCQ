//nzlang2.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_kill();
void away(object obj);

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ƹ󱱲�����ȡ������Ǳ��̵ĺ�ˮ�������ɻ�������
�ţ���������������������ֹ����ǰ������ͨ�����Ƹ��լ��
LONG);
	set("exits", ([
			"south" : __DIR__"houzhai",
			"north" : __DIR__"nzlang3",
			"west" : __DIR__"tangwen",
			"east" : __DIR__"tanggan",
	]));
	set("area", "����");
	setup();
//	replace_program(ROOM);
}

int init()
{
	object me, roomg, roomw;

	me = this_player();

	if ( !( roomg = find_object(__DIR__"tanggan")) )
		roomg = load_object(__DIR__"tanggan");
	if ( !( roomw = find_object(__DIR__"tangwen")) )
		roomw = load_object(__DIR__"tangwen");

	if ( ( (string)me->query("family/family_name") != "�Ĵ�����" ) && !wizardp(me) )
	{
		if ( objectp(present("tang gan", environment(me)) )
			|| ( objectp(roomg) && objectp(present("tang gan", roomg)) )
			|| ( objectp(present("tang wen", environment(me)) ) )
			|| ( objectp(roomw) && objectp(present("tang wen", roomw)) ) )
		me->set_temp("tangjindi",1);
		remove_call_out("do_kill");
		call_out("do_kill", 1);
	}
}

int do_kill()  
{
	object me, obj, roomg, roomw;

	me = this_player();

	me->delete_temp("tangjindi");

	if ( !( roomg = find_object(__DIR__"tanggan")) )
		roomg = load_object(__DIR__"tanggan");
	if ( !( roomw = find_object(__DIR__"tangwen")) )
		roomw = load_object(__DIR__"tangwen");

	if ( ( (string)me->query("family/family_name") != "�Ĵ�����" ) && !wizardp(me) )
	{
		if ( objectp(present("tang gan", environment(me)) ) )
		{
			obj = present("tang gan", environment(me));
			message_vision("�Ƹж���$N���һ�������󵨣��ô����Ž��أ��ҿ����ǲ�����ˣ���\n",me);
			obj->kill_ob(me);
			me->fight_ob(obj);
			call_out("away", 20, obj);
		}
		else
		{
			if ( objectp(roomg) && objectp(present("tang gan", roomg)) )
			{
				obj = present("tang gan", roomg);
				tell_room(roomg, "�Ƹк���������ʲô���죬üͷһ�����ﵽ������˭��ô�󵨣��ô����Ž��أ��ҵ�ȥ����!��\n�Ƹп첽������ȥ��\n");
				tell_room(this_object(), "�Ƹп첽�Ӷ��ߵ������߳�����\n");
				obj->move(__DIR__"nzlang2");
				message_vision("�Ƹж���$N���һ�������󵨣��ô����Ž��أ��ҿ����ǲ�����ˣ���\n",me);
				obj->kill_ob(me);
				me->fight_ob(obj);
				call_out("away", 20, obj);
			}
		}

		if ( objectp(present("tang wen", environment(me)) ) )
		{
			obj = present("tang wen", environment(me));
			message_vision("���Ŷ���$N���һ�������ߣ��������Ĵ̿ͣ�����!��\n",me);
			obj->kill_ob(me);
			me->fight_ob(obj);
			call_out("away", 20, obj);
		}
		else
		{
			if ( objectp(roomw) && objectp(present("tang wen", roomw)) )
			{
				obj = present("tang wen", roomw);
				tell_room(roomw, "���ź���������ʲô���죬üͷһ�����ﵽ:����˭��ô�󵨣��ô����Ž��أ��ҵ�ȥ����!��\n���ſ첽����ȥ��\n");
				tell_room(this_object(), "���ſ첽�����ߵ������߳�����\n");
				obj->move(__DIR__"nzlang2");
				message_vision("���Ŷ���$N���һ�������ߣ��������Ĵ̿ͣ�����!��\n",me);
				obj->kill_ob(me);
				me->fight_ob(obj);
				call_out("away", 20, obj);
			}
		}
	}
	return 1;
}

void away(object obj)
{
	string name;
	if( living(obj) )
	{
		if (  !obj->busy() && !obj->is_fighting() )
		{
			message_vision("$N�޺޵�˵:��˭���ô����Ž��أ��Ҿ���������\n$Nһת���߻����Լ������С�\n", obj);
			if ( (string)obj->query("id") == "tang wen" )
				obj->move(__DIR__ "tangwen");
			else
				if ( (string)obj->query("id") == "tang gan" )
					obj->move(__DIR__ "tanggan");
		}
		else
			call_out("away", 20, obj);
	}
	return;
}

int valid_leave(object me, string dir)
{
	object obj;
	string msg;
	if ( obj = present("tang gan", environment(me) ) )
		msg = obj->query("name") + "˵�������ߣ��ô����Ž��أ������ߣ��Ȱ������̵���˵����\n";
	else
		if ( obj = present("tang wen", environment(me) ) )
			msg = obj->query("name") + "˵�������ߣ��ô����Ž��أ������ߣ��Ȱ������̵���˵����\n";

	if ( me->query_temp("tangjindi") )
		return notify_fail("��о��и��־������ԣ���������������\n");

	if ( ( (dir == "north") || (dir == "west") || (dir == "east") || (dir == "south") ) && ( (string)me->query("family/family_name") != "�Ĵ�����" ) && !wizardp(me) && obj)
		return notify_fail(msg);
	else
		return ::valid_leave(me, dir);
}