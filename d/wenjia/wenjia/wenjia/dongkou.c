// Room: dongkou.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
������һ����ɽ����������վ�ĵط���һ����ƽ̨����˵������ھ�
�ǽ�����ֺŵıؾ�֮·�����������������¼ҵ��ӡ�
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"huoroad8",
                "west" : __DIR__"huikeshi1",
        ]));
        set("objects", ([
               __DIR__"npc/wenjiadizi": 2,
        ]));

        setup();
        replace_program(ROOM);
}
