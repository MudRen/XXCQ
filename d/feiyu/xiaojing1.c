// Room: xiaojing1.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 

inherit ROOM;

void create ()
{
        set ("short", "С��");
        set ("long", @LONG
����һ����ʯ�̳ɵ�С�������ܶ���������С��Ľ���������������
���߾͵��������Ķ����䳡�ˣ���������һ��Ƭ���֣���Լ���ü�������
��Щ�ƶ���Ӱ�ӡ�
LONG);
	set("valid_startroom", 1);
       set("outdoors", "feiyu");
       set("exits", 
        ([
		"north" : __DIR__"dongwuchang",
		"south" : __DIR__"shulin",
       ]));

                setup();
        replace_program(ROOM); 
}

