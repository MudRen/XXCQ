// Room: shanjing1.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ��С��");
        set ("long", @LONG
������һ������������ɽ��С��һֱ�����Ϸ������š�С�����߶���
��ֵ���ʯ����Χû��һ����Ӱ�������߾Ϳ��Իص����㳡��
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"westsquare",
                "northwest" : __DIR__"shanjing2",
        ]));

        setup();
        replace_program(ROOM);
}
