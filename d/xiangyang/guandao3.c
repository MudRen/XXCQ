//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��ʯ�ٵ�");
        set ("long", @LONG
��������������Χ���С���е�һ����ƽ������ʯ�ٵ��ӻƺӱߵ���
����ͷһֱ���쵽�����ǡ���ʱ�������ˡ����Ҵ�·����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"northwest" : __DIR__"qugongci",
		"southeast" : __DIR__"guandao4",
	]));

        set("outdoors", "zigui");
        setup();
}