
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"
void create()
{
        set("short", "����С·");
        set("long", @LONG
���������ѵ�С·�ϣ�������ϡ������ֺ���Ƭ����Ұ��һ�����峺
��СϪ��·ƽ�У�Ϫ���峺���ף�ˮ��������������ԵĿ�������ˮ����
������������һ��һ�����Ұɢ�������˵��������㡣���ߺ���������һ
����ʯ�����
LONG );
        set("valid_startroom",1);
        set("outdoors","����");
        set("class","Ѫ����");
        set("exits", ([
                "northwest"  : __DIR__"sroad5",
                "east"       : __DIR__"qsroad1",
        ]));
//        set("no_clean_up", 0);
        setup();
}


