// Room: tian.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;


void create ()
{
        set ("short", "����");
        set ("long", @LONG
������Χ����һ������أ��ֵĶ�����ʳ�������Ƿ�������˽�
�������Ϊ��������ɽ�аɣ���һ����ΧɽʱҲ������Ϊ��ʳ�������
���ܡ���������ɽׯ���ǲ��򵥰����������ţ�ͻȻ�����Լ���·�ˣ�
LONG);
        set("area","����");
        set("valid_startroom", 1);
        set("outdoors", "feiyu");

        set("exits", ([
                "north" : __DIR__"tian"+(random(4)+1),
                "south" : __DIR__"tian"+(random(4)+1),
                "east" : __DIR__"tian"+(random(4)+1),
                "west" : __DIR__"tian"+(random(4)+1),
        ]));

        setup();
        replace_program(ROOM);
}
