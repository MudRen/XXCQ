//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG
����һƬ�����Ϸ��ĵ�������������Ķ�����ӣ������꾰���ã�
����������ճ�Ҳ����ô�ã������������һ���Դ���Ϊ��������ı���
������һ���˼ҡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"tulu3",
		"north" : __DIR__"minju2",
		"south" : __DIR__"maitian2",
	]));

        set("outdoors", "zigui");
        setup();
}