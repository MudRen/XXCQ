// Room: shaozhan.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "��վ");
        set ("long", @LONG
����ɽ����΢ƽ����Сƽ̨�ϣ���һ�������ľ�ݣ���������Ʈ�����
�Ƿ������ġ������족��������̾������ɽ��ʱ��һ�ӷ���������˹�����
����������Ѳ�߲������ƺ�������ʲô���¡��������򶫱����ǵ������ˣ�
��������һ��ɽ�ȡ�
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 2,
        ]));

        set("exits", ([
                "northeast" : __DIR__"diliufeng",
                "southdown" : __DIR__"shangu1",
        ]));
        setup();
        replace_program(ROOM);
}
