// Room: shufang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�鷿");
        set ("long", @LONG
�������ֺŵ�������˿����鷿����˿�������ﴦ�����ֺŵĴ��£�
�����ɳ�ɱ�˵������Ȼ��Ҳ����������������ȥ��������Ҫ������
��ſ��������񡣾���������ſ��Իص�����ҡ�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wensijuan" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"huikeshi2",
        ]));

        setup();
        replace_program(ROOM);
}
