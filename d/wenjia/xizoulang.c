// Room: xizoulang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// Modified Long
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
���������ȣ����������һ����������������ڶ���β����
ˮ�ﳩ�Ρ���������ȥ�����ﴫ��ߺ���������������䳡������
���Ǹ�������ɱ���յ�ǰ����
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "east" : __DIR__"qianting",
                "west" : __DIR__"xilianwuchang",
        ]));
        setup();
        replace_program(ROOM);
}
