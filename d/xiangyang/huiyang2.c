//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
���ڽ���Ǯׯ�����壬�������������Ҳ�൱��һ�����裬��Ȼÿ��
�ٲ�Ҳ��ģ�����ĳ���Ѳ�飬���ƺ�ֻ��Ϊ����������Ǯׯ��ѹ���ա���
�����ž���·����������������νֶ���������
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"huiyang1",
		"south" : __DIR__"qugongci",
	]));

        set("outdoors", "zigui");
        setup();
}