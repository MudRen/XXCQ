//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��·");
        set ("long", @LONG
���ǺᴩС��ׯ����·����·��ϡϡ�������м���é�ݷ���ż����һ
ֻ���ܹ���Ҳ��û����ɡ�·��ɹ��һЩ����������һЩ���������㣬��
Щ�����������ʳ��·������һƬ�ѵ�һ���ĵ��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"tulu3",
		"southwest" : __DIR__"tulu5",
		"east" : __DIR__"maitian2",
		"west" : __DIR__"tulu8",
	]));

        set("outdoors", "zigui");
        setup();
}