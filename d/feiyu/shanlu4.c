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
������һ��С��·��������ɽ������һ��·�����������ˣ�û�й�
������֮ǰ�㿴�������Ǳߵ��κζ����������׵����䵶��������֧��֮
һ�ķ����þ�˵��������Ǳߡ�
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("exits", ([
                "northup" : __DIR__"luoshenling",
                "eastdown" : __DIR__"shanlu5",
        ]));
        setup();
        replace_program(ROOM);
}