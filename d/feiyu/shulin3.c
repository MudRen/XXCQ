// Room: shulin1.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create ()
{
        set ("short", "����");
        set ("long", @LONG
ï�ܵ���Ҷ�ڵ������⣬��ʹ����Χ�����Ե��е���ɭ��һ��紵��
����Χ����Ҷ��ɳɳ�������졣�㷢�����ܶ��Ǵ�������֪��һ���ǳ�·
��������ͻȻ�����������¸¡�����У����������Щ��
LONG);
        set("area","����");
        set("valid_startroom", 1);
        set("outdoors", "feiyu");

        set("exits", ([
                "east" : __DIR__"shulin"+(random(4)+1),
                "south" : __DIR__"shulin"+(random(4)+1),
                "west" : __DIR__"shulin"+(random(4)+1),
                "north" : __DIR__"shulin"+(random(4)+1),
                
        ]));
        setup();
}

