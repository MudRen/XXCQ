//zrping��c           ���ź�ɽ������ƺ

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIW"����ƺ"NOR);
	set("long", @LONG
�����Ǻ�ɽ����ƺ����˵Ѫ���ɿ�ɽ��ʦ�ڴ���������������ڵ���
��ʱ�����ڴ˿����似����ϣ���ܷ�����ʦ�ż�����ñ��ɸ�����ѧ����
����һ�����������ɽ���ⳤ���������������ơ�
LONG);
	set("exits", ([
                        "east" : __DIR__"houshan",
	]));
	set("item_desc", ([
		"shu" : "������ɾ�˵������ǰ�̹ſ���ʱ�������ɵġ�\n",
	]));
        set("outdoors","����");
        set("valid_startroom",1);
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
       ob=this_player();

	if ( arg && arg == "shu" )
	{
                if ( (int)ob->query_skill("dodge", 1) < 100 )
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