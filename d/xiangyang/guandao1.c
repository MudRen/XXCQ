//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��ʯ�ٵ�");
        set ("long", @LONG
����һ��ƽ������ʯ�ٵ������ڴ�ٹ�����ˮ·ȥ������һ��Ҫ����
�������·Ҳ�̵��ر�ĺã�����ͨ���ƺ�����ɿڣ�������ͨ������
��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"zgmatou",
		"south" : __DIR__"guandao2",
	]));

        set("outdoors", "zigui");
        setup();
}