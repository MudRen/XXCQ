
inherit ROOM;
void create()
{
        set("short","��������");
        set("long",@LONG
 ���Ѿ������˶��������ĵش���
LONG );
        set("valid_startroom",1);
        set("class","Ȩ����");
        set("exits",([
                "east" : __DIR__"zoulang1",
                 "enter" : __DIR__"biandian1",
        ]));
        set("objects",([
        ]));
//        set("no_clean_up"�� 0);
        set("objects",([
          __DIR__"npc/dujue" : 1,
    ]));
        setup();
        replace_program(ROOM);
}

