
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"
void create()
{
        set("short", "С������");
        set("long", @LONG
·�Ϻܸɾ�����·����������������һ�������������һ������
���洫�˳�����һЩ�������Ͷ���ȥ��ƽ�����������һ�����죬��
��д�š����ſ�ջ���ĸ����֣��������߾͵����������ˡ�
LONG );
        set("valid_startroom",1);
        set("outdoors","����");
        set("class","Ѫ����");
        set("exits", ([
                "west"  : __DIR__"dexit",
                "east"  : __DIR__"sqare",
                "north"  : __DIR__"kezhan",
                "south"  : __DIR__"jiulou",
        ]));
//        set("no_clean_up", 0);
        setup();
}

