//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "�����򱱿�");
        set ("long", @LONG
���������򱱿���һ����ʯ�����һֱͨ���ƺӰ��ߣ���Ŀ��������
�Կ�������Ʈ������ģ���Ϊ���������۵�ʱ�ڣ���������·�Ϻ�������
����Ҷ��Ҵ��򰶱߸�ȥ��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"guandao2",
		"south" : __DIR__"chaoyang1",
	]));

        set("outdoors", "zigui");
        setup();
}