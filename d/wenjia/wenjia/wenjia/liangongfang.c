// Room: liangongfang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
���������ֺŵ����ǵ����������м���������������������Ա��м�
�����̿���������˯�������������ͨ������ҵģ����Ҫ��ϰ�������
�����յĻ��뵽������䳡��
LONG);
        set("area","����");
        set("valid_startroom", 1);
        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([
                "east" : __DIR__"huikeshi2",
                "south" : __DIR__"wuchang",
        ]));

        setup();
        replace_program(ROOM);
}
