//brestroom.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�е�����Ϣ��");
	set("long", @LONG
����һ���谵�ķ��䣬���ڱ����ĺڲ���ס��ֻ��һ˿���ߴ�
�ŷ���͸������Լ�Ŀ������������ڿ�ǽ�Ĵ�����Ϣ��
LONG);	
	set("valid_startroom",1);
	set("no_steal", "1");
	set("no_fight", "1");
	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"nzlangw3",
	]));
	setup();
	replace_program(ROOM);
}