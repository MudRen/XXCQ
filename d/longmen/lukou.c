// made by lks

inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"

void create()
{
        set("short", "·��");
        set("long", @LONG
������ǻ���С��Ķ�·�ڣ���������ģ�û��ʲ�����ڸ����߶���
������һ�����ѵ�С·��������һ��С�����ϵ��˼Ҳ����࣬���Ƕ���
���ճ������������Ϣ���������
LONG );
        set("valid_startroom",1);
        set("exits", ([
                "east" : __DIR__"sroad1",
                "west" : "/d/huayang/hyroad6",
        ]));
        set("class","Ѫ����");
        set("outdoors", "����" );
        setup();
}
