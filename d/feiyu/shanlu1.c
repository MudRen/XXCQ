// Room: shanlu1.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
��ʯ·�������Ѿ��������ˣ����±��������·��������������ȥ
���Ƿ���ɽׯ�����ˡ�������Կ���һЩ�����������������ţ����ǵ�
���鶼�ܽ��ţ���������������������˶��˰ɡ��������˾������򱱿�
ȥ����һ��Ƭ�˵ء�
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 2,
        ]));

        set("exits", ([
                "southeast" : __DIR__"yixiantian",
                "eastup" : __DIR__"lysquare",
                "north" :__DIR__"tian5",     
        ]));
        setup();
        replace_program(ROOM);
}
