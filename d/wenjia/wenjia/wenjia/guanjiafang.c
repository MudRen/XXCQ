// Room: guanjiafang.c �ܼҷ�
// Created by Zeus 1999.5.28
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�ܼҷ�");
        set ("long", @LONG
���������һ���������Ա�����һ�����ˡ����Ӻ�����������ŵ�
���Ǿ��ڣ������϶����˾��ڣ���Ȼ�ٲ������ķ��ı������˵��ֲ�ͣ��
д�Ŷ�����
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "north" : __DIR__"donglianwuchang",
        ]));
        set("objects", ([
                 __DIR__"npc/wengu": 1,
        ]));

        setup();
        replace_program(ROOM);
}
