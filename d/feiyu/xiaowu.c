// Room: xiaowu.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����Ƿ�����������������������������һ���ţ�ֻ��������Ϯ��
����,ʹ��͸������������ǰ��һ����¯,ֻ�������������������ظɻ
����һ���������ڲ���Ѳ�ӣ�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "north" : __DIR__"zhailu",
        ]));

        set("objects", ([
                       __DIR__"npc/tiejiang" : 1,
                       __DIR__"obj/tielu" : 1,
        ]));

		setup();
}
