//chaifang.c		�Ĵ����š���

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
�����Ǻ�Ժ�Ĳ񷿣����ж��������õĲ�����ݶ���ľ�ĵ���
ζ����ɽҲ�ƵĲ����һ��С��ͨ���ɽ����˵�����û�Ų��ǻ���
�������Ы�����򲻹��߿ɲ�Ҫ����ѽ��
LONG);
	set("exits", ([
			"west" : __DIR__"chufang",
			"south" : __DIR__"nzlange1",
			"north" : __DIR__"exiaolu1",
	]));
//	create_door("northeast","ľ��","southwest",DOOR_CLOSED);
	set("objects", ([__DIR__"npc/tangbukun" : 1,]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}