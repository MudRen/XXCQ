// Room: shanlu3.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
������һ��С��·��·�����潥������������ɽ��һֱͨ�������롣
������������ʯ�ٵ������Ǳ߾Ϳ��Ե�������
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("exits", ([
                "westup" : __DIR__"shanlu5",
                "east" : "/d/xiangyang/guandao4",
        ]));
        setup();
        replace_program(ROOM);
}