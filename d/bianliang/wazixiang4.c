// wazixiang4.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������");
	set("long", @LONG
�����������ǵ�������,������һ��С��ͬ���ѡ�·����ʮ������Ӱ�ˡ�
��������ɴ�У��ڶ����ǹ����С�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"wazixiang3",
		"south" : __DIR__"wazixiang5",
		"west" : __DIR__"shahang",
		"east" : __DIR__"guozihang",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
