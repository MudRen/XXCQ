// Room: yaotian7.c
// Created by Zeus 1999.4.9
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ҩ��");
        set ("long", @LONG
������Χ����һ������أ�����������ֵĲ�����ʳ������һЩ��
�ӷǳ���ֵ�ֲ�����������ֵ����¼�С�ֺ������춾ҩ��ԭ�ϡ���
��Ȼ���������˸ߵ��������·�ˡ�
LONG);
        set("area","����");
        set("valid_startroom", 1);
        set("outdoors", "wenjia");

        set("exits", ([
                "north" : __DIR__"yaotian"+(random(6)+1),
                "south" : __DIR__"houyuan",
                "east" : __DIR__"yaotian"+(random(6)+1),
                "west" : __DIR__"yaotian"+(random(6)+1),
        ]));

        setup();
        replace_program(ROOM);
}
int valid_leave(string dir)
{
        if (dir == "south" )
                write("�㳤��������һ�����������߳�ҩ���ˡ�\n");
}