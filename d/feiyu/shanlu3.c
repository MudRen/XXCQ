// Room: shanlu3.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
������Ȼ����ʵ����ʯ·���������ڳ������ˮ��������ʯ·������
���е㻬�������Ѿ��ǰ�ɽ���ˣ�������Щ���⣬��������������ȥ��
�������ġ���ֹ�ء��ˡ���̧ͷ���Ͽ�ȥ������һ��ɽ�ƹ����ɽ�塣
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("exits", ([
                "northup" : __DIR__"renzhiguan",
                "southup" : __DIR__"luoshenling",
        ]));
        setup();
        replace_program(ROOM);
}
