// Room: shanjing2.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.7.12
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ��С��");
        set ("long", @LONG
����С�����߶��Ƕ��͵�ɽ�ڣ�С���ǳ���б��һֱ���������죬ͨ
��һƬ���֡�����һ��С�ľͻ�ˤ�ӡ����Ϸ��߾ͻ�ص�����ƽ̹��С
����
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "southeast" : __DIR__"shanjing1",
                "northdown" : __DIR__"shulin1",
        ]));

        setup();
        replace_program(ROOM);
}