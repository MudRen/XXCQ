//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��·");
        set ("long", @LONG
����һ�������˲ȳ�������·��·�ϵ����˺��ǲ��٣���������ٻ�
̶�����ˣ�Ҳ��һЩ��佻����Ӻ���佻���ʦ���ˡ�·�����Ի��ݴ�����
·���������ǰٻ�̶��������һƬ���֣��������־͵��˻���С���ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"northwest" : __DIR__"baihuatan",
		"east" : __DIR__"treeroad3",
       ]));

        set("outdoors", "huayang");
        setup();
}