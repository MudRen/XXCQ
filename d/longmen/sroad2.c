
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"
void create()
{
        set("short", "����С·");
        set("long", @LONG
���������ѵ�С·�ϣ�������ϡ������ֺ���Ƭ����Ұ��һ�����峺
��СϪ��·ƽ�У�Ϫ���峺���ף�ˮ��������������ԵĿ�������ˮ����
������������һ��һ�����Ұɢ�������˵��������㡣
LONG );
        set("valid_startroom",1);
        set("outdoors","����");
        set("class","Ѫ����");
        set("exits", ([
                "west"  : __DIR__"sroad1",
                "southeast"  : __DIR__"sroad3",
        ]));
//        set("no_clean_up", 0);
        setup();
}


