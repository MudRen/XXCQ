//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��ʯ·");
        set ("long", @LONG
����һ����ʯ�̾�С·��Ҳ���ɻ����س�ȥ���ٻ�̶���ɻ��š�佻�
Ϫ���仨���ıؾ�֮·��·�����˺��ǲ��١���ʯ·�������첻Զ����ʧ
�ˣ�ȡ����֮����һ����·�������֣�����������������ڲ�Զ��ǰ����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"treeroad4",
		"east" : __DIR__"hyroad2",
       ]));

        set("outdoors", "huayang");
        setup();
}