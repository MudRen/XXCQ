
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"
void create()
{
        set("short", "��·��");
        set("long", @LONG
�����������ߣ���ͨ������ʯ�ߵ�ɽ·����˵��Ѫ���ɡ��ʹ�����
���������ִ��ң���������Ҫ����Ѫ���ɡ�����û����ˢ�ӾͲ�Ҫ
��ɽ����������ɱ��֮���������������С��
LONG );
        set("valid_startroom",1);
        set("outdoors","����");
        set("class","Ѫ����");
        set("exits", ([
                "south"  : __DIR__"xiaolu1",
                "north"  : __DIR__"nanjie",
        ]));
//        set("no_clean_up", 0);
        setup();
}

