#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����ɽ");
        set("long", @LONG
���Ǵ�˵�����صİ���ɽ��ԶԶ��ȥ��������ɳ�ѻ��γɵ�ɽ�����
һֻ���յļ�����һ��ɽ�����������ǰ��ɽ�ź�һ��С·ͨ��һ��ɽ��
�ϵ�ɽׯ�������ǡ�������ŷ�������լ��
LONG);
        set("exits", ([
            "east" : "/d/hj/gebi4",
           "westup" : __DIR__"shanmen", 
        ]));
        set("outdoors", "����ɽ");
        setup();
        replace_program(ROOM);
}