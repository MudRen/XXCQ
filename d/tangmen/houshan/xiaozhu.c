//xiaozhu.c		�Ĵ����š���źС��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��źС��");
	set("long", @LONG
�����Ǿ��������Ų�Զ����źС������źС���Ƕ�����ɫ�Ľ���
�������¼��ӣ����ж��ٽ�������Ϊ��Խ��һ������ʬ���ز��ɵ�
�أ�һ�Ⱥ��صĴ���(door)�����ı��š�
LONG);
	set("item_desc", ([
		"door" : "����һ�ȼ�����صĴ��ţ�������ͭ�Ż���������ڴ�С��\n"NOR,
	]));
	set("area", "����");
	setup();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_open","open");
}

int do_open(string arg)
{
	object ob;
	ob = this_player();

	if ( arg && arg=="door" )
	{
		message_vision(HIC "$N˫���������ƿ����ţ���������Ȼ��������ס�ˡ�\n" NOR, ob);
		return 1;
	}
}

int do_knock(string arg)
{
	object ob, room;

	ob = this_player();

	if ( query("exits/enter") )
		return notify_fail("���Ѿ��ǿ��ŵ��ˡ�\n");

	if ( !( room = find_object(__DIR__"shuige1")) )
		room = load_object(__DIR__"shuige1");

	if ( arg && arg=="door" && objectp(room) )
	{
//		message_vision(HIC "$N����С������Ŀ۶��Ż���\n����һ�����������ĵ������α�Ϊ���أ��е��ͽ�С�������ɣ������������������\n����������Ϣ�Ĵ��ˡ�\n" NOR, ob);
		message_vision(HIC "$N�����۶��Ż�������������Ϣ�Ĵ��ˡ�\n" NOR, ob);
		set("exits/enter", __DIR__"shuige1");
		room->set("exits/out", __DIR__"xiaozhu");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
	else
		return 0;
}

//void close(object room)
void close()
{
	object room;

	if ( !( room = find_object(__DIR__"shuige1")) )
		room = load_object(__DIR__"shuige1");

	if( this_object() == environment(this_player()) || room == environment(this_player()))
		message("vision",HIR"����������Ϣ�Ĺ���������\n"NOR, this_player());
	
	delete("exits/enter");
	if ( objectp(room) )
		room->delete("exits/out");
}	
