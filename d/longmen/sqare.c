
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"
void create()
{
        set("short", "С������");
        set("long", @LONG
����������С��Ĺ㳡��Ҳ�Ǿ����Ǽ��ϵĵط����������С��
���ڽ��赱�У����Ծ����и�ʾ�����������񳣵������˽�С��Ľ���
���ȣ��������һ�����ӣ�����������Ǯ����ʿΪС����ļ��ġ�
LONG );
        set("valid_startroom",1);
        set("outdoors","����");
        set("objects",([
                __DIR__"obj/box" : 1,
      ]));
        set("class","Ѫ����");
        set("exits", ([
                "west"  : __DIR__"xijie",
                "south"  : __DIR__"nanjie",
        ]));
//        set("no_clean_up", 0);
        setup();
}

