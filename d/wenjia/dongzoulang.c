// Room: dongzoulang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
���Ƕ����ȣ������ұ���һ����������������ڶ���β����
ˮ�ﳩ�Ρ���������ȥ�����ﴫ��ߺ���������Ƕ����䳡������
���Ǹ�������ɱ���յ�ǰ����
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "west" : __DIR__"qianting",
                "east" : __DIR__"donglianwuchang",
        ]));
        setup();
        replace_program(ROOM);
}
