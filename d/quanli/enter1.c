
inherit ROOM;
void create()
{
        set("short","��������");
        set("long",@LONG
 ���Ѿ�������Ȩ��������ĵش���
LONG );
        set("valid_startroom",1);
        set("class","Ȩ����");
        set("exits",([
                "west" : __DIR__"zoulang2",
                 "enter" : __DIR__"biandian",
        ]));
        set("objects",([
        ]));
//        set("no_clean_up"�� 0);
        set("objects",([
          __DIR__"npc/futianyi" : 1,
    ]));
        setup();
        replace_program(ROOM);
}

