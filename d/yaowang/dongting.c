// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ҩ���ȵĶ����������ǳ������ṩ���е��ӵ���ʳ��������һ����Ϣ�ң�
����һ��ҩ�����������һЩ�����ĳ���ҩ��
LONG );
	set("area", "ҩ����");
	set("areb", "����");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"chufang",
		"west" : __DIR__"dating",
		"east" : __DIR__"xiuxi2",
		"northeast" : __DIR__"yaofang",
	]));

        create_door("east", "ľ��", "west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
