//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��·");
        set ("long", @LONG
����һ�����˿����·�������ǲ��߳��ģ�ֻ��佻����Ӻ�ȥ佻�Ϫ
�϶Ÿ����õ��˲Ż�������·��·����һЩϡϡ�����Ļ��ݣ�·��������
ͨ��佻�Ϫ�������������һƬ���֣���˵������ǿ�˴�ٵġ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"northwest" : __DIR__"feihua",
		"south" : __DIR__"treeroad1",
       ]));

        set("outdoors", "huayang");
        setup();
}