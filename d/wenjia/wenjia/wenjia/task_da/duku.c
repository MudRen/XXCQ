// Room: duku.c
// Created by Zeus 1999.5.12
// Modified by Zeus 1999.5.12
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
�������¼�С�Ӻŷǳ���Ҫ�ĵط�֮һ�������ղ����¼ҵĴ�
���ֶ�ҩ��������𽭺��Ķ�ҩ���ղ����������Ҳ����Σ�յ�
�ط�֮һ����Ϊһ��С�ľͻ��ж���
LONG);
        set("area","����");

        set("exits", ([
                "south" : __DIR__"cangdushi",
                "down" : __DIR__"cangdudong",
        ]));
        replace_program(ROOM);
        setup();
}