// Room: dayuan.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.10
// �޸ĳ�������
// 

inherit ROOM;
void create ()
{
        set ("short", "��Ժ");
        set ("long", @LONG
������һ����Ժ����ɨ�÷ǳ��ɾ������ܷ���һЩ���ʣ�ǽ
����һ����ˮ�ס�ˮ�����ˮ���ֳ�һ����ɫ��ʮ�ֹ��졣����
���¼ҵ���������������߾��Ǻ�Ժ���������ƶ��ң�����
��ʵ���ң��������Ǿ��ǻ���ҡ�
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 2,
        ]));

        set("exits", ([
                "south" : __DIR__"huikeshi",
                "north" : __DIR__"houyuan",
                "east" : __DIR__"shiyanshi",
                "west" : __DIR__"zhidushi",
        ]));
        setup();
        replace_program(ROOM);
}
