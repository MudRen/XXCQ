//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "����Ǯׯ");
        set ("long", @LONG
����Ǯׯ�Ǹ�������һ��Ǯׯ���������ĺ�̨�ϰ���Ȩ������ˣ�
����û�˸��ǣ��������µ����Ŷ���ͨ��ͨȡ����Ǯ����û�����⡣һ��
���������ڹ�̨�����а�����һ�ͽ�ӡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"jinyin2",
		"north" : __DIR__"jyqz2",
	]));

	set("objects", ([
		__DIR__"npc/cheng": 1,
	]));

        setup();
}
