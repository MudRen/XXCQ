// Room: siroad5.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.17
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
�����ǵ������ֺš���ɽ·��·���ֵĶ���һЩ���컨�ݡ�
˵������Щ�������ж��ģ����ǿ�Щ�뿪����ɡ�������ȥ��
ɽ·������������Ҳ��ɽ·��
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "northeast" : __DIR__"siroad4",
                "southup" : __DIR__"siroad6",
        ]));
        setup();
        replace_program(ROOM);
}

