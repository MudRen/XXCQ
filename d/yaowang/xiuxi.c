// Room: ����ҩ��
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
�����ǻش��õ���Ϣ�ң���������ҩ�����ú�ҽʦ��Ϣ�ĵط���
�����ڷ������ŵĴ��̣���������ˣ�����������˯һ�����
LONG );
	set("area", "������");
	set("areb", "�ش���");
	set("no_fight", 1);
	set("sleep_room", 1);
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"beiting",
	]));

        create_door("east", "ľ��", "west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
