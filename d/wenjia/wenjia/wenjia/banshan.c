// Room: banshan.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
�����ǰ�ɽ��������ĵ��ƱȽ�ƽ̹���ۼ��˼����¼ҵĵ��ӣ�����
����������ʲô�������������߾���һ��ɽ·������Ҳ��һ��ɽ·��
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 4,
        ]));

        set("exits", ([
                "south" : __DIR__"shanlu3",
                "westup" : __DIR__"shanlu4",
        ]));
        setup();
        replace_program(ROOM);
}
