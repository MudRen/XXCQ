// Room: sahngu1.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ��");
        set ("long", @LONG
����ĵ��ƺ�Ȼ����ˣ�������ƺ�ů����һ�㣬��������ȥ��ֻ��
ɽ������Щֲ��еĻ��ſ�����ɽ��һֱ���������ȥ����ͷ��ȥ����
�ߵ�ɽ����Χ����һЩ������Щ������翵ĸо���
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 1,
        ]));

        set("exits", ([
                "northup" : __DIR__"shaozhan",
                "southdown" : __DIR__"shangu2",
        ]));
        setup();
        replace_program(ROOM);
}
