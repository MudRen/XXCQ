//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
��Ȼ������ֻ��һ��С�򣬵�ȷ�������ȫ������·������һ����վ
�������д���Ϣ��������ͷ�����ǿ��˱���Ϣ����ҿ�ջ��·����һ����
ͨ����ӡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"chaoyang1",
		"south" : __DIR__"zgcs",
	]));

        set("outdoors", "zigui");
        setup();
}