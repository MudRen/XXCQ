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
		"northwest" : __DIR__"tulu7",
		"south" : __DIR__"tulu4",
		"east" : __DIR__"maitian1",
	]));

        set("outdoors", "zigui");
        setup();
}