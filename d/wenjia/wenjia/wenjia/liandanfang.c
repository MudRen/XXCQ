// Room: liandanfang.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
������С�ֺŵ�����������ʵ���������ҩ����ҩƷ��������������
��ʵ��Ʒ������ֻ��һ�����ڣ������߾���ʵ���ҡ�
LONG);
        set("area","����");
        set("valid_startroom", 1);
 
        set("exits", ([
                "west" : __DIR__"shiyanshi",
        ]));
 
        setup();
        replace_program(ROOM);
}
