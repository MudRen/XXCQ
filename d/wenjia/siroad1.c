// Room: siroad1.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.16
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
�����ǵ������ֺš���ɽ·��·���ֵĶ���һЩ���컨�ݡ�
˵������Щ�������ж��ģ����ǿ�Щ�뿪����ɡ�����ȥ��
��ɽ·�������Ϸ��߾����ܲ��Ķ��㳡��
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "southwest" : __DIR__"eastsquare",
                "northup" : __DIR__"siroad2",
        ]));
        setup();
        replace_program(ROOM);
}
