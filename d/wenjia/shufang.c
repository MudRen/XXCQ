// Room: shufang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.17
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�鷿");
        set ("long", @LONG
�������ֺŵ�������˿����鷿����˿�������ﴦ�����ֺ�
�Ĵ��£������ɳ�ɱ�˵������Ȼ��Ҳ����������������ȥ����
����Ҫ��������ſ��������񡣾���������ſ��Իص�����ҡ�
LONG);
        set("area","����");
        set("objects", ([
                "/kungfu/class/wenjia/wensijuan" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"huikeshi2",
        ]));
        setup();
        replace_program(ROOM);
}
