// Room: cangshufang.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.7.22
// 
// 

inherit ROOM;

string* books = ({
        "forcebook",
        "dodgebook",
        "lphandbook",
});

void create ()
{
        set ("short", "���鷿");
        set ("long", @LONG
������һ��һ�ŵ���ܣ������ղص����й���ѧ�ʵĺ͹����书�ġ�
������ѧ�á�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "north" : __DIR__"xuetang",
        ]));

        set("objects", ([
                __DIR__"obj/"+books[random(sizeof(books))] : 1,
        ]));

        setup();
        replace_program(ROOM);
}
