//shuige1.c		�Ĵ����š�ͤ�ˮ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void away(object obj);

void create()
{
	set("short", "ͤ�ˮ��");
	set("long", @LONG
��������źС����ͤ�ˮ����������źС����Ϊһ�壬ͬ����
����ɫ�Ľ�����ˮ���ı��ϻ��Ÿ�ɫ��ɽˮ��棬��������ǰͨ����
�Ƹ󣬶����һ�ȴ��Ž����ŵ�ס����·��
LONG);
	set("exits", ([
		"north" : __DIR__"shuige2",
		"east" : __DIR__"chashi",
		"west" : __DIR__"menwei",
	]));
	set("area", "����");
	setup();
}
void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{
	object ob, room;
	ob = this_player();

	if ( query("exits/out") )
		return notify_fail("���Ѿ��ǿ��ŵ��ˡ�\n");

	if ( !( room = find_object(__DIR__"xiaozhu")) )
		room = load_object(__DIR__"xiaozhu");

	if ( arg && arg=="door" && objectp(room) )
	{
		message_vision(HIC "������������������\n" NOR, ob);
		set("exits/out", __DIR__"xiaozhu");
		room->set("exits/enter", __DIR__"shuige1");
		remove_call_out("close");
		call_out("close", 60, this_object());
		return 1;
	}
	else
		return 0;
}

void close()
{
	object room;

	if ( !( room = find_object(__DIR__"xiaozhu")) )
		room = load_object(__DIR__"xiaozhu");

	if( this_object() == environment(this_player()) || room == environment(this_player()))
		message("vision",HIR"����������Ϣ�Ĺ���������\n"NOR, this_player());
	delete("exits/out");
	if ( objectp(room) )
		room->delete("exits/enter");
}	

int valid_leave(object me, string dir)
{
	object obj, room;

	if ( !( room = find_object(__DIR__"menwei")) )
		room = load_object(__DIR__"menwei");

	if ( (dir == "out") && ( me->query("combat_exp") <=200000 ) && !wizardp(me) && !me->query("tangmen/xin") )
		if ( objectp(present("men wei", environment(me)) ) )
		{
			obj = present("men wei", environment(me));
			message_vision("��������$N����������������书�������ߣ����ȥ���ƼҶ����ˣ���\n",me);
			remove_call_out("away");
			call_out("away", 60, obj);
			return notify_fail("\n���Ȼ����ʦ�������������߹��㣬ֻ�й��������˲��ܱ�������Ŵ���������\n");
		}
		else
			if ( objectp(room) && objectp(present("men wei", room)) )
			{
				obj = present("men wei", room);
				tell_room(room, "��������������ʲô���죬üͷһ�����ﵽ������˭�������Գ��ţ��ҵ�ȥ����!��\n�����첽����ȥ��\n");
				tell_room(this_object(), "�����첽�����ߵ������߹�����\n");
				obj->move(__DIR__"shuige1");
				message_vision("��������$N����������������书�������ߣ����ȥ���ƼҶ����ˣ���\n",me);
				remove_call_out("away");
				call_out("away", 60, obj);
				return notify_fail("\n���Ȼ����ʦ�������������߹��㣬ֻ�й��������˲��ܱ�������Ŵ���������\n");
			}

	return ::valid_leave(me, dir);
}

void away(object obj)
{
	string name;
	object room;

	if ( !( room = find_object(__DIR__"menwei")) )
		room = load_object(__DIR__"menwei");

	if( living(obj) )
	{
		if (  !obj->busy() && !obj->is_fighting() )
		{
			message_vision("$Nҡ��ҡͷ��Ц��˵:��������ЩС���治֪��ߵغ񣬿�һ��ȥ�͸��ƼҶ��ˡ���\n$N����ȥ��\n", obj);
			tell_room(room, "�����첽��ˮ���Ǳ��߹�����\n");
			obj->move(__DIR__ "menwei");
		}
		else
		{
			remove_call_out("away");
			call_out("away", 60, obj);
		}
	}
	return;
}