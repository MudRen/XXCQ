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
		"south" : __DIR__"zgnorth",
		"north" : __DIR__"guandao1",
	]));

        set("outdoors", "zigui");
        setup();
}