// Room: bingqifang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
��������ʲô�������У�����������������ţ�������ר������İɡ�
�¼ҵ���û�й̶��ı����������¼ҵ��ӿ����������ҵ��ʺ��Լ��ı�����
���ߵ���ͨ��ҩ���������߾��Ƕ����䳡��
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"yaofang",
                "south" : __DIR__"donglianwuchang",
        ]));

        set("objects", ([
                "/clone/weapon/changjian" : 1,
                "/clone/weapon/dandao" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
