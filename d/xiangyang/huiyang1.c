//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
�����ֺ̣ܶ������Ϳ����ߵ���ͷ������·������־�֪��������
һ�ҵ��̣����ŴҴ��߹��Ĺ����ſ��Բµ����ž��ڽֵ����档����
����������������ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
         "east" : __DIR__"xyyizhan",
		"north" : __DIR__"zgcs",
		"south" : __DIR__"huiyang2",
	]));

        set("outdoors", "zigui");
        setup();
}
