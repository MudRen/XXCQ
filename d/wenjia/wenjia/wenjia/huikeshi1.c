// Room: huikeshi1.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�����");
        set ("long", @LONG
������ֺš��Ļ���ҡ��������ֺŵĻ����һ�������̫ʦ����
�����ǻ��ֺŵĵڶ�����--��Լ�졣������Ӵ�������Ŀ��ˡ������Ƕ�
�ڣ��������о��ң������Ϸ������������ң����Ϸ���������ҩ����
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wenyuehong" : 1,
        ]));

        set("exits", ([
                "east" : __DIR__"dongkou",
                "west" : __DIR__"yanjiushi",
                "northwest" : __DIR__"zhiliaoshi",
                "southwest" : __DIR__"peiyaofang",
        ]));

        setup();
        replace_program(ROOM);
}
