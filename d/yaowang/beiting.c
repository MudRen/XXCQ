// Room: ����ҩ��
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǻش��õ��ʷ����ʷ������������űߵ�һ�����Ӻ��档����
�ش���������¡��ҩ���ȵĵ����Ѿ�æ�����������Դ�����Ӷ�㹤��ƣ�
��Ǯ���͵ġ������ͷȱǮ������ѧϰҽҩѧ�������������򹤡�
LONG );
	set("area", "ҩ����");
	set("areb", "����");
	set("no_fight", 1);
	set("exits", ([
		"west" : __DIR__"xiuxi",
		"south" : __DIR__"tingyuan",
	]));
	set("objects", ([
		__DIR__"npc/zhangfang" : 1,
	]));
        create_door("west", "ľ��", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
