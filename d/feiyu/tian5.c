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
                "south" : __DIR__"shanlu1",
        ]));

        setup();
        replace_program(ROOM);
}
