// Room: shanlu2.c
//Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
������Ȼ����ʵ����ʯ·���������ڳ������ˮ��������ʯ·������
���е㻬�������Ѿ��ǰ�ɽ���ˣ���е�Խ��Խ�䡣��������������ȥ
���������ġ���ֹ�ء��ˡ�������Կ���һЩ������Ӵ���������������
��֮��������������ֻ������Щͷ��,�������ǿ����˼���С����
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 2,
        ]));

        set("exits", ([
                "westdown" : __DIR__"shanjianxiaowu",
                "eastup" : __DIR__"renzhiguan",
        ]));
        setup();
        replace_program(ROOM);
}
