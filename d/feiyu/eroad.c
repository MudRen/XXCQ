// Room: eroad.c
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
����һ����ʯ�̳ɵ�С·�����Ի�����һ��Ƭ��֪���Ļ��ݡ�������
�����߾͵��������Ķ�Ժ�ˡ�����һ������һ���յأ�������Щ��Ӱ
�ڻζ���������Ƕ����䳡�ˣ��㷢�ָ������˷·�Ҳ����Ծ������
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"dongwuchang",
		"east" : __DIR__"dongyuan",
       ]));

        set("outdoors", "feiyu");
        setup();
        replace_program(ROOM); 
}

