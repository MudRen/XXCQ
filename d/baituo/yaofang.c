#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ҩ��");
        set("long", @LONG
ŷ�����Ϊ�������������ڶ�ҩ��ľ�ͨ���������޹����������ߡ�
��ҩ������ǧ��ҽҩ����ҩȫ�ð״�ƿ��װ�ţ����ϱ�ǩ�����ű���ط�
�����ܵ�ҩ���ϣ�����һĿ��Ȼ��ԽҲ������һ˿�־�֮�ġ�
LONG);
        set("exits", ([
              "east" : __DIR__"tangwu",
        ]));
        set("objects", ([
//                    "/d/xingxiu/obj/yao" : 1,
//                    "/d/xingxiu/obj/yao1" : 1,
                    __DIR__"obj/grass" : 1,
        ]));
        setup(); 
      replace_program(ROOM);
}
