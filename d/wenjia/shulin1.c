// Room: shulin1.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.10
// �޸ĳ�������
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
������ï�ܵ����֣�������֦��ï����ס�����⣬������Щ��ɭ
�ֲ�����ʱ����ֻҰ���ܹ�����ߡ������߻���һƬ���֣���������
���ǳ����͵�ɽ����
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("objects", ([
                __DIR__"npc/yetu" : 1,
        ]));

        set("exits", ([
                "southup" : __DIR__"shanjing2",
                "west" : __DIR__"shulin2",
        ]));
        setup();
        replace_program(ROOM);
}
