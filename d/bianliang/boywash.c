// zaotang.c  by winder

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������в�");
	set("long", @LONG
�߽������������������ŨŨ������������������Զ�ĵط�����
һ������ʯ���ɵĳ��ӣ���Լ��ʮ�����������ڳ����������Щ����Ҳ
��ϴ��һϴ��ϴȥһ���ƣ����
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"south" : __DIR__"zaotang",
	]));

	set("area", "����");

	setup();
}

void init()
{
	object me;
	me = this_player();
	call_out("check",1,me);
}

void check(object me)
{
	if (me->query("gender") == "Ů��")
	{
		message("channel:chat",
			HIW"���������������ǻ���صķ�������һ���������ֵ���������˵�и�Ů�Ľ�ʲô"
			+me->name(1)+"���ܵ�����������ȥ�ˣ�����������������ѽ��\n"NOR,users());
		tell_object(me, "\n�������������ҿ���������������������Ѿ�Χ�����������ŵøϿ����˳�ȥ���������ˡ�\n\n");
		message("vision",
			me->query("name")+"�����������ҿ���������������������Ѿ�Χ����ȥ��"+me->query("name")+"�ŵøϿ����˳�ȥ��",
			environment(me), ({me}) );
		me->move("/d/bianliang/zaotang");
		message("vision",
			me->query("name")+"����ͨ��Ĵ��������������˳��������滹�������������˵�Ц����",
			environment(me), ({me}) );
	}
}