
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
���������Ȼ���ʡ�һ����ʯ�̳ɵĴ��ʹ�����е㶼�е�ζ����
��������Զ�������ĳ��򣬻��������������ڸ��������������������
���ġ�Ѫ���ɡ���ʹ�����𲽷�չ��һ���˿ھۼ���С��
LONG );
        set("valid_startroom",1);
        set("outdoors","����");
        set("class","Ѫ����");
        set("exits", ([
                "west"  : __DIR__"sroad6",
                "east"  : __DIR__"qsroad2",
        ]));
//        set("no_clean_up", 0);
        setup();
}


