// Room: shandi.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ��");
        set ("long", @LONG
����������ɽ���ĵײ����Ĵ�����ï�ܵ�ɭ�֣�ֻ��һ��ɽ·��ɽ��
��˵���ﾭ�������˳�û����ҪС��һ�㡣�����Ǳ����Ķɿڣ��������
������ȥ�����֡�
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "west" : __DIR__"gangkou",
                "southup" : __DIR__"shanlu1",
        ]));
        setup();
        replace_program(ROOM);
}
