//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
�����ǽ����ֵĶ��ˣ��򶫾�Ҫ�����������ˣ�·����һ��С��ݣ�
Ʈ���ŵĻ���д��������ݣ������������У������������֡�·����һ��
��ӡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"zgeast",
		"west" : __DIR__"jinyin2",
	]));

        set("outdoors", "zigui");
        setup();
}