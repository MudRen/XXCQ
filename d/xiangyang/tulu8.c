//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��·");
        set ("long", @LONG
���Ǻ̵ܶ�һ��·�������Ѿ�û��·�ˣ�ֻ��һƬ�Ҳݶѣ�·����һ
��é�ݣ����������Ŵ������·��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"tulu4",
		"north" : __DIR__"minju4",
	]));

        set("outdoors", "zigui");
        setup();
}