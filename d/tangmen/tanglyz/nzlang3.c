//nzlang3.c		�Ĵ����š�����

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
			"south" : __DIR__"nzlang2",
			"north" : __DIR__"tangltt",
			"west" : __DIR__"tangshe",
			"east" : __DIR__"tangting",
	]));
	set("area", "����");
	setup();
//	replace_program(ROOM);
}

int init()
{
	object me, roomt, rooms;

	me = this_player();

	if ( !( roomt = find_object(__DIR__"tangting")) )
		roomt = load_object(__DIR__"tangting");
	if ( !( rooms = find_object(__DIR__"tangshe")) )
		rooms = load_object(__DIR__"tangshe");

	if ( ( (string)me->query("family/family_name") != "�Ĵ�����" ) && !wizardp(me) )
	{
		if ( objectp(present("tang ting", environment(me)) )
			|| ( objectp(roomt) && objectp(present("tang ting", roomt)) )
			|| ( objectp(present("tang she", environment(me)) ) )
			|| ( objectp(rooms) && objectp(present("tang she", rooms)) ) )
		me->set_temp("tangjindi",1);
		remove_call_out("do_kill");
		call_out("do_kill", 1);
	}
}

int do_kill()  
{
	object me, obj, roomt, rooms;

	me = this_player();

	me->delete_temp("tangjindi");

	if ( !( roomt = find_object(__DIR__"tangting")) )
		roomt = load_object(__DIR__"tangting");
	if ( !( rooms = find_object(__DIR__"tangshe")) )
		rooms = load_object(__DIR__"tangshe");

	if ( ( (string)me->query("family/family_name") != "�Ĵ�����" ) && !wizardp(me) )
	{
		if ( objectp(present("tang ting", environment(me)) ) )
		{
			obj = present("tang ting", environment(me));
			message_vision("��������$N���һ�������󵨣��ô����Ž��أ��ҿ����ǲ�����ˣ���\n",me);
			obj->kill_ob(me);
			me->fight_ob(obj);
			call_out("away", 20, obj);
		}
		else
		{
			if ( objectp(roomt) && objectp(present("tang ting", roomt)) )
			{
				obj = present("tang ting", roomt);
				tell_room(roomt, "��������������ʲô���죬üͷһ�����ﵽ������˭��ô�󵨣��ô����Ž��أ��ҵ�ȥ����!��\n�����첽������ȥ��\n");
				tell_room(this_object(), "�����첽�Ӷ��ߵ������߳�����\n");
				obj->move(__DIR__"nzlang3");
				message_vision("��������$N���һ�������󵨣��ô����Ž��أ��ҿ����ǲ�����ˣ���\n",me);
				obj->kill_ob(me);
				me->fight_ob(obj);
				call_out("away", 20, obj);
			}
		}

		if ( objectp(present("tang she", environment(me)) ) )
		{
			obj = present("tang she", environment(me));
			message_vision("�������$N���һ�������ߣ��������Ĵ̿ͣ�����!��\n",me);
			obj->kill_ob(me);
			me->fight_ob(obj);
			call_out("away", 20, obj);
		}
		else
		{
			if ( objectp(rooms) && objectp(present("tang she", rooms)) )
			{
				obj = present("tang she", rooms);
				tell_room(rooms, "�������������ʲô���죬üͷһ�����ﵽ:����˭��ô�󵨣��ô����Ž��أ��ҵ�ȥ����!��\n����첽����ȥ��\n");
				tell_room(this_object(), "����첽�����ߵ������߳�����\n");
				obj->move(__DIR__"nzlang3");
				message_vision("�������$N���һ�������ߣ��������Ĵ̿ͣ�����!��\n",me);
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
			if ( (string)obj->query("id") == "tang she" )
				obj->move(__DIR__ "tangshe");
			else
				if ( (string)obj->query("id") == "tang ting" )
					obj->move(__DIR__ "tangting");
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
	if ( obj = present("tang ting", environment(me) ) )
		msg = obj->query("name") + "˵�������ߣ��ô����Ž��أ������ߣ��Ȱ������̵���˵����\n";
	else
		if ( obj = present("tang she", environment(me) ) )
			msg = obj->query("name") + "˵�������ߣ��ô����Ž��أ������ߣ��Ȱ������̵���˵����\n";

	if ( me->query_temp("tangjindi") )
		return notify_fail("��о��и��־������ԣ���������������\n");

	if ( ( (dir == "north") || (dir == "west") || (dir == "east") || (dir == "south") ) && ( (string)me->query("family/family_name") != "�Ĵ�����" ) && !wizardp(me) && obj)
		return notify_fail(msg);
	else
		return ::valid_leave(me, dir);
}

