//changan city

#include <ansi.h>
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"

void create ()
{
        set ("short", "�����򶫿�");
        set ("long", @LONG
�ӻ����򶫿����߳�ȥֻ��һ��������С·������Լ��߿���ʮ��
�����Ҳ�߲����ģ�����·ֻ��Ϊ������Ԥ���ģ��ݳ������ź����人
�ͺӱ�������
LONG);
        set("valid_startroom", 1);

        set("exits", 
        ([
                "west" : __DIR__"hycs",
                "east" : "/d/longmen/lukou",
        ]));

        set("outdoors", "huayang");
        setup();
}

