// hongbujie3.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�첼��");
	set("long", @LONG
�����Ǻ첼�ֵľ�ͷ,�򶫱�ɵ��̻���ȥ��ÿ�춼�в����˽�����

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"bh_lukou2",
		"south" : __DIR__"hongbujie4",
		"east" : __DIR__"yanhuaxiang",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
