// zaotang.c  by winder

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�����Ů��");
	set("long", @LONG
�߽������������������ŨŨ������������������Զ�ĵط�����
һ������ʯ���ɵĳ��ӣ���Լ��ʮ����Ů�������ڳ����������Щ����
Ҳ��ϴ��һϴ��ϴȥһ���ƣ����
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"north" : __DIR__"zaotang",
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
	if (me->query("gender") == "����")
	{
		message("channel:chat",
			HIW"\n��������������ǻ���صķ�������һ��Ů�������ץ��å����������˵"
			+me->name(1)+"�ܵ�Ů��������ȥ�ˣ��������ǲ�Ҫ����\n"NOR,users());
		tell_object(me, "\n���������۸�һ����Ů������������Ѿ����������һӵ���ϣ��������˳�ȥ����û���ӡ�\n\n");
		message("vision",
			me->query("name")+"��ɫ���Ե�����ҿ���ʮ�����󵨵�Ů���Ѿ�������ȥ����"+me->query("name")+"���˳�ȥ��\n",
			environment(me), ({me}) );
		me->move("/d/bianliang/zaotang");
		message("vision",
			"ֻ�����顱��һ����"+me->query("name")+"���˴�Ů���������˳��������滹������Ů�˵Ľ�������\n",
			environment(me), ({me}) );
	}
}