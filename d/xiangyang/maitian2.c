//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG
����һƬ�����Ϸ��ĵ�������������Ķ�����ӣ������꾰���ã�
����������ճ�Ҳ����ô�ã������������һ���Դ���Ϊ��������Ķ���
������һ���˼ң����������˴���С����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"tulu4",
		"north" : __DIR__"maitian1",
		"east" : __DIR__"minju3",
	]));

        set("outdoors", "zigui");
        setup();
}