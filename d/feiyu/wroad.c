// Room: wroad.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "С·");
        set ("long", @LONG
����һ����ʯ�̳ɵ�С·�����Ի�����һ��Ƭ��֪���Ļ��ݡ����ú�
���ߵ�С·��һģһ���Ĵ����������߾͵��������Ķ�Ժ�ˡ�����Ҳ��һ
���յأ�������������䳡�ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"xiyuan",
		"east" : __DIR__"xiwuchang",
        "north" : __DIR__"jzroad1",
	   ]));

        set("outdoors", "feiyu");
        setup();
        replace_program(ROOM); 
}

