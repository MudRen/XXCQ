//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "佻�Ϫ��");
        set ("long", @LONG
��佻��������߹�����Ϳ��Ե�佻���ͷ�ˣ�����ʵֻ��佻�������
�����ͷ�ϴ���·��Ϫ�ϼ���������ǳˮ����ˣ���֣��ò�����ż��Ҳ��
��®��Ѿ��������ϴ�·���
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"hhxroad1",
		"south" : __DIR__"hhmatou",
        ]));

	set("hhjob", 1);
        set("outdoors", "xiao");
        setup();
}