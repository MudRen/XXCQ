
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"
void create()
{
        set("short", "С���Ͻ�");
        set("long", @LONG
�ߵ����ͻȻһ����˻���Ӷ����һ�������ﴫ����ԭ��������
һ����վ�����淿�����һ����ͣ��������һ��������ֻһ���֣���
������������һ�ҵ��̡�
LONG );
        set("valid_startroom",1);
        set("outdoors","����");
        set("class","Ѫ����");
        set("exits", ([
              "east" : __DIR__"lmyizhan",
                "south"  : __DIR__"sexit",
                "north"  : __DIR__"sqare",
        ]));
//        set("no_clean_up", 0);
        setup();
}

