//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��·");
        set ("long", @LONG
����·�������۴����������·��ϡϡ�������м���é�ݷ�������ת
�����˼��ܼ���һЩ��·��ɹ��һЩ����������һЩ���������㣬��Щ��
���������ʳ��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"tulu1",
		"east" : __DIR__"tulu7",
	]));

        set("outdoors", "zigui");
        setup();
}