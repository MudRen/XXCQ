//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��ʯ��");
        set ("long", @LONG
����һ����ʯ�̳ɵ�ɽ·����佻�Ϫ�ķɻ����������������ˡ�����
���������߼����͵���佻����ɵĽ�®��ǰ�ˡ�����·�ϲ��µ��мҶ���
Ѿ�ߴ���������������������˵��Ц�ò����֡�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"westup" : "/d/huanhua/gate",
		"eastdown" : __DIR__"hhxroad1",
       ]));
        set("objects", ([
                 "/d/huanhua/npc/bzong": 2,
        ]));

        set("outdoors", "xiao");
        setup();
}
