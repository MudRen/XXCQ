// Room: cangshufang.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.4.10
// �޸ĳ�������
// 

inherit ROOM;

string* books = ({
        "handbook",
        "forcebook",
        "bladebook",
        "swordbook",
        "dodgebook",
        "laozi",
        "lunyu",
        "sanzijing",
});

void create ()
{
        set ("short", "���鷿");
        set ("long", @LONG
������һ��һ�ŵ���ܣ������ղص����й���ѧ�ʵĺ͹���
�书�ġ�������ѧ�á�
LONG);
        set("area","����");
        set("exits", ([
                "north" : __DIR__"xuetang",
        ]));

        set("objects", ([
                __DIR__"obj/"+books[random(sizeof(books))] : 1,
                __DIR__"obj/"+books[random(sizeof(books))] : 1,
                __DIR__"obj/"+books[random(sizeof(books))] : 1
        ]));

        setup();
        replace_program(ROOM);
}
