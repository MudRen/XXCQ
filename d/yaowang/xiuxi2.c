// Room: ����ҩ��
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
������ҩ����ר�Ź�������Ϣ�ĵط����������һ���ŵĴ󴲡��ݽ�
���м�ֻˮͰ������װ������ˮ�����������������������װЩˮ��
LONG );
	set("area", "ҩ����");
	set("areb", "��Ϣ��");
	set("no_fight", 1);
	set("sleep_room", 1);
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"dongting",
	]));

        create_door("west", "ľ��", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
