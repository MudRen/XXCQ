// hongbujie5.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�첼��");
	set("long", @LONG
������ȫ�������Ĵ�֣�������һ���ߴ��Ժ�ӣ������εĴ����Ϸ�д��
������ĥ�����ĸ����֣������Ǹ���լ��

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"hongbujie4",
		"south" : __DIR__"hongbujie6",
		"west" : __DIR__"minzhai3",
		"east" : __DIR__"ziqimofang",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
