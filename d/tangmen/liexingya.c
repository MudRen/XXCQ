//liexingya.c		�Ĵ����š�������

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������źС����ɽ�������¡���˵���ŵĿ�ɽ��ʦ����������
�����ﾲ�����꣬ҹ���Ǳ䣬������������򽭺������Ű���������
��������һ�����������ɽ���ⳤ���������������ơ�
LONG);
//������һ���������(shu)��ɽ���ⳤ���������������ơ�
	set("exits", ([
			"southdown" : __DIR__"shandao5",
	]));
	set("item_desc", ([
		"shu" : "������ɾ�˵������ǰ�̹ſ���ʱ�������ɵġ�\n",
	]));
	set("area", "����");
	setup();
}

void init()
{
	add_action("do_climb","climb");
	add_action("do_climb","pa");
}

int do_climb(string arg)
{
	object ob;
	ob = this_player();

	if ( arg && arg == "shu" )
	{
		if ( (int)ob->query_skill("dodge", 1) < 21 && (int)ob->query_skill("finger", 1) < 21 )
		{
			tell_object(ob, HIR "��Ĺ��򻹲����ߣ�����ȥ���»�ˤ���ġ�\n" NOR, ob);
			return 1;
		}

		message_vision(HIC "$N���ŷ�ï����֦һ����������ȥ��\n" NOR, ob);
		ob->move(__DIR__"shugan1");
		return 1;
	}
	else
		return notify_fail("��Ҫ����������\n");
}