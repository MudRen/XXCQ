// Room: huikeshi2.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�����");
        set ("long", @LONG
���������ֺŵĻ���ҡ�������д�����ֺ��������֣�̫ʦ��������
���������ӡ���������ǵ��������ģ���������ǵ����ֺ�������˿���
�鷿��
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wenlazi" : 1,
        ]));

        set("exits", ([
                "northdown" : __DIR__"siroad6",
                "east" : __DIR__"shufang",
                "west" : __DIR__"liangongfang",
        ]));

        setup();
        replace_program(ROOM);
}
