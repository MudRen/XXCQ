//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "������ֿ�");
        set ("long", @LONG
������������С���ʮ��״�����Ƕ����͵ģ�����ֿھ���������
�����ģ���������������ƺ�����ɿڣ������ǽ����֣�����Ǯׯ������
�ߣ��ϱ��������ŵ����ڡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"chaoyang2",
		"south" : __DIR__"huiyang1",
		"east" : __DIR__"jinyin1",
	]));

        set("outdoors", "zigui");
        setup();
}