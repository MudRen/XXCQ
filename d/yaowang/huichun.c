// Room: ����ҩ��
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ش���" );
	set("long",
"���߽�������ŵ�Ũ�ص�ҩζ�����ϸ߸ߵĹ���һ���Ҷ�"HBRED HIY"���ش��á�\n"NOR
"����������������Ļش���ҩ���ˣ��ش�����ҩ���������������ҩ��\n"
"����ҩ�������Ƶ�ҩ�ġ�ǽ�Ϲ���һ������(paizi)��\n"
);
	set("area", "������");
	set("areb", "�ش���");
	set("item_desc", ([
		"paizi" : YEL"��ҩ�ֳ��۸���ҩ�ģ��������㹤��ơ�\n\n"
				"���������˵��뵽������\n"
				"��ҩ���뵽������\n"
				"�򹤵��뵽������\n"NOR,
	]));
	set("exits", ([
        "east" : "/d/bianliang/nandajie2",
		"west" : __DIR__"tingyuan",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
        "/d/bianliang/npc/shang" : 1,
	]));
	setup();
	replace_program(ROOM);
}
