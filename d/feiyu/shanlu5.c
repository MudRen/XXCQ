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
������һ��С��·��������ɽ������·��һֱͨ��������ġ�������
�����䵶��������֧��֮һ�ķ����þ�˵��������Ǳߡ����˷�����Ӻ�
������������·��
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("exits", ([
                "westup" : __DIR__"shanlu4",
                "southdown" : __DIR__"shanlu6",
        ]));
        setup();
        replace_program(ROOM);
}