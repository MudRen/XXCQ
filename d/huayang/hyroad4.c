//changan city

#include <ansi.h>
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"

void create ()
{
        set ("short", "����������");
        set ("long", @LONG
��·�Ͽ�ȥ��һ��ľ����Ʈ��һ�����ľƻϣ�һ����֪������һ��
С�ƹݡ��������˽����ƹݣ��еĻ�����һ���մ�ľơ�·�ı�������һ
��ɡ�꣬���������ⲻ�Ǻܺá�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"sandian",
		"west" : __DIR__"hyroad3",
		"south" : __DIR__"jiupu",
		"east" : __DIR__"hycs",
        ]));

        set("outdoors", "huayang");
        setup();
}
