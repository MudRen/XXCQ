//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
���������ֵ����ֽ������֣��������������������򣬵����Դ�Ȩ��
�������￪�˼ҽ���Ǯׯ��������Ҳ�͸�����Ϊ�������ˡ�·����һ��
�鱦�꣬Ҳ��Ȩ���￪�ġ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"jinyin2",
		"west" : __DIR__"zgcs",
	]));

        set("outdoors", "zigui");
        setup();
}