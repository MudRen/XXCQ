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
Щ�����������ʳ���������˼ҽ�������Щ��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"southeast" : __DIR__"tulu3",
		"west" : __DIR__"tulu2",
	]));

        set("outdoors", "zigui");
        setup();
}