//changan city

#include <ansi.h>
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"

void create ()
{
        set ("short", "������");
        set ("long", @LONG
վ�������ģ�����������һ�ۿ��Կ�����������С���ϱ�����С��
��Ҫ������ӣ��򶫲�Զ�ͳ����ˣ��������Ǽ���С�꣬������ͯ������
��ˣ����ʱ�Ļ�����������
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"xiaox1",
		"west" : __DIR__"hyroad4",
		"south" : __DIR__"xiaox2",
		"east" : __DIR__"hyroad6",
        ]));

        set("outdoors", "huayang");
        setup();
}
