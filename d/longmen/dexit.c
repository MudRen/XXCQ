
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"
void create()
{
        set("short", "��·��");
        set("long", @LONG
�������������ߣ��͵�������С��������Ȼ�˲��Ǻܶ࣬����ȴ
ʲô���У����ǡ���ȸ��С�������ȫ�����������Ѫ��������������
�������������ɶ���������Χ��Ѫ���ɣ��ⷴ���̼������С��ķ�չ
ʲô�Ƶ꣬��ջ�����ֵĿ����ˡ�
LONG );
        set("valid_startroom",1);
        set("outdoors","����");
        set("class","Ѫ����");
        set("exits", ([
                "west"  : __DIR__"qsroad1",
                "east"  : __DIR__"xijie",
        ]));
//        set("no_clean_up", 0);
        setup();
}


