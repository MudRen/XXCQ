// Room: yishiting.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
�������һȦ���ӣ�����Ȼ�����������������µ������İɶ��Ϸ���
���Ϸ����������Ǻ���Ȼ�Ǵ�ǰ�������������ƫ����
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wenliangyu" : 1,
        ]));

        set("exits", ([
                "southwest" : __DIR__"xipianting",
                "southeast" : __DIR__"dongpianting",
        ]));

        setup();
        replace_program(ROOM);
}
