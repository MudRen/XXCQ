//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "�ݴ�");
        set ("long", @LONG
����佻�Ϫ���ߵ�������·�Ѿ������Ĳ����ˣ������Χ�����Ӳ�
���������Ұ�����÷����ïʢ������Ŀ����������ȴʲôҲ��������
���Ƿ���ȥ�ɡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"hhxroad3",
		"north" : __DIR__"hhxroad4",
        ]));

	set("hhjob", 1);
        set("outdoors", "xiao");
        setup();
}