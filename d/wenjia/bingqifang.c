// Room: bingqifang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.10
// �޸ĳ�������
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
��������ʲô�������У�����������������ţ�������ר��
����İɡ��¼ҵ���û�й̶��ı����������¼ҵ��ӿ���������
�ҵ��ʺ��Լ��ı��������ߵ���ͨ��ҩ���������߾��Ƕ����䳡��
LONG);
        set("area","����");
        set("exits", ([
                "east" : __DIR__"yaofang",
                "south" : __DIR__"donglianwuchang",
        ]));

        set("objects", ([
                "/clone/weapon/gangjian" : 1,
                "/clone/weapon/gangdao" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
