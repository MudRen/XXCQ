//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "���о�ʯ");
        set ("long", @LONG
���Ͻ��ľ�ʯ����ʱ�е��������ȣ����������ӽ�������������ˮ��
���棬�����ھ�ʯ��ǰ��Ϊ���룬���ٶ�Ȼ�Ӽ������ڶ�ȥ��һλ������
�������������������������ŵĴ�����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"hengtan",
        ]));

	set("objects", ([
		"/kungfu/class/quanli/futianyi": 1,
	]));

        set("outdoors", "zigui");
        setup();
}