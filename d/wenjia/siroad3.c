// Room: siroad3.c
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
һ��ɽ·�����Ϸ��߻���ɽ·��
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "southeast" : __DIR__"siroad2",
                "westup" : __DIR__"siroad4",
        ]));
        setup();
        replace_program(ROOM);
}
