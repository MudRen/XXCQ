// hongbujie6.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�첼��");
	set("long", @LONG
������ȫ�������Ĳ�ƥһ���֣�������һ�����ӵ�Ժ�ӣ������εĴ����Ϸ�д��
��������ׯ���ĸ����֣������Ǹ���լ��

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"hongbujie5",
		"south" : __DIR__"hongbujie7",
		"west" : __DIR__"minzhai4",
		"east" : __DIR__"shuzhuang",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
